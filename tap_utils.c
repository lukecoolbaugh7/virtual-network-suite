#include "tap_utils.h"
#include <net/if_utun.h>
#include <sys/kern_control.h>
#include <sys/kern_event.h>
#include <sys/socket.h>
#include <sys/sys_domain.h>

int tap_alloc(char *dev)
{
    struct ifreq ifr;
    int fd, err;
    struct sockaddr_ctl sc;
    struct ctl_info ctlInfo;

    if ((fd = socket(PF_SYSTEM, SOCK_DGRAM, SYSPROTO_CONTROL)) < 0)
    {
        return fd;
    }

    memset(&ctlInfo, 0, sizeof(ctlInfo));
    strncpy(ctlInfo.ctl_name, "com.apple.net.utun_control", sizeof(ctlInfo.ctl_name));
    if (ioctl(fd, CTLIOCGINFO, &ctlInfo))
    {
        close(fd);
        return -1;
    }

    sc.sc_id = ctlInfo.ctl_id;
    sc.sc_len = sizeof(sc);
    sc.sc_family = AF_SYSTEM;
    sc.ss_sysaddr = AF_SYS_CONTROL;
    sc.sc_unit = 0;

    if (connect(fd, (struct sockaddr *)&sc, sizeof(sc)) < 0)
    {
        close(fd);
        return -1;
    }

    if (*dev)
    {
        // attempt to get the interface name
        socklen_t nameLen = IFNAMSIZ;
        if (getsockopt(fd, SYSPROTO_CONTROL, UTUN_OPT_IFNAME, dev, &nameLen))
        {
            close(fd);
            return -1;
        }
    }

    return fd;
}
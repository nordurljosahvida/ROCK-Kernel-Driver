#ifndef AMD_KCL_PERF_EVENT_H
#define AMD_KCL_PERF_EVENT_H

#include <linux/perf_event.h>
#include <linux/version.h>

extern void (*_kcl_perf_event_update_userpage)(struct perf_event *event);

static inline void kcl_perf_event_update_userpage(struct perf_event *event)
{
#if defined(BUILD_AS_DKMS) && LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
	return _kcl_perf_event_update_userpage(event);
#else
	return perf_event_update_userpage(event);
#endif
}

#endif

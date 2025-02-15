#include <kcl/kcl_amdgpu.h>

#if DRM_VERSION_CODE >= DRM_VERSION(4, 4, 0)
u32 kcl_amdgpu_get_vblank_counter_kms(struct drm_device *dev, unsigned int crtc)
{
	return amdgpu_get_vblank_counter_kms(dev, crtc);
}

int kcl_amdgpu_enable_vblank_kms(struct drm_device *dev, unsigned int crtc)
{
	return amdgpu_enable_vblank_kms(dev, crtc);
}

void kcl_amdgpu_disable_vblank_kms(struct drm_device *dev, unsigned int crtc)
{
	amdgpu_disable_vblank_kms(dev, crtc);
}

#if DRM_VERSION_CODE < DRM_VERSION(4, 13, 0) && \
	!defined(OS_NAME_SUSE_15) && \
	!defined(OS_NAME_SUSE_15_1)
int kcl_amdgpu_get_vblank_timestamp_kms(struct drm_device *dev, unsigned int crtc,
					int *max_error,
					struct timeval *vblank_time,
					unsigned flags)
{
	return amdgpu_get_vblank_timestamp_kms(dev, crtc, max_error, vblank_time, flags);
}
#endif

int kcl_amdgpu_display_get_crtc_scanoutpos(struct drm_device *dev, unsigned int crtc,
				   unsigned int flags, int *vpos, int *hpos,
				   ktime_t *stime, ktime_t *etime,
				   const struct drm_display_mode *mode)
{
	return amdgpu_display_get_crtc_scanoutpos(dev, crtc, flags, vpos, hpos, stime, etime, mode);
}
#else
u32 kcl_amdgpu_get_vblank_counter_kms(struct drm_device *dev, int crtc)
{
	return amdgpu_get_vblank_counter_kms(dev, crtc);
}

int kcl_amdgpu_enable_vblank_kms(struct drm_device *dev, int crtc)
{
	return amdgpu_enable_vblank_kms(dev, crtc);
}

void kcl_amdgpu_disable_vblank_kms(struct drm_device *dev, int crtc)
{
	amdgpu_disable_vblank_kms(dev, crtc);
}

int kcl_amdgpu_get_vblank_timestamp_kms(struct drm_device *dev, int crtc,
					int *max_error,
					struct timeval *vblank_time,
					unsigned flags)
{
	return amdgpu_get_vblank_timestamp_kms(dev, crtc, max_error, vblank_time, flags);
}

int kcl_amdgpu_display_get_crtc_scanoutpos(struct drm_device *dev, int crtc, unsigned int flags,
				   int *vpos, int *hpos, ktime_t *stime, ktime_t *etime)
{
	return amdgpu_display_get_crtc_scanoutpos(dev, crtc, flags, vpos, hpos, stime, etime, NULL);
}
#endif

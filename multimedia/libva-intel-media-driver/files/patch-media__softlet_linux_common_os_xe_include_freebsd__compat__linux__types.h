--- media_softlet/linux/common/os/xe/include/freebsd_compat_linux_types.h	2025-08-24 20:36:24.341220000 -0700
+++ media_softlet/linux/common/os/xe/include/freebsd_compat_linux_types.h	2025-08-24 20:36:46.040515000 -0700
@@ -0,0 +1,13 @@
+#ifndef _FREEBSD_COMPAT_LINUX_TYPES_H
+#define _FREEBSD_COMPAT_LINUX_TYPES_H
+
+#include <sys/types.h>
+#include <stdint.h>
+
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
+typedef int32_t __s32;
+
+#endif

--- media_softlet/linux/common/os/osservice/mos_utilities_specific.h.orig	2026-03-19 03:15:05.000000000 -0700
+++ media_softlet/linux/common/os/osservice/mos_utilities_specific.h	2026-05-17 00:31:02.186017000 -0700
@@ -27,7 +27,6 @@
 #define __MOS_UTILITIES_SPECIFIC_H__
 
 #include <map>
-#include <malloc.h>
 #include <string>
 #include "mos_defs.h"
 #include "media_class_trace.h"
@@ -36,7 +35,7 @@
 
 #define NOT_FOUND            -1
 
-#define _aligned_malloc(size, alignment)  memalign(alignment, size)
+#define _aligned_malloc(size, alignment)  aligned_alloc(alignment, size)
 #define _aligned_free(ptr)                free(ptr)
 
 typedef void (*MOS_UserFeatureCallback)( void*, bool);

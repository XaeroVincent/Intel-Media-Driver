--- media_softlet/linux/common/os/xe/include/dma-buf.h	2025-06-28 08:29:13.000000000 -0700
+++ media_softlet/linux/common/os/xe/include/dma-buf.h	2025-08-24 19:18:28.429878000 -0700
@@ -20,7 +20,11 @@
 #ifndef _DMA_BUF_UAPI_H_
 #define _DMA_BUF_UAPI_H_
 
-#include <linux/types.h>
+#if defined(__FreeBSD__)
+    #include "freebsd_compat_linux_types.h"
+#else
+    #include <linux/types.h>
+#endif
 
 /**
  * struct dma_buf_sync - Synchronize with CPU access.

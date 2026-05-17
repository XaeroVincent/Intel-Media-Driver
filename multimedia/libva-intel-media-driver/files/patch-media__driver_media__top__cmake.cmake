--- media_driver/media_top_cmake.cmake.orig	2026-05-17 12:03:33.698638000 -0700
+++ media_driver/media_top_cmake.cmake	2026-05-17 14:20:23.575560000 -0700
@@ -32,7 +32,11 @@ include(${MEDIA_DRIVER_CMAKE}/media_feature_flags.cmak
 option (MEDIA_RUN_TEST_SUITE "run google test module after install" ON) 
 include(${MEDIA_DRIVER_CMAKE}/media_gen_flags.cmake)
 include(${MEDIA_DRIVER_CMAKE}/media_feature_flags.cmake)
+include(CheckIncludeFileCXX)
+include(CheckLibraryExists)
 
+check_include_file_cxx("execinfo.h" HAVE_EXECINFO_H)
+check_library_exists(execinfo backtrace "" HAVE_LIBEXECINFO)
 
 if(NOT DEFINED SKIP_GMM_CHECK)
     # checking dependencies
@@ -588,7 +592,14 @@ add_library(${LIB_NAME} SHARED
     $<TARGET_OBJECTS:${LIB_NAME}_SOFTLET_CODEC>
     $<TARGET_OBJECTS:${LIB_NAME}_SOFTLET_COMMON>)
 
+if(HAVE_EXECINFO_H)
+    target_compile_definitions(${LIB_NAME} PRIVATE HAVE_EXECINFO_H)
+endif()
 
+if(HAVE_LIBEXECINFO)
+    target_link_libraries (${LIB_NAME} execinfo)
+endif()
+
 add_library(${LIB_NAME_STATIC} STATIC
     $<TARGET_OBJECTS:${LIB_NAME}_mos>
     $<TARGET_OBJECTS:${LIB_NAME}_COMMON>

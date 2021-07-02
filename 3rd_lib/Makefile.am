# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    02/07 2021 13:40
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        02/07 2021      create the file
# 
#     last modified: 02/07 2021 13:40
# ===============================================================

# ------------------
# defining variables
# ------------------
_lib_3rd_dst_path   = $(prefix)/3rd_lib
_lib_3rd_src_path   = $(top_srcdir)/3rd_lib

# ------------------
# make install files
# ------------------
install-exec-hook:
	${MKDIR_P} $(_lib_3rd_dst_path);
	for i in `ls $(_lib_3rd_src_path)`; do \
		if [ -d $(_lib_3rd_src_path)/$$i ]; then \
			echo $$i; \
			cp -ar $(_lib_3rd_src_path)/$$i ${_lib_3rd_dst_path}; \
		fi \
	done

uninstall-hook:
	rm -rf ${_lib_3rd_dst_path}/*

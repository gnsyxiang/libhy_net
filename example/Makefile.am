# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    05/03 2021 10:38
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        05/03 2021      create the file
# 
#     last modified: 05/03 2021 10:38
# ===============================================================

# ------------------
# defining variables
# ------------------
_include_com    =
_sources_com    =
_cppflags_com   =
_cflags_com     =
_cxxflags_com   =
_ldflags_com    =
_ldadd_com      =
bin_PROGRAMS    =

# ---------------------
# add necessary content
# ---------------------
_include_com    += -I$(top_srcdir)/include

_sources_com    +=

_cppflags_com   += \
                   $(CPPFLAGS_COM) \
                   $(_include_com)


_cflags_com     += $(CFLAGS_COM)

_cxxflags_com   += $(CXXFLAGS_COM)

_ldflags_com    += $(BIN_LDFLAGS_COM)

_ldadd_com      += $(top_builddir)/src/lib@project_name@.la

if COMPILE_LIBEVENT_PTHREAD
_cppflags_com   += $(EVENT_PTHREAD_INCS)
_ldadd_com      += $(EVENT_PTHREAD_LIBS)
endif

if COMPILE_LIBEVENT
_cppflags_com   += $(EVENT_INCS)
_ldadd_com      += $(EVENT_LIBS)
endif

bin_PROGRAMS    += hy_net
hy_net_SOURCES  = $(_sources_com) main.c
hy_net_CPPFLAGS = $(_cppflags_com)
hy_net_CFLAGS   = $(_cflags_com)
hy_net_CXXFLAGS = $(_cxxflags_com)
hy_net_LDFLAGS  = $(_ldflags_com)
hy_net_LDADD    = $(_ldadd_com)


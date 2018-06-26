# Read this first: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

do_install_append() {
    ### libraries ###
    install -d ${D}${libdir}

    # libegl-nvidia
    cp ${NVIDIA_SRC}/libEGL_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0

    # libgles1-nvidia
    cp ${NVIDIA_SRC}/libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1

    # libgles2-nvidia
    cp ${NVIDIA_SRC}/libGLESv2_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2

    # libglx-nvidia
    cp ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_indirect.so.0

    # libnvidia-glcore
    cp ${NVIDIA_SRC}/tls/libnvidia-tls.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-glcore.so.${PV} ${D}${libdir}/

    # libnvidia-eglcore
    cp ${NVIDIA_SRC}/libnvidia-eglcore.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-glsi.so.${PV} ${D}${libdir}/

    # libnvidia-ml
    cp ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so.1

    # libnvidia-fbc
    cp ${NVIDIA_SRC}/libnvidia-fbc.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-fbc.so.${PV} ${D}${libdir}/libnvidia-fbc.so.1

    # libnvidia-ifr
    cp ${NVIDIA_SRC}/libnvidia-ifr.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ifr.so.${PV} ${D}${libdir}/libnvidia-ifr.so.1

    # libnvidia-encode
    cp ${NVIDIA_SRC}/libnvidia-encode.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-encode.so.${PV} ${D}${libdir}/libnvidia-encode.so.1

    # libnvidia-opencl
    cp ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1

    # libnvidia-compiler
    cp ${NVIDIA_SRC}/libnvidia-compiler.so.${PV} ${D}${libdir}/

    # libnvidia-ptxjitcompiler
    cp ${NVIDIA_SRC}/libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/

    # libnvidia-cfg
    cp ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so.1

    # libnvidia-fatbinaryloader
    cp ${NVIDIA_SRC}/libnvidia-fatbinaryloader.so.${PV} ${D}${libdir}/

    # libcuda
    cp ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so.1

    # libnvcuvid
    cp ${NVIDIA_SRC}/libnvcuvid.so.${PV} ${D}${libdir}/
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so.1

    # nvidia-vdpau-driver
    cp ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/libvdpau_nvidia.so.1

    # xf86-video-nvidia
    mkdir -p ${D}${libdir}/xorg/modules/drivers ${D}${libdir}/xorg/modules/extensions
    cp -r ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/
    cp -r ${NVIDIA_SRC}/libglx.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglx.so
    cp ${NVIDIA_SRC}/libnvidia-wfb.so.${PV} ${D}${libdir}/xorg/modules

    ### executables ###
    mkdir -p ${D}${bindir}

    # nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    cp ${NVIDIA_SRC}/libnvidia-gtk2.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-gtk3.so.${PV} ${D}${libdir}/

    # nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump

    # nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi

    # nvidia-modprobe
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe

    # nvidia-xconfig
    install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig

    # nvidia-cuda-mps
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control

    # nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced

    ### nvidia-doc ### - it should also be split into individual -dev pkgs
    mkdir -p ${D}${datadir}/doc/nvidia ${D}${mandir}/man1
    cp -r ${NVIDIA_SRC}/html ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
}

PACKAGES =+ " \
    xf86-video-nvidia \
    libegl-nvidia \
    libglx-nvidia \
    libgles1-nvidia \
    libgles2-nvidia \
    libnvidia-glcore \
    libnvidia-eglcore \
    libnvidia-ml \
    libnvidia-fbc \
    libnvidia-ifr \
    libnvidia-encode \
    libnvidia-opencl \
    libnvidia-compiler \
    libnvidia-ptxjitcompiler \
    libnvidia-cfg \
    libnvidia-fatbinaryloader \
    libnvcuvid \
    libcuda \
    nvidia-vdpau-driver \
    nvidia-settings \
    nvidia-debugdump \
    nvidia-smi \
    nvidia-modprobe \
    nvidia-xconfig \
    nvidia-cuda-mps \
    nvidia-persistenced \
    "

python populate_packages_prepend() {
    d.appendVar("RDEPENDS_xf86-video-nvidia", " xorg-abi-video-23")
}

do_make_scripts[noexec] = "1"

FILES_${PN} += " \
    ${libdir} \
    ${bindir} \
    "

FILES_${PN}-doc += " \
    ${mandir} \
    ${datadir}/doc/nvidia \
    "

FILES_xf86-video-nvidia += " \
    ${libdir}/xorg/modules/extensions/libglx.so \
    ${libdir}/xorg/modules/drivers/nvidia_drv.so \
    ${libdir}/xorg/modules/libnvidia-wfb.so.${PV} \
    "

FILES_libegl-nvidia = " \
    ${libdir}/libEGL_nvidia.so.${PV} \
    ${libdir}/libEGL_nvidia.so.0 \
    "

FILES_libgles1-nvidia = " \
    ${libdir}/libGLESv1_CM_nvidia.so.${PV} \
    ${libdir}/libGLESv1_CM_nvidia.so.1 \
    "

FILES_libgles2-nvidia = " \
    ${libdir}/libGLESv2_nvidia.so.${PV} \
    ${libdir}/libGLESv2_nvidia.so.2 \
    "

FILES_libglx-nvidia = " \
    ${libdir}/libGLX_nvidia.so.${PV} \
    ${libdir}/libGLX_nvidia.so.0 \
    ${libdir}/libGLX_indirect.so.0 \
    "

FILES_libnvidia-glcore = " \
    ${libdir}/libnvidia-tls.so.${PV} \
    ${libdir}/libnvidia-glcore.so.${PV} \
    "

FILES_libnvidia-eglcore = " \
    ${libdir}/libnvidia-eglcore.so.${PV} \
    ${libdir}/libnvidia-glsi.so.${PV} \
    "

FILES_libnvidia-ml = " \
    ${libdir}/libnvidia-ml.so.${PV} \
    ${libdir}/libnvidia-ml.so.1 \
    "

FILES_libnvidia-fbc = " \
    ${libdir}/libnvidia-fbc.so.${PV} \
    ${libdir}/libnvidia-fbc.so.1 \
    "

FILES_libnvidia-ifr = " \
    ${libdir}/libnvidia-ifr.so.${PV} \
    ${libdir}/libnvidia-ifr.so.1 \
    "

FILES_libnvidia-encode = " \
    ${libdir}/libnvidia-encode.so.${PV} \
    ${libdir}/libnvidia-encode.so.1 \
    "

FILES_libnvidia-opencl = " \
    ${libdir}/libnvidia-opencl.so.${PV} \
    ${libdir}/libnvidia-opencl.so.1 \
    "

FILES_libnvidia-compiler = " \
    ${libdir}/libnvidia-compiler.so.${PV} \
    "

FILES_libnvidia-ptxjitcompiler = " \
    ${libdir}/libnvidia-ptxjitcompiler.so.${PV} \
    "

FILES_libnvidia-cfg = " \
    ${libdir}/libnvidia-cfg.so.${PV} \
    ${libdir}/libnvidia-cfg.so.1 \
    "

FILES_libnvidia-fatbinaryloader = " \
    ${libdir}/libnvidia-fatbinaryloader.so.${PV} \
    "

FILES_libcuda = " \
    ${libdir}/libcuda.so.${PV} \
    ${libdir}/libcuda.so.1 \
    "

FILES_libnvcuvid = " \
    ${libdir}/libnvcuvid.so.${PV} \
    ${libdir}/libnvcuvid.so.1 \
    "

FILES_nvidia-vdpau-driver = " \
    ${libdir}/libvdpau_nvidia.so.${PV} \
    ${libdir}/libvdpau_nvidia.so.1 \
    "

FILES_nvidia-settings = " \
    ${bindir}/nvidia-settings \
    ${libdir}/libnvidia-gtk2.so.${PV} \
    ${libdir}/libnvidia-gtk3.so.${PV} \
    "

FILES_nvidia-debugdump= "${bindir}/nvidia-debugdump"
FILES_nvidia-smi= "${bindir}/nvidia-smi"
FILES_nvidia-modprobe = "${bindir}/nvidia-modprobe"
FILES_nvidia-xconfig = "${bindir}/nvidia-xconfig"
FILES_nvidia-cuda-mps= "${bindir}/nvidia-cuda-mps-control ${bindir}/nvidia-cuda-mps-server"
FILES_nvidia-persistenced = "${bindir}/nvidia-persistenced"


RDEPENDS_${PN} += " \
    libvdpau \
    ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'xf86-video-nvidia', '', d)} \
    "

RDEPENDS_xf86-video-nvidia = " \
    xserver-xorg-module-libwfb \
    "

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
# INSANE_SKIP_libgl-nvidia_append = " ldflags"

INSANE_SKIP_${PN}_append = " ldflags already-stripped"
INSANE_SKIP_xf86-video-nvidia = "ldflags already-stripped"
INSANE_SKIP_libegl-nvidia = "ldflags already-stripped"
INSANE_SKIP_libglx-nvidia = "ldflags already-stripped"
INSANE_SKIP_libgles1-nvidia = "ldflags already-stripped"
INSANE_SKIP_libgles2-nvidia = "ldflags already-stripped"
INSANE_SKIP_libnvidia-glcore = "ldflags already-stripped"
INSANE_SKIP_libnvidia-eglcore = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ml = "ldflags already-stripped"
INSANE_SKIP_libnvidia-fbc = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ifr = "ldflags already-stripped"
INSANE_SKIP_libnvidia-encode = "ldflags already-stripped"
INSANE_SKIP_libnvidia-opencl = "ldflags already-stripped"
INSANE_SKIP_libnvidia-compiler = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ptxjitcompiler = "ldflags already-stripped"
INSANE_SKIP_libnvidia-cfg = "ldflags already-stripped"
INSANE_SKIP_libnvidia-fatbinaryloader = "ldflags already-stripped"
INSANE_SKIP_libnvcuvid = "ldflags already-stripped"
INSANE_SKIP_libcuda = "ldflags already-stripped"
INSANE_SKIP_nvidia-vdpau-driver = "ldflags already-stripped"
INSANE_SKIP_nvidia-settings = "ldflags already-stripped"
INSANE_SKIP_nvidia-debugdump = "ldflags already-stripped"
INSANE_SKIP_nvidia-smi = "ldflags already-stripped"
INSANE_SKIP_nvidia-modprobe = "ldflags already-stripped"
INSANE_SKIP_nvidia-xconfig = "ldflags already-stripped"
INSANE_SKIP_nvidia-cuda-mps = "ldflags already-stripped"
INSANE_SKIP_nvidia-persistenced = "ldflags already-stripped"

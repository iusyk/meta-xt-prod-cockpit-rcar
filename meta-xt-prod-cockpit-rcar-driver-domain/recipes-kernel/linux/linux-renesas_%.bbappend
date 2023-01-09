FILESEXTRAPATHS_prepend := "${THISDIR}/files:"


SRCREV = "${AUTOREV}"
LINUX_VERSION = "5.10.0"

SRC_URI_append = " \
    file://defconfig \
    file://xt_pass_drv.cfg \
    file://boot-options.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://0001-cluster-driver-use-misc-instead-of-char-driver.patch \
"


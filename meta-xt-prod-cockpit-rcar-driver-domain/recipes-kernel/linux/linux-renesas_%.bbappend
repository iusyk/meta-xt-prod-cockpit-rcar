FILESEXTRAPATHS_prepend := "${THISDIR}/files:"


SRCREV = "${AUTOREV}"

SRC_URI_append = " \
    file://0001-CR7_mfis_as_in_v5.10.41.patch \
    file://defconfig \
    file://xt_pass_drv.cfg \
    file://boot-options.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://r8a7795-h3ulcb-4x2g-kf-doma.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://r8a77951-h3ulcb-4x2g-kf-domd.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://0001-OF-DT-Overlay-configfs-interface-v7.patch \
    file://0002-of-overlay-kobjectify-overlay-objects.patch \
    file://0003-of-overlay-global-sysfs-enable-attribute.patch \
    file://0004-Documentation-ABI-overlays-global-attributes.patch \
    file://0005-Documentation-document-of_overlay_disable-parameter.patch \
    file://0006-of-overlay-add-per-overlay-sysfs-attributes.patch \
    file://0007-Documentation-ABI-overlays-per-overlay-docs.patch \
    file://0008-of-rename-_node_sysfs-to-_node_post.patch \
    file://0001-ulcb-kf.dtsi-Enable-Leopard-Imaging-LI-OV10640-490-G.patch \
    file://0002-max9286.c-Check-whether-a-pixel-clock-is-supplied-to.patch \
"


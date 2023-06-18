FILESEXTRAPATHS_prepend := "${THISDIR}/files:"


SRCREV = "${AUTOREV}"

SRC_URI_append = " \
    file://0001-CR7_mfis_as_in_v5.10.41.patch \
    file://defconfig \
    file://xt_pass_drv.cfg \
    file://boot-options.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://r8a7795-h3ulcb-4x2g-kf-doma.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://r8a77951-h3ulcb-4x2g-kf-domd.dtsi;subdir=git/arch/${ARCH}/boot/dts/renesas \
    file://0001-PM-clk-make-PM-clock-layer-compatible-with-clocks-th.patch \
    file://0002-firmware-arm_scmi-Add-clock-management-to-the-SCMI-p.patch \
    file://0001-device-tree-Introduce-scmi-nodes-to-work-with-clocks.patch \
    file://0001-r8a77951-scmi.dtsi-change-the-start-memory-address.patch \
"
#    file://0001-scmi-clocks-add-scmi-clocks-to-rcar_sound.patch 
#    file://domd_ces.dts;subdir=git/arch/${ARCH}/boot/dts/renesas 
#    file://xen_ces.dts;subdir=git/arch/${ARCH}/boot/dts/renesas 


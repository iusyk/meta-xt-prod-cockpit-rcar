FILESEXTRAPATHS_append := "${THISDIR}/files:"

SRC_URI_append = " \
    file://0001-xen-HACK-disable-warning-delay.patch \
    file://0001-xen-hypfs-support-fo-nested-dynamic-hypfs-nodes.patch \
    file://0002-libs-libxenhypfs-handle-blob-properties.patch \
    file://0003-xen-arm-Export-host-device-tree-to-hypfs.patch \
    file://0004-xen-arm-add-generic-SCI-mediator-framework.patch \
    file://0005-xen-arm-introduce-SCMI-SMC-mediator-driver.patch \
    file://0006-tools-arm-Introduce-force_assign_without_iommu-optio.patch \
    file://0007-tools-arm-add-arm_sci-option-to-xl.cfg.patch \
    file://0008-xen-arm-add-SCI-mediator-support-for-DomUs.patch \
    file://0001-sci.h-hypfs-c-Fix-build-errors.patch \
    file://0001-domain_build.c-add-DT-node-to-SCI.patch \
    file://0001-domain-type-check.patch \
    file://0001-debuf-sci_init.patch \
    file://0001-xt_config-activate-CONFIG_ARM_SCI.patch \
    file://0001-xt_defconfig-activate-CONFIG_SCMI_SMC.patch \
    file://0001-xt_defconfig-activate-HOST_DTB_EXPORT.patch \
    file://0001-smci_smc-fix-build-errors.patch \
"

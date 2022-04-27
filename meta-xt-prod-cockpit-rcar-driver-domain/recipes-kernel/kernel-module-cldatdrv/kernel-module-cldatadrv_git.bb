SUMMARY = "CPURTT drive Module"
LICENSE = "CLOSED"

inherit module

PR = "r0"
PV = "0.1"

SRC_URI = "git://github.com/iusyk/cluster_data_drv.git;ptotocol=http;branch=master"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

do_install_append () {
    install -d ${D}${includedir}
    install -m 644 ${S}/r_taurus_cluster_protocol.h ${D}${includedir}
}

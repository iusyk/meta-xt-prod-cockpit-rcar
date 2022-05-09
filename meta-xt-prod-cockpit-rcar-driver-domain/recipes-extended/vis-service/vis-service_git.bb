SUMMARY = "QT Example Recipe"
LICENSE = "CLOSED"

SRC_URI = "file://vis-service.pro \
           file://main.cpp \
           file://VisClient.h \
           file://VisClient.cpp \
           file://vis-service.service \
"

DEPENDS += " \
     qtbase \
     qtquickcontrols2 \
     qtwebsockets \
"

RDEPENDS_${PN} += " \
     qtwebsockets \
     kernel-module-cldatadrv \
"

S = "${WORKDIR}"

inherit pkgconfig qmake5 systemd

SYSTEMD_SERVICE_${PN} = "vis-service.service"

VISSERVER = "10.0.0.1    wwwivi"

FILES_${PN} += " \
    ${systemd_system_unitdir}/vis-service.service \
    ${bindir}/vis-service \
"

do_install_append() {
    install -d ${D}/${bindir}
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/vis-service.service ${D}${systemd_system_unitdir}/vis-service.service
    install -m 0644 ${WORKDIR}/build/vis-service ${D}/${bindir}/
    chmod +x ${D}/${bindir}/vis-service
}


pkg_postinst_ontarget_${PN} () {
    if ! grep -q '${VISSERVER}' $D${sysconfdir}/hosts ; then
        echo '${VISSERVER}' >> $D${sysconfdir}/hosts
    fi
}

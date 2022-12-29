FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SUMMARY = "QT Cluster application"
LICENSE = "CLOSED"

SRC_URI = " \
      file://clusterview.pro \
      file://cluster-view.service \
      file://main.cpp \ 
      file://visclient.h \
      file://visclient.cpp \
      file://commandline.cpp \
      file://commandline.h \
      file://main.qml \
      file://qml.qrc \
      file://images/100_MPH.png \
      file://images/100%.png \
      file://images/102mi.png \
      file://images/102_mph.png \
      file://images/105_mph.png \
      file://images/105_MPH.png \
      file://images/108mi.png \
      file://images/108_mph.png \
      file://images/10_MPH.png \
      file://images/10%.png \
      file://images/110_MPH.png \
      file://images/111_mph.png \
      file://images/114mi.png \
      file://images/114_mph.png \
      file://images/115_MPH.png \
      file://images/117_mph.png \
      file://images/120mi.png \
      file://images/120_mph.png \
      file://images/120_MPH.png \
      file://images/123_mph.png \
      file://images/125_MPH.png \
      file://images/126mi.png \
      file://images/126_mph.png \
      file://images/129_mph.png \
      file://images/12mi.png \
      file://images/12_mph.png \
      file://images/12%.png \
      file://images/130_MPH.png \
      file://images/132mi.png \
      file://images/132_mph.png \
      file://images/135_mph.png \
      file://images/135_MPH.png \
      file://images/138mi.png \
      file://images/138_mph.png \
      file://images/140_MPH.png \
      file://images/141_mph.png \
      file://images/144mi.png \
      file://images/144_mph.png \
      file://images/145_MPH.png \
      file://images/147_mph.png \
      file://images/14%.png \
      file://images/150mi.png \
      file://images/150_mph.png \
      file://images/150_MPH.png \
      file://images/156mi.png \
      file://images/15_mph.png \
      file://images/15_MPH.png \
      file://images/162mi.png \
      file://images/168mi.png \
      file://images/16%.png \
      file://images/174mi.png \
      file://images/180mi.png \
      file://images/186mi.png \
      file://images/18mi.png \
      file://images/18_mph.png \
      file://images/18%.png \
      file://images/192mi.png \
      file://images/198mi.png \
      file://images/204mi.png \
      file://images/20_MPH.png \
      file://images/20%.png \
      file://images/210mi.png \
      file://images/216mi.png \
      file://images/21_mph.png \
      file://images/222mi.png \
      file://images/228mi.png \
      file://images/22%.png \
      file://images/234mi.png \
      file://images/240mi.png \
      file://images/246mi.png \
      file://images/24mi.png \
      file://images/24_mph.png \
      file://images/24%.png \
      file://images/252mi.png \
      file://images/258mi.png \
      file://images/25_MPH.png \
      file://images/264mi.png \
      file://images/26%.png \
      file://images/270mi.png \
      file://images/276mi.png \
      file://images/27_mph.png \
      file://images/282mi.png \
      file://images/288mi.png \
      file://images/28%.png \
      file://images/294mi.png \
      file://images/2%.png \
      file://images/300mi.png \
      file://images/30mi.png \
      file://images/30_mph.png \
      file://images/30_MPH.png \
      file://images/30%.png \
      file://images/32%.png \
      file://images/33_mph.png \
      file://images/34%.png \
      file://images/35_MPH.png \
      file://images/36mi.png \
      file://images/36_mph.png \
      file://images/36%.png \
      file://images/38%.png \
      file://images/39_mph.png \
      file://images/3_mph.png \
      file://images/40_MPH.png \
      file://images/40%.png \
      file://images/42mi.png \
      file://images/42_mph.png \
      file://images/42%.png \
      file://images/44%.png \
      file://images/45_mph.png \
      file://images/45_MPH.png \
      file://images/46%.png \
      file://images/48mi.png \
      file://images/48_mph.png \
      file://images/48%.png \
      file://images/4%.png \
      file://images/50_MPH.png \
      file://images/50%.png \
      file://images/51_mph.png \
      file://images/52%.png \
      file://images/54mi.png \
      file://images/54_mph.png \
      file://images/54%.png \
      file://images/55_MPH.png \
      file://images/56%.png \
      file://images/57_mph.png \
      file://images/58%.png \
      file://images/5_MPH.png \
      file://images/60mi.png \
      file://images/60_mph.png \
      file://images/60_MPH.png \
      file://images/60%.png \
      file://images/62%.png \
      file://images/63_mph.png \
      file://images/64%.png \
      file://images/65_MPH.png \
      file://images/66mi.png \
      file://images/66_mph.png \
      file://images/66%.png \
      file://images/68%.png \
      file://images/69_mph.png \
      file://images/6mi.png \
      file://images/6_mph.png \
      file://images/6%.png \
      file://images/70_MPH.png \
      file://images/70%.png \
      file://images/72mi.png \
      file://images/72_mph.png \
      file://images/72%.png \
      file://images/74%.png \
      file://images/75_mph.png \
      file://images/75_MPH.png \
      file://images/76%.png \
      file://images/78mi.png \
      file://images/78_mph.png \
      file://images/78%.png \
      file://images/80_MPH.png \
      file://images/80%.png \
      file://images/81_mph.png \
      file://images/82%.png \
      file://images/84mi.png \
      file://images/84_mph.png \
      file://images/84%.png \
      file://images/85_MPH.png \
      file://images/86%.png \
      file://images/87_mph.png \
      file://images/88%.png \
      file://images/8%.png \
      file://images/90mi.png \
      file://images/90_mph.png \
      file://images/90_MPH.png \
      file://images/90%.png \
      file://images/92%.png \
      file://images/93_mph.png \
      file://images/94%.png \
      file://images/95_MPH.png \
      file://images/96mi.png \
      file://images/96_mph.png \
      file://images/96%.png \
      file://images/98%.png \
      file://images/99_mph.png \
      file://images/9_mph.png \
      file://images/Auto_Lighting_off.png \
      file://images/Auto_Lighting_on.png \
      file://images/Bar_1.png \
      file://images/Bar_2.png \
      file://images/Bar_3.png \
      file://images/Bar_4.png \
      file://images/Battery_Gauge.png \
      file://images/Battery_icon.png \
      file://images/Battery_level.png \
      file://images/Charge_Reminder.png \
      file://images/CHG_Bar_100%.png \
      file://images/CHG_Bar_10%.png \
      file://images/CHG_Bar_20%.png \
      file://images/CHG_Bar_30%.png \
      file://images/CHG_Bar_40%.png \
      file://images/CHG_Bar_50%.png \
      file://images/CHG_Bar_60%.png \
      file://images/CHG_Bar_70%.png \
      file://images/CHG_Bar_80%.png \
      file://images/CHG_Bar_90%.png \
      file://images/Cloudy.png \
      file://images/cluster-bkg.png \
      file://images/Consumption_Gauge.png \
      file://images/C.png \
      file://images/Cruise_control_on.png \
      file://images/Gears_all_off.png \
      file://images/Gears_D.png \
      file://images/Gears_N.png \
      file://images/Gears_P.png \
      file://images/Gears_R.png \
      file://images/kWh.png \
      file://images/mi.png \
      file://images/mph.png \
      file://images/Power_CHG_Gauge.png \
      file://images/Power_Gauge.png \
      file://images/Range_gauge.png \
      file://images/READY_off.png \
      file://images/READY_on.png \
      file://images/reminder_Bar_01.png \
      file://images/reminder_Bar_02.png \
      file://images/reminder_Bar_03.png \
      file://images/reminder_Bar_04.png \
      file://images/RPM.png \
      file://images/Speed_gauge.png \
      file://images/Speed_limit_EU_bg_circle.png \
      file://images/Speed_limit_indicator_US.png \
      file://images/sport_bckg.png \
      file://images/SPORT_off.png \
      file://images/SPORT_on.png \
      file://images/Temperature_level.png \
      file://images/Turn_left_off.png \
      file://images/Turn_right_off.png \
      file://qml/Battery.qml \
      file://qml/EnergyConsumption.qml \
      file://qml/Footer.qml \
      file://qml/NormalSpeedInfo.qml \
      file://qml/OdoInfo.qml \
      file://qml/PowerChargeInfo.qml \
      file://qml/Range.qml \
      file://qml/SpeedLimitInfo.qml \
      file://qml/SportSpeedInfo.qml \
      file://qml/TimeInfo.qml \
      file://qml/TripInfo.qml \
      file://qml/WeatherInfo.qml \
      file://images/epam.png \
      file://images/Turn_right_on.png \
      file://images/Turn_left_on.png \
"

DEPENDS += " \
     qtbase \
     qtquickcontrols2 \
     qtquick3d \
     qtdeclarative \
     fonts-deployer \
     qtwebsockets \
"

S = "${WORKDIR}"

inherit pkgconfig qmake5 systemd

SYSTEMD_SERVICE_${PN} = "cluster-view.service"

FILES_${PN} += " \
    ${bindir}/clusterview \
    ${systemd_system_unitdir}/cluster-view.service \
"

do_install() {
    install -d ${D}/${bindir}
    install -m 0644 ${WORKDIR}/build/clusterview  ${D}/${bindir}/
    chmod +x ${D}/${bindir}/clusterview

    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/cluster-view.service ${D}${systemd_system_unitdir}/cluster-view.service
}


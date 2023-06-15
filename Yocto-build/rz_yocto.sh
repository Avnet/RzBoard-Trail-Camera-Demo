#!/bin/bash

# -----------------------------Yocto package------------------------------------
# Make sure that the following packages have been downloaded from the official website
# RZ/V Verified Linux Package [5.10-CIP]  V3.0.0-update2
REN_LINUX_BSP_PKG="RTK0EF0045Z0024AZJ-v3.0.0-update2"
SUFFIX_ZIP=".zip"

# RZ MPU Graphics Library Evaluation Version V1.2
REN_GPU_MALI_LIB_PKG="RTK0EF0045Z13001ZJ-v1.21_EN"

# RZ MPU Codec Library Evaluation Version V0.58
REN_VEDIO_CODEC_LIB_PKG="RTK0EF0045Z15001ZJ-v0.58_EN"

# RZ/V2L DRP-AI Support Package Version 7.20
REN_V2L_DRPAI_PKG="r11an0549ej0720-rzv2l-drpai-sp"

# RZ/V2L ISP Support Package Version 1.20
# This package is not needed for integrated package
REN_V2L_ISP_PKG="r11an0561ej0120-rzv2l-isp-sp"

# RZ/V2L Multi-OS Package V1.02
REN_V2L_MULTI_OS_PKG="r01an6238ej0102-rzv2l-cm33-multi-os-pkg"

# RZ/V2L Generic package
REN_V2L_GENERIC_PKG="RZV2L-Generic-Package-v0.5"
# ------------------------------------------------------------------------------

# -----------------------------Global variable------------------------------------
# ------------------------------------------------------------------------------

# Guidance
# Currently, this script supports for two board
# 1. RZV2L SMARC EVK
# 2. RZV2L Avnet
function guideline() {
    echo "------------------------------------------------------------"
    echo "Syntax Error!!!"
    echo "How to use script:"
    echo "Syntax:"
    echo ""
    echo "========="
    echo "1.Prepare the rz build source repository"
    echo " ./rz_yocto.sh setup <target_board> <target_dir>"
    echo ""
    echo "2.Build yocto"
    echo " ./rz_yocto.sh build <target_board> <target_dir>"
    echo ""
    echo "3.Summarize the final output of rz build"
    echo " ./rz_yocto.sh output <target_board> <target_dir>"
    echo "--------------------------"
    echo " - <target_board>:"
    echo "     1. rzv2l_smarc"
    echo "     2. rz_avnet"
    echo " - <target_dir>: the build directory"
    echo "     If not set <target_dir>: current directory will be selected"
    echo "------------------------------------------------------------"
}

function check_and_set_dir() {
    if [ -n "$1" ]; then
        TARGET_DIR=$1
        if [ ! -d "$TARGET_DIR" ]; then
            echo "No such TARGET_DIR=$TARGET_DIR"
            exit 1
        fi
    else
        TARGET_DIR=`pwd`
        echo "Set current directory is <target_dir>=$TARGET_DIR"
    fi
    export WORKSPACE=$TARGET_DIR
    export YOCTO_HOME="${WORKSPACE}/yocto_rzboard"
}

function log_error(){
    local string=$1
    echo -ne "\e[31m $string \e[0m\n"
}

function check_pkg_require(){
        # check required pacakages are downloaded from Renesas website and local package
        local check=0
        cd ${WORKSPACE}

        if [ ! -e ${REN_LINUX_BSP_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_LINUX_BSP_PKG}${SUFFIX_ZIP} !"
                echo "Please download 'RZ/V Verified Linux Package' from Renesas RZ/V2L Website"
                check=1
        fi
        if [ ! -e ${REN_GPU_MALI_LIB_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_GPU_MALI_LIB_PKG}${SUFFIX_ZIP} !"
                echo "Please download 'RZ MPU Graphics Library' from Renesas RZ/V2L Website"
                check=2
        fi
        if [ ! -e ${REN_VEDIO_CODEC_LIB_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_VEDIO_CODEC_LIB_PKG}${SUFFIX_ZIP} !"
                echo "Please download 'RZ MPU Codec Library' from Renesas RZ/V2L Website"
                check=3
        fi
        if [ ! -e ${REN_V2L_DRPAI_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_V2L_DRPAI_PKG}${SUFFIX_ZIP} !"
                echo "Please download 'RZ/V2L DRP-AI Support Package' from Renesas RZ/V2L Website"
                check=4
        fi
        if [ $1 = "rz_avnet" ]; then	
		if [ ! -e ${REN_V2L_ISP_PKG}${SUFFIX_ZIP} ];then
                	log_error "Cannot found ${REN_V2L_ISP_PKG}${SUFFIX_ZIP} !"
                	echo "Please download 'RZ/V2L ISP Support Package' from Renesas RZ/V2L Website"
                	check=5
		fi
	fi
        if [ ! -e ${REN_V2L_MULTI_OS_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_V2L_MULTI_OS_PKG}${SUFFIX_ZIP} !"
                echo "Please download 'RZ/V2L Group Multi-OS Package' from Renesas RZ/V2L Website"
                check=6
        fi
	if [ ! -e ${REN_V2L_GENERIC_PKG}${SUFFIX_ZIP} ];then
                log_error "Cannot found ${REN_V2L_GENERIC_PKG}${SUFFIX_ZIP} !"
                echo "Please get 'RZ/V2L Generic package' from integrated package"
                check=7
        fi

        [ ${check} -ne 0 ] && echo "---Failed---" && exit
}

function extract_to_meta(){
        local zipfile=$1
        local tarfile=$2
        local tardir=$3

        cd ${WORKSPACE}
        pwd
        unzip ${zipfile}
        tar -xzf ${tarfile} -C ${tardir}
        sync
}

function unpack_bsp(){
        local pkg_file=${WORKSPACE}/${REN_LINUX_BSP_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_LINUX_BSP_PKG}

        local bsp="rzv_bsp_v3.0.0.tar.gz"
        local bsp_patch="rzv_v300-to-v300update2.patch"

        extract_to_meta ${pkg_file} "${zip_dir}/${bsp}" ${YOCTO_HOME}
        patch -d ${YOCTO_HOME} -p1 < ${zip_dir}/${bsp_patch}
        rm -fr ${zip_dir}
}

function unpack_gpu(){
        local pkg_file=${WORKSPACE}/${REN_GPU_MALI_LIB_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_GPU_MALI_LIB_PKG}

        local gpu="meta-rz-features.tar.gz"

        extract_to_meta ${pkg_file} "${zip_dir}/${gpu}" ${YOCTO_HOME}
        rm -fr ${zip_dir}
}

function unpack_codec(){
        local pkg_file=${WORKSPACE}/${REN_VEDIO_CODEC_LIB_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_VEDIO_CODEC_LIB_PKG}

        local codec="meta-rz-features.tar.gz"

        extract_to_meta ${pkg_file} "${zip_dir}/${codec}" ${YOCTO_HOME}
        rm -fr ${zip_dir}
}

function unpack_drpai(){
        local pkg_file=${WORKSPACE}/${REN_V2L_DRPAI_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_V2L_DRPAI_PKG}

        local drpai="rzv2l_drpai-driver/meta-rz-features.tar.gz"

        cd ${WORKSPACE}
        unzip -d ${zip_dir} ${pkg_file}
        tar -xzf ${zip_dir}/${drpai} -C ${YOCTO_HOME}
        sync
        rm -fr ${zip_dir}
}

function unpack_isp(){
        local pkg_file=${WORKSPACE}/${REN_V2L_ISP_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_V2L_ISP_PKG}

        local isp="meta-rz-features.tar.gz"

        extract_to_meta ${pkg_file} "${zip_dir}/${isp}" ${YOCTO_HOME}
        rm -fr ${zip_dir}
}

function unpack_multi_os(){
        local pkg_file=${WORKSPACE}/${REN_V2L_MULTI_OS_PKG}${SUFFIX_ZIP}
        local zip_dir=${REN_V2L_MULTI_OS_PKG}

        local rtos="meta-rz-features.tar.gz"

	if [ $1 = "rz_avnet" ]; then
		extract_to_meta ${pkg_file} "${zip_dir}/${rtos}" ${zip_dir}
        	cp -ar ${WORKSPACE}/${zip_dir}/meta-rz-features ${YOCTO_HOME}/meta-multi-os
	else
		extract_to_meta ${pkg_file} "${zip_dir}/${rtos}" ${YOCTO_HOME}
	fi
        rm -fr ${zip_dir}

        # replace the layer name
	if [ $1 = "rz_avnet" ]; then
        	sed -i 's/rz-features/multi-os/g' ${YOCTO_HOME}/meta-multi-os/conf/layer.conf
	fi
}

function unpack_generic_package(){
        local pkg_file=${WORKSPACE}/${REN_V2L_GENERIC_PKG}${SUFFIX_ZIP}
	local zip_file=${REN_V2L_GENERIC_PKG}${SUFFIX_ZIP}

	cd ${WORKSPACE}
        unzip ${zip_file}
}
function remove_redundant_patches(){
        # remove linux patches that were merged into the Avnet kernel
        flist=$(find ${YOCTO_HOME} -name "linux-renesas_*.bbappend")
        for ff in ${flist}
        do
                echo ${ff}
                rm -rf ${ff}
        done

        # remove u-boot patches
        find ${YOCTO_HOME} -name "u-boot_*.bbappend" -print -exec rm -rf {} \;

        # remove tfa patches
        find ${YOCTO_HOME} -name "trusted-firmware-a.bbappend" -print -exec mv {} {}.remove \;
}

function get_meta-rzboard(){
	cd ${YOCTO_HOME}
	git clone https://github.com/Avnet/meta-rzboard.git
	cd meta-rzboard
	git checkout rzboard_dunfell_5.10
	git checkout c80d836c8e0e0067d7e542e1b9c182a2916ff764
	rm -rf .git
}

function apply_local_patch(){
	cd ${YOCTO_HOME}
	
	# apply common patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0001-conf-add-conf-files.patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0002-rz-feature-drp-ai-disable-ai-eva-sw.patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0003-poky-core-disable-udev-psplash-urandom-dropbear-dbus.patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0004-meta-renesas-core-disable-basic-packages-additional-.patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0005-rz-feature-test-app-install-app-run-for-testing.patch
	git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Common/yocto/0006-meta-renesas-core-un-install-v4l2-init.sh.patch

	# apply extra patch
	if [ $1 = "rz_avnet" ]; then
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0001-conf-add-local.conf-file-for-avnet-board.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0002-atf-add-patch-for-optimization-and-integration.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0003-kernel-add-patches-for-optimization-and-integration.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0004-rzboard-core-sample-disable-usb-camera.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0005-rzboard-core-sample-disable-drpai-app-demos-rzboard-.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0006-rzboard-core-disable-additional-packages.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0007-rzboard-connectivity-disable-wlan.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0008-rzboard-connectivity-core-disable-wireless-tools.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0009-rzboard-core-disable-packagegroup-tools-bluetooth.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0010-rzboard-connectivity-disable-rzboard-firmware.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0011-rzboard-core-cm33-remove-installing-cm33-images.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0012-rzboard-core-disable-qt5-demo.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0013-rzboard-gpio-add-gpio-trigger-for-measurement-boot-t.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0014-reduce-time-app_yolov3-show-image.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0015-add-auto-login.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/Avnet/yocto/0016-fix-log-fip-image.patch
	else
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/RZV2L-EVK/yocto/0001-conf-add-local.conf-file-for-smarc-board.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/RZV2L-EVK/yocto/0002-rz-feature-include-openamp-in-meta-rz-feature.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/RZV2L-EVK/yocto/0003-kernel-update-patch-for-optimization.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/RZV2L-EVK/yocto/0004-atf-update-atf-for-optimization-and-integration.patch
		git apply ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Extra/RZV2L-EVK/yocto/0005-kernel-gpio-add-gpio-trigger-for-measuring-boot-time.patch
	fi

	rm -fr ${WORKSPACE}/${REN_V2L_GENERIC_PKG}
	echo "Finished apply local patches"
}

function create_fip_file(){
	unpack_generic_package
	# get CM33 binary and fiptool from generic package
    unzip ${WORKSPACE}/rtos.zip
    if [ $1 = "rz_avnet" ]; then
	    cp ${WORKSPACE}/rtos/* ${OUTPUT}
    else
        cp ${WORKSPACE}/rtos/* ${OUTPUT}
    fi
	cp ${WORKSPACE}/${REN_V2L_GENERIC_PKG}/Tool/fiptool ${OUTPUT}
	rm -fr ${WORKSPACE}/${REN_V2L_GENERIC_PKG}
    rm -fr ${WORKSPACE}/rtos

	# create fip file
	cd ${OUTPUT}
	chmod a+x fiptool
	if [ $1 = "rz_avnet" ]; then
		./fiptool create --align 16 --soc-fw bl31-rzboard.bin --nt-fw-config rzboard.dtb --nt-fw Image \
		--fw-config rzv2l_cm33_rpmsg_demo_secure_code.bin \
		--hw-config rzv2l_cm33_rpmsg_demo_non_secure_vector.bin \
		--soc-fw-config rzv2l_cm33_rpmsg_demo_secure_vector.bin \
		--rmm-fw rzv2l_cm33_rpmsg_demo_non_secure_code.bin fip-rzboard-all.bin

		objcopy -O srec --adjust-vma=0x0000 --srec-forceS3 -I binary fip-rzboard-all.bin fip-rzboard.srec
	else
                ./fiptool create --align 16 --soc-fw bl31-smarc-rzv2l_pmic.bin --nt-fw-config r9a07g054l2-smarc.dtb --nt-fw Image \
                --fw-config rzv2l_cm33_rpmsg_demo_secure_code.bin \
                --hw-config rzv2l_cm33_rpmsg_demo_non_secure_vector.bin \
                --soc-fw-config rzv2l_cm33_rpmsg_demo_secure_vector.bin \
                --rmm-fw rzv2l_cm33_rpmsg_demo_non_secure_code.bin fip-smarc-rzv2l_pmic-all.bin

                objcopy -O srec --adjust-vma=0x0000 --srec-forceS3 -I binary fip-smarc-rzv2l_pmic-all.bin fip-smarc-rzv2l_pmic.srec
	fi	

	# remove all unused files
	rm *.dtb Image *.bin
	rm fiptool

	echo "Finished create fip file"
}
# Main setup
function setup() {
    check_and_set_dir $2

    if [ ! -d ${YOCTO_HOME} ];then
        mkdir -p ${YOCTO_HOME}
    else
	echo "${YOCTO_HOME} existed!, please check the folder again. Finished setup."
	exit 1
    fi

    check_pkg_require $1
    if [ $1 = "rz_avnet" ]; then
        unpack_bsp
        unpack_gpu
        unpack_codec
        unpack_drpai
        unpack_isp
        unpack_multi_os $1
        remove_redundant_patches
	get_meta-rzboard
    else
        unpack_bsp
        unpack_gpu
        unpack_codec
        unpack_multi_os $1
	unpack_drpai
    fi
    unpack_generic_package
    apply_local_patch $1

    ls ${YOCTO_HOME}
    echo ""
    echo "Finished prepare the rz yocto build source repository for $1 board"
    echo "============================================================"
}

# Main build
function build() {
    check_and_set_dir $2

    if [ ! -d ${YOCTO_HOME}/meta-rz-features ];then
        echo "${YOCTO_HOME}/meta-rz-features does not exist!, please check the setup first. Finished build."
        exit 1
    fi
    # Build RZ
    cd ${YOCTO_HOME}
    source poky/oe-init-build-env build
    if [ $1 = "rz_avnet" ]; then
        bitbake avnet-core-image
    else
	bitbake core-image-weston
    fi
    echo
    echo "Finished the rz yocto build for $1 board"
    echo "============================================================"
}

# Main output
function output() {
    check_and_set_dir $2
    export OUTPUT=${WORKSPACE}/output
    
    if [ ! -d ${OUTPUT} ];then
        mkdir -p ${OUTPUT}
    fi
    
    # Collect final output
    cd $OUTPUT
    if [ $1 = "rz_avnet" ]; then
        cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/bl31-rzboard.bin $OUTPUT
	cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/rzboard.dtb $OUTPUT
	cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/Image $OUTPUT
	cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/bl2_bp-rzboard.srec $OUTPUT
	cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/Flash_Writer_SCIF_rzboard.mot $OUTPUT
	cp ${YOCTO_HOME}/build/tmp/deploy/images/rzboard/avnet-core-image-rzboard.tar.bz2 $OUTPUT
    else
	cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/bl31-smarc-rzv2l_pmic.bin $OUTPUT
        cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/r9a07g054l2-smarc.dtb $OUTPUT
        cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/Image $OUTPUT
        cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/bl2_bp-smarc-rzv2l_pmic.srec $OUTPUT
        cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/Flash_Writer_SCIF_RZV2L_SMARC_PMIC_DDR4_2GB_1PCS.mot $OUTPUT
        cp ${YOCTO_HOME}/build/tmp/deploy/images/smarc-rzv2l/core-image-weston-smarc-rzv2l.tar.bz2 $OUTPUT
    fi
    create_fip_file $1

    echo "The output located at: $OUTPUT"
    ls -la $OUTPUT
    echo
    echo "Finished collect the rz yocto output for $1 board"
    echo "============================================================"
}

# Main process
if [ ! -n "$1" ] || [ ! -n "$2" ]; then
    guideline
elif [ $2 = "rzv2l_smarc" ] || [ $2 = "rz_avnet" ]; then
    if [ $1 = "setup" ]; then
        setup $2 $3
    elif [ $1 = "build" ]; then
	build $2 $3
    elif [ $1 = "output" ]; then
        output $2 $3
    else
	guideline
    fi
else
    guideline
fi

exit 1

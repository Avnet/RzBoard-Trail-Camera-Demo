# RzBoard-Trail-Camera-Demo
# Overview
This is the package for RZV2L AVnet board.
This package is optimized and included source code for boot time measurement. It is also integrated FSP package.
About outline of package structure, please refer to Folder Structure section.

# Folder Structure
The following is an outline of the folder structure of this package.
```
RzBoard-Trail-Camera-Demo/
	+---README.md (this document)
	|	
	+---Output -> Integrated package
    	|	bl2_bp-rzboard.srec
    	|	fip_rzboard.srec
    	|	Flash_Writer_SCIF_rzboard.mot
    	|	avnet-core-image-rzboard.tar.bz2
	|
	+---Yocto-build -> zip file and script for build yocto
	|	RZV2L-Generic-Package-v0.5.zip
	|	rz_yocto.sh
	|
	+---CM33 -> FreeRTOS package and source code
	|	Renesas##BSP##rzv2l##fsp####1.0.0.xml
	|	Renesas.CRU.1.5.0.pack
	|	Renesas.Exposure_control.1.2.0.pack
	|	Renesas.I2C_master_for_camera.1.0.0.pack
	|	Renesas.OV5645.1.5.0.pack
	|	rzv2l_cm33_rpmsg_demo
	|	rtos				
```
# How to build and boot.
Please refer to documentation on [AI Apps Integrating Linux with RTOS for Real Time Detection](https://www.hackster.io/bernard-ngabonziza/ai-apps-integrating-linux-with-rtos-for-real-time-detection-3e7b66) for more details.

# History
v0.1:
- Port the software from RZV2L SMARC board to RLV2L Avnet board.
- Support new camera MAAXBOARD MIPI CSI CAMERA (OV5640).
v0.2:
- Add new script to automate the setting for weston.
- Using Darknet YOLO(v3) model for AI inference with our captured images.
v0.3:
- Support display AI inference output image with Full-HD resolution on monitor.
v0.4:
- Optimize the execution time of AI inference app and script in total.
- Support auto login feature.
v0.5:
- Remove unrelated log message in gst_linux_app and AI inference app.

# 3531D_Demo

#### 项目介绍
3531D全功能开发板的演示程序集

#### Decode
解码网络流并显示，可以修改代码中的流地址。

#### Encode
将HDMI-1接口的图像编码并输出流rtmp://xx.xx.xx.xx/live/test

#### Gpio
Gpio测试程序，执行后按下靠近调试串口的“stop”按键，程序会打印出相应的事件。

#### InputTest
全部输入源测试，将输出一个9宫格画面，依次为

SDI-1、SDI-2、SDI-3

SDI-4、HDMI-1、HDMI-2

HDMI-3/VGA、AHD、USBCam

其中USBCam需要外接UVC标准摄像头。

#### Record
录制测试程序，程序执行后会录制一个8秒钟左右的视频，保存在/tmp/test.mp4

#### UI
支持触屏操作的UI测试程序，UI使用Html实现，运行后会出现两个交错的图像，点击“Touch Me”按钮会交换两个图像的位置。
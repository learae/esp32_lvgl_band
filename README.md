  基于esp32-WROOM-32E,使用了PSRAM，flash为8M，使用lvgl开发手表的图形界面，移植了gui-guider生成的代码，触摸芯片采用cst816t，显示驱动芯片采用st7789，lvgl使用v8.3.10版本，mqtt连接阿里云iot平台,实现ota功能，以及各种数据的交换
  
  主界面如下：
  
  ![屏幕截图 2025-04-27 192822](https://github.com/user-attachments/assets/792471a1-bcbc-457e-aee0-1f3aba8f9798)
  
  下拉打开控制界面：
  
  ![image](https://github.com/user-attachments/assets/0a5e48e3-1473-430a-be24-5ff7cdf4f7ec)
  
  开启wifi并连接到可用网络，会自动连接到mqtt并同步时间
  
  主界面左滑进入多功能界面：
  
  ![image](https://github.com/user-attachments/assets/780ca999-00e8-4abf-a81f-761af7c5c084)

  温湿度界面：打开后会定时读取温度有网络时上传阿里云iot，关闭停止读取

  ![image](https://github.com/user-attachments/assets/dc890546-4205-4b4a-b8ee-480ae24f068f)

  天气预报界面：下拉查看七天天气

  ![image](https://github.com/user-attachments/assets/89865300-033c-479b-9b9d-7c2640b5e1b8)![image](https://github.com/user-attachments/assets/de8d731e-9230-4f29-82db-22aecd2b333c)

  亮度控制界面：可选择调光模式

  ![image](https://github.com/user-attachments/assets/1e56e429-f8f3-49a2-97df-c6ca62f88511)

  心率界面：（没有硬件模块，并未完成）

  ![image](https://github.com/user-attachments/assets/9cf953fb-d977-43de-8a8d-9ca3ee11895b)

  连接模式设置：wifi和路由可同时打开

  ![image](https://github.com/user-attachments/assets/3b560a07-7fe9-4ccb-a987-357a77fb8b3c)

  计算器功能：实现简单的计算

  ![image](https://github.com/user-attachments/assets/17df8cd0-3740-4376-88af-35bc1c00ee29)

  声音控制界面：通过蓝牙来控制各个设备的声音（暂未完成）

  ![image](https://github.com/user-attachments/assets/2f7da221-857e-4492-a9cf-28723fd69bc3)

  文本界面：可打开txt文件

  ![image](https://github.com/user-attachments/assets/12364a66-9499-4530-92ac-7d2edd97b4c3)![image](https://github.com/user-attachments/assets/271d9ed0-b742-4e52-8338-739fd8e1f4d5)

  导航模式：通过蓝牙将手机导航信息显示到手表（暂未完成）

  ![image](https://github.com/user-attachments/assets/d535b880-4ac8-4552-802f-0372ef06a566)






  






  
  
  



Welcome to the **Automated Finadvisor Application**, your tool 
for predicting momentum and volatility in the market in order
to assist with your day-trading ventures.

# Disclaimer Notice: 
The creator of this application is not liable for any losses incurred from bad momentum or 
volatility predictions. This application is solely designed for learning purposes. 

## Message from the creator of Automated Finadvisor: 
This project was developed using CLion. You can find CLion 
installation instructions here: [CLion Jetbrains Page](https://www.jetbrains.com/clion/)

# Dependencies:
* [CMake](https://cmake.org/)

# Libraries:
* [Cinder](https://libcinder.org/)

## Quick Start CMake on Linux:
```bash
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ ./nothing    
```

# Download/Installation Instructions:
1. Install Cinder onto your local machine. See download instructions
in the section entitled "Cinder Installation Instructions".
2. Clone github repository to your local machine.
3. Create directory entitled "my-projects" within the cinder directory 
and open project inside this folder.
4. Congratulations. You have successfully downloaded the Automated 
Finadvisor project.
   
# Cinder Installation Instructions:

### Note: 
This guide was derived from [CS 126 Cinder Installation Guide]( 
https://courses.grainger.illinois.edu/cs126/sp2021/notes/cinder-installation-notes/).
If you run into setup issues, visit this site to seek further instructions.
### Instructions:
Ubuntu instructions can be found here: [Ubuntu Cinder Installation](https://www.libcinder.org/docs/guides/linux-notes/ubuntu.html)
1. Download Cinder (v0.9.2) onto your platform. Create a folder entitled "Cinder" and extract the downloaded item into it.
2. Open the Cinder folder in IDE and then build project. Do this only once to build libcinder.
3. Find "BasicApp" within your Cinder folder in **another project window** and run it. There should be a pop-window that will 
allow you to draw a line within the window using your mouse.
4. Congratulations Cinder has been successfully installed onto your local machine.

# Running Application:
* This application contains two running configurations: **train-model** and **stock-data-visualizer**
* Change the working directory by editing these configurations. Change the file path of the working directory to end with
~my-projects/[directory-name]. This will allow you to use relative file paths in place of absolute file paths.
* You will now be able to run and debug these configurations. Running the **train-model** configuration will create 
the training data set, train the model, and test the model. Running the **stock-data-visualizer** will render a technical
analysis chart, candlestick charts, predictions, and price summaries in an external window.
  
# **Analyzing Charts:**
* Carefully scrutinizing the technical analysis and candlestick charts for bullish or bearish patterns or high, medium,
or low volatilities will improve your skills as a day-trader and empower you to make quick, confident decisions.
* A green trend line conveys a positive difference between the closing price and opening price, whereas a red line conveys
a negative difference between the closing price and opening price. Check the image below to see an example of a technical
analysis chart and identify it when running the **stock-data-visualizer**:
  
![alt text](https://www.edelweiss.in/ewwebimages/WebImages/Learner/Line_Chart_Stocks~b2869c5e-d36c-4bdb-80e1-07d4805e70e0.jpg)

* A green candlestick body conveys a tendency towards high volatility during that respective trading day, whereas a red 
candlestick body conveys a tendency towards low volatility during that respective trading day. In rare events, a doji candle,
  one with a single horizontal line in place of a red or green body conveys a tendency towards medium volatility. Check 
  the image below to see an example of a candlestick chart and identify it when running the **stock data visualizer**:
  
![alt text](https://media.istockphoto.com/vectors/stock-exchange-vector-id867941110?k=6&m=867941110&s=612x612&w=0&h=zE-LBIx2hT0eNEfDnuk1EQsGuWplf_hP76ETagH_vic=)




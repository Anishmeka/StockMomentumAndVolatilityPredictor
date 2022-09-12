Final Project Proposal:

For my CS 126 final project, I would like to devise an application for
algorithmic trading. This will serve as an extension of a personal project
that I have worked on for predicting bearish or bullish momentum in the stock
market based on candlestick charts, except I will be using C++ and employing the
Cinder library in accordance with the guidelines for my final project. In addition,
I will have to work on an algorithm for calculating momentum based on differences
in closing prices, which I had not done when working on the momentum predictor
as a personal side project since I had simply created a Convolutional Neural Network
utilizing the FastAI library, a feature of Python alone. My project will not be limited
to momentum prediction alone. I will implement a model for predicting volatility as well, which
I believe will take up a bulk of my time for this project. My dataset will be taken in .csv format from
[TradingView](https://www.tradingview.com/).

My primary motivation for this project is my struggles with day-trading after entering college.
During the summer prior to entering the University of Illinois, I had plenty of time on my hands
to get up fairly early in the morning (since the market follows EST timings) and to monitor stock
prices throughout the day with some of my dad's software. However, at the present moment, exam and work
stress makes it difficult for me to trade stocks, so I would like to automate this process (or at least
begin to as I believe a fully automated system will take several years). My freshman year is almost coming
to a close and I have not made much progress yet on my personal project goal aside from the momentum predictor, so
I have a burning desire to see my final project to completion. The last feature of my project will be data visualization
for which I will employ the Cinder library, namely for displaying technical and Japanese candlestick charts, two
of the most popular mediums through which traders make quick second decisions.

Last but not least, what follows is a rough timeline for my project. A few features are more difficult to 
implement than others, so I would like to allocate more time to these more difficult features. When I had initially 
worked on the momentum predictor in Python, my project had taken me around 1.5 weeks. However, I have more experience now with
implementing the algorithm, so I will train my model for momentum prediction, similar to our tasks for week 1 of Naive 
Bayes by the end of the first week of my final project. Additionally, I will complete visualization
features for technical analysis charts by the end of week 1 for demonstration purposes during code review.
By the end of week 2, I will train my model for volatility prediction, once again similar to week 1 of Naivebayes. 
Additionally, I will finish my visualization features for rendering Japanese candlestick charts using Cinder. Finally,
for the last week of my final project, I will finish implementing a classifier for stock data on the basis of bullish or bearish
momentum and type of volatility. I will evaluate the validation accuracy of my models and tweak my model accordingly
to improve both prediction accuracy and efficiency, similar to the Week 2 portion of
Naivebayes. I will ensure throughout the process that my code is flexible in order to incorporate datasets for a multitude 
of stock categories, including but not limited to blue chip stocks and penny stocks. I don't think my aforementioned 
allocation of time will be subject to change. 

In the event that I were to finish my project early, an extra feature I would implement would be 
identifying patterns and configurations based on candlestick charts, a skill that I have much experience with from
day trading. This task is much greater in difficulty than my aforementioned tasks, so I will realistically have enough time
to construct a model for identifying only popular candlestick and technical patterns. If in the very unlikely event I also
finish this feature, I will work on developing an algorithm for predicting high and low prices at a specified hour in 
the market.

Below are two resources I will use to give a better idea of how my algorithm will look like:
[4 Ways to Predict Market Performance](https://www.investopedia.com/articles/07/mean_reversion_martingale.asp)
[Forecasting stock market volatility](https://www.hindawi.com/journals/ddns/2020/1428628/)


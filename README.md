# ESP2866 Telegram Messenger

A simple Arduino sketch to send messages via Telegram on button press. 

Similar to a hospital "Help Button", user presses the button, LED turns on indicating that a message has been sent and their request for assistance is still present. 

If the user or another user wants to cancel the request, the button can be pressed again and it will turn off. No additional message will be sent until the button is pressed again. 

Built for a ESP2866 NodeMCU V3 however should work on any ESP2866 board. 



ArduinoJSON Version 5.13.5



Credits: 

[How to Build Your First Telegram Bot: A Guide for Absolute Beginners | Process Street | Checklist, Workflow and SOP Software](https://www.process.st/telegram-bot/)





## 1) Setting up Telegram Bot

### Step 1.1: Download the Telegram app for desktop

![Download Telegram for desktop](https://www.process.st/wp-content/uploads/2018/05/Snip20180510_34.png)

Telegram is predominantly a mobile app, but for development purposes you’re going to want to have it installed on the same machine you’re using for writing code. This way, you can quickly test it without unlocking your phone every time. And, you’ll be able to copy and paste your Telegram bot’s API key straight into your text editor.

Time to grab that API key!

### Step 1.2: Chat with the BotFather to get your API key

Telegram bot creation is a novel process because much of it is centered around your own interactions with a Telegram bot. That bot is the BotFather. Inside your Telegram desktop app, you need to search his username and start a conversation with him.

![img](https://www.process.st/wp-content/uploads/2018/05/Snip20180510_36.png)

Give the start command to BotFather by typing `/start`.

You’ll see a list of commands that help you create, edit, and manage your bots. Since it’s your first time, you’ll want `/newbot`.

![img](https://www.process.st/wp-content/uploads/2018/05/Snip20180510_33.png)

Compared to the process for building a [Twitter bot](https://github.com/benjbrandall/minimalist-painter), a [Mastodon bot](http://benjbrandall.xyz/mastodon-bot-ruby/), or any other kind of bot I’ve experimented with, Telegram makes the initial setup *super* easy. I guess that proves what a great tool Telegram bots can be!

After giving the `/newbot` command, you get to pick a name and username for your bot. The name is what your users will see the bot as in their contacts list, and the username is how they’ll find it. Think of the username like a Twitter handle; it has to be unique, and it’s best if it’s short and memorable.

![img](https://www.process.st/wp-content/uploads/2018/05/Snip20180510_37.png)

With that done, you’ll be given your bot’s API key. The API key is how Telegram knows the code you write is associated with this particular bot. Every bot has its own API key, and you shouldn’t share it with anyone or they could hijack your bot and have it carry out their evil deeds.

That concludes our chat with BotFather for now — onto the code!



## 2) Finding your Chat ID on Telegram

In the search box of Telegram, the same spot where you found BotFather, search IDBot.

Send the message to IDBot " /start "

Then, " /getID "

It will give you your ID. You will put this into the provided Arduino Code. 



## 3) Download code from Github

Navigate to the top of this Github page and select Clone or Download as pictured below. Then select download. On Mac, it will automatically unzip. Once unzipped you can open the "ESP2866-Telegram-Messenger.ino"

![img](https://i2.wp.com/www.alphr.com/wp-content/uploads/2019/01/download-github-file-1024x483-1.png?fit=690%2C690&ssl=1)



## 4) Setup Arduino for ESP8266

First we need to add the ESP8266 boards to the Arduino IDE. Do this by going to File > Preferences.

![img](https://puu.sh/HH1il.png) 

When on preferences, go down to the bottom where it says "Additional Boards manager URLS" and paste in: https://arduino.esp8266.com/stable/package_esp8266com_index.json 

![](https://puu.sh/HH1jZ.png)

Once that's done you can now go to Tools > Board and select your appropriate ESP2866 board. 



## 4) Customise your code

Now using the telegram details you setup before, copy your Bot token into the "TOKEN" field and Chat ID into the "CHAT_ID" Field

![](https://puu.sh/HH1mu.png)

Next replace the "WIFI_NAME" & "PASSWORD" with your wifi name and password
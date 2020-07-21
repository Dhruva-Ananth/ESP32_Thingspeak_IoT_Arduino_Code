Welcome !
There are certain steps to follow before you can try and upload the code into ESP32


1. We need to have the Arduino IDE installed and also a firmly working ESP32 right at your hands
2. Along with a B type USB data cable to connect the ESP32


With them in your hands go on and open the Arduino IDE, we have some work to do with the libraries and also the device manager!

1. Go to Files -> Preferences and open preference window and set the “Additional Boards Manager URL’s” as: 
                    https://dl.espressif.com/dl/package_esp32_index.json
2. With that done go to Tools-> Board-> Board Manager and search for ESP32 and press install, 
it will take some time to install make sure that you have internet connection while installing.

Voila you have ESP32 interface ready with the Arduino IDE, as told earlier now you gotta have some library installed

1. There are two ways to do it one get a zip file of the library downloaded and add the zip file by:
sketch->include libraries->include Zip library , browse and add the ZIP wherever you have saved it.

2. The other way is to search for the library by:
tools -> Manage libraries -> searh for the library and add it up

Now for this specific project we are using thingspeak-arduino library and also wifi library you can get the thingspeak-arduino it in the below repository:
https://github.com/mathworks/thingspeak-arduino

The Wifi library is available in the Arduino IDE -  Manage library options

Download the ZIP and follow the regualar instructions for adding the library


WITH THIS YOUR ARDUINO IDE IS ALL SET FOR CODING -YET THERE IS ONE MORE THING!!!!!!!!!!

In order to operate this IoT solution we need to have a thingspeak Account, make sure you go and make an account and a channel along with the field names given and visuvalizations set
all the above words make sense when you try and make an account and explore thingspeak for a while:

well for all the fast pace line guys here is the link to set up a thingspeak channel:
https://www.thethingsnetwork.org/docs/applications/thingspeak/

That may also be a long line to read and understand, so here is a small way
create an account -> go to channels -> my channels -> new channel -> set the number of things you are gonna send and also fill in the details of the names -> and create the channel
Your channel has a number(ID) and also there are something called API keys (you gotta remember the Write API key PS:Copy and Paste do not byheart!)

Now everything is goin all smooth ! all you want is the code and upload and run stuff....ALl THE BEST CHAPS!

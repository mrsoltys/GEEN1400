# Particle Photon

The Particle Photon is one of my favorite micocontrollers. It's small, well documented, inexpensive, and comes with WiFi.

To get started with your new Particle Photon, one of the first things you should do is [install the command line interface (CLI)](https://docs.particle.io/guide/tools-and-features/cli/photon/#installing)

### Getting the MAC address 

To connect to UCB Wireless, you'll have to email [help@colorado.edu](mailto:help@colorado.edu) with your devices' MAC address. To get the mac address:

 1) Connect the Photon to your computer with a USB cable
 2) Hold down the `SETUP` button until the light begins to flash blue.
 3) Open your Terminal App, and type:

	particle serial mac

It normally takes IT about 24 hours to get your device added to CU's network. 

### Programming over USB

You can program the Photon over WiFi, which is a really nice feature... but sometimes you'll want to program it over USB.

## Webhooks

The photon is capable of sending and recieiving HTTP POST and GET requests without any intermedieraies, but if it gets a big reply, it could overrun the 128 kb RAM on the photon and give you bad data. My experience is it's much better to use a server somewhere on the internet to do the GET and POST requests, parse the results, and send just the data you want to your photon. This is called a _webhook_.

You can set up your own webhook on the [particle console](https://console.particle.io/integrations/); however, I feel this makes the behind the sceens of what's going on a bit of a black box. Instead, you can create a webhook from a $.JSON$ file:

    particle webhook create webhook.json

### Example: Using an API to get driving time.

In this example: I'm going to use [Google's Geolocation API](https://developers.google.com/maps/documentation/distance-matrix/start) to try to get real-time traffic data for my commute home. The steps here are similar for other services that have APIs (Weather, Calendars, etc.)

For almost every API, you'll need to get a Key. Never share your Key with anyone! The API Key allows the service to track your usage, and bill you approprately. If you're a hobbiest, your usage should fall into the "Free" Tier on most APIs, but if you decide to take your product to market, you might have to pay to use these services. For google, you can get an [API Key Here](https://developers.google.com/maps/documentation/distance-matrix/get-api-key).

# Testing your response:

Once you have your key, you can do a test request in your browser. Feel free to edit the Origin and Destination address, and make sure to insert your API Key where it says "YOUR_API_KEY_HERE"

    https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&origins=1045+Regent+Dr+Boulder,CO&destinations=1535+Pearl+St,+Boulder,CO+80302&departure_time=now&key=YOUR_API_KEY_HERE

The formatted JSON response is:

		{
		   "destination_addresses" : [ "1535 Pearl St, Boulder, CO 80302, USA" ],
		   "origin_addresses" : [ "1045 Regent Dr, Boulder, CO 80302, USA" ],
		   "rows" : [
		      {
		         "elements" : [
		            {
		               "distance" : {
		                  "text" : "1.7 mi",
		                  "value" : 2656
		               },
		               "duration" : {
		                  "text" : "7 mins",
		                  "value" : 401
		               },
		               "duration_in_traffic" : {
		                  "text" : "6 mins",
		                  "value" : 347
		               },
		               "status" : "OK"
		            }
		         ]
		      }
		   ],
		   "status" : "OK"
		}

I can see that the $duration_in_traffic$ is _6 mins_ 
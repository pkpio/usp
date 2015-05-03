# USP
USP - USB Streams Protocol is an imitation of the [stream control transport protocol][1] of networks in context of USB transfer in kernel space.

#What if offers
  - Multiple streams
  - Multiplexing streams over one connection
  - Inorder deliver of stream data
  
#What it needs
A USB interface that has the following 2 end points
  - Bulk in
  - Bulk out

#Using with Android Accessory Mode
The interface work with both USB Host and Accessory modes for Android device. To use with Accessory mode, check [adk-driver][2] to set device into ADK mode. usctp can take over once the device enter ADK mode.

[1]: http://en.wikipedia.org/wiki/Stream_Control_Transmission_Protocol
[2]: https://github.com/praveendath92/adk-driver

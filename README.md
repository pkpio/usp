# usctp
USCTP - USB SCTP is an imitation of the [stream control transport protocol][1] of networks in context of USB transfer in kernel space.

#What if offers
  - Multiple streams
  - Multiplexing streams over one connection
  - Inorder deliver of stream data
  
#What it needs
A USB interface that has the following 2 end points
  - Bulk in
  - Bulk out

[1]: http://en.wikipedia.org/wiki/Stream_Control_Transmission_Protocol

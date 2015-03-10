#Protocol
- Offers multi-streaming over one USB interface
- Needs Bulk in and Bulk out end points
- A stream is uni-directional
- Number of Incoming and Outgoing streams as params / at setup (?)
- Each stream creates an independent buffer for itself
- Data can be read / written to resp. buffers / calls for these ops (?)
- Protocol takes care of sending stream data to other end
- Protocol handles multiplexing of streams
- Protocol handles inorder delivery of any stream data
- Protocol ensures that stream data are not mixed up due to multiplexing

Note: This is just  a first draft. Things may change while the implementation take place. 


Any kind of contributions welcome :)

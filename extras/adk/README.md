ADK
---------------
This driver, if enabled, sets a supported device into Accessory mode when attached to USB. 
Nothing more, nothing less. No USB devices files are registered.

Flow
---------------
Device attached --> Driver probed --> Set device into Accessory mode --> Driver unprobed --> Device reattached in Accessory mode.

You should take care how to use the device in accessory mode.

# eRomo (work under progress)
A digital picture frame completely designed and 3D printed from scratch. I believe digital picture frames were never succesfull for two main reasons: 
the need to be plugged, and
the light they emmit, potentially disturbing at night.
This project tackles both problems by using an ultra-low consumption e-paper screen from WaveShare. This technology only utilizes a minimal amount of energy while updating 
the image, which then stays without requiring any anergy at all. In addition, this frames do not produce any kind of light. Due to the low energetic consumption, 
the system can work on a simple battery. To eliminate the plug inconvenient, a 5V solar panel is added in the back of the frame, which is able to recharge the battery making it
an autosustainable system.

The screen is connected to an embedded ESP-32 microcontroller with WiFi/Bluetooth connection. This microcontroller fetches a new picture from the cloud periodically 
and updates the screen. In addition, I plan to add a smartphone functionality for it.

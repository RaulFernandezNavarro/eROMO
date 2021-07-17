#include <WiFi.h>
#include <HttpClient.h>

#include "buff.h" // POST request data accumulator
#include "epd.h"  // e-Paper driver
//FALTA SETUP
/*void Drive_setup(char* ssid,char* password,char* myDomain,String myScript,String myFolder)
{
  HttpClient client;
  }
// The server state observation loop -------------------------------------------
//Mas un requester que un loop de server
bool Request_image()
{
    // Looking for a client trying to connect to the server
    WiFiClient client = server.available();

    // Exit if there is no any clients
    if (!client)
        return false;

    // Print log message: the start of request processing
    Serial.print("<<<");

    // Waiting the client is ready to send data
    while (!client.available())
        delay(1);

    // Set buffer's index to zero
    // It means the buffer is empty initially
    Buff__bufInd = 0;

    // While the stream of 'client' has some data do...
    while (client.available()) {
        // Read a character from 'client'
        int q = client.read();

        // Save it in the buffer and increment its index
        Buff__bufArr[Buff__bufInd++] = (byte)q;

        // If the carachter means the end of line, then...
        if ((q == 10) || (q == 13)) {
            // Clean the buffer
            Buff__bufInd = 0;
            continue;
        }

            // e-Paper driver initialization
            if (Buff__signature(Buff__bufInd - 4, "EPD")) {
                Serial.print("\r\nEPD\r\n");
                // Getting of e-Paper's type
                EPD_dispIndex = (int)Buff__bufArr[Buff__bufInd - 1] - (int)'a';
                if(EPD_dispIndex < 0)
                  EPD_dispIndex = (int)Buff__bufArr[Buff__bufInd - 1] - (int)'A' + 26;
                // Print log message: initialization of e-Paper (e-Paper's type)
                Serial.printf("EPD %s", EPD_dispMass[EPD_dispIndex].title);

                // Initialization
                EPD_dispInit();
                //client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                break;
            }

            // Image loading
            if (Buff__signature(Buff__bufInd - 4, "LOAD")) {
                // Print log message: image loading
                Serial.print("LOAD");

                // Load data into the e-Paper
                // if there is loading function for current channel (black or red)
                if (EPD_dispLoad != 0)
                    EPD_dispLoad();
                //client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                break;
            }

            // Select the next data channel
            if (Buff__signature(Buff__bufInd - 4, "NEXT")) {
                // Print log message: next data channel
                Serial.print("NEXT");

                // Instruction code for for writting data into
                // e-Paper's memory
                int code = EPD_dispMass[EPD_dispIndex].next;

                // If the instruction code isn't '-1', then...
                if (code != -1) {
                    // Print log message: instruction code
                    Serial.printf(" %d", code);

                    // Do the selection of the next data channel
                    EPD_SendCommand(code);
                    delay(2);
                }

                // Setup the function for loading choosen channel's data
                EPD_dispLoad = EPD_dispMass[EPD_dispIndex].chRd;
                //client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                break;
            }

            // If the loading is complete, then...
            if (Buff__signature(Buff__bufInd - 4, "SHOW")) {
                // Show results and Sleep
                EPD_dispMass[EPD_dispIndex].show();

                //Print log message: show
                Serial.print("\r\nSHOW");
                //client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                break;
            }

            // If the routine reaches this code,
            // it means the there is no known commands,
        }
    }

    // Clear data stream of the 'client'
    client.flush();

    // Sent to the 'client' the header describing the type of data.
    // In this case 'Content-Type' is 'text/html'
    client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

    // Send the 'index' page if it's needed
    if (isIndexPage)
        sendHtml(client, myIP);
    else
        client.print("Ok!");

    client.print("\r\n");
    delay(1);

    // Print log message: the end of request processing
    Serial.println(">>>");
    return true;
}*/

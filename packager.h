/* Packager for our generic API 

This is surprisingly simple but also the most prone to change.
As we continue to design and refine our communication module, 
the inputs we take from the user (our parameters below), will 
inevitably change.

*/
#define COMM_OVERHEAD 20

struct MessageContext {
  int messageType;
  int time; // Will most likekly change to a custom type
  char* data;
  size_t dataSize;
};

/* Packages data to send using our comm protocol
  REQUIRES:
    msg: The struct of message including... 
      data: array of bytes of data we want to send
      dataSize: number of bytes we want to send, must be the size of data array
      messageType: The "type" of message we are setting (HR, BP, Respatory, etc. ), this is expandable
      time: This can be null (0) and will be filled by the packager optionally, else it is kept at what it is set to
    buf: The array to put our packaged message into, must be dataSize + COMM_OVERHEAD size
  EFFECTS:
    Takes the context and adds time and other aspects TBD to the data into buf
    Returns the new size of the data in buf, 0 if invalid or empty
*/
int packageAPI(MessageContext* msg, char* buf);

/* Packages data to send using our comm protocol
  REQUIRES:
    buf: array of bytes we want to unpackage
    bufSize: number of bytes we want to unpackage, must be the size of buf
    msg:The struct that we will be unpackaging into including
      messageType: The type of message received
      time: The timestamp that the message was received from
      data: Where the data will be read into, THE USER IS REQUIRED TO CLEAN THIS
      dataSize: The size of the message
  EFFECTS:
    Takes in a raw message from buf and converts it to a Message Context
    Returns a 1 on success and a 0 for an error
*/
int unpackageAPI(char* buf, size_t bufSize, MessageContext* msg);
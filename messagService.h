// initialize
bool messageServiceInit();

// Will wake any task that called messageReceive.
bool messageSend(int messageHandle, void * value);

// This function will block until the message is sent.
bool messageReceive(int messageHandle, void * value);

// This struct contains a list of all of the messages.
// Each consists of a semaphore and variable.
struct messageServiceStruct
{
    // semaphores
    // variables
}
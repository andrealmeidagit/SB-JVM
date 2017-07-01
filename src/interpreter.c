#include "interpreter.h"

void runFrame(Frame* frame) {
    
    if (frame->previous != NULL)
        runFrame(frame->previous);
}

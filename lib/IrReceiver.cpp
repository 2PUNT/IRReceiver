#include "IrReceiver.hpp"

bool IrReceiver::GetIrSignal(){
    return !sensor.get();
}

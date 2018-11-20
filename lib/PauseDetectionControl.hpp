#ifndef PAUSE_DETECTION_CONTROL_HPP
#define PAUSE_DETECTION_CONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "IrReceiver.hpp"
#include "MSGDecoderControl.hpp"

class PauseDetectionControl : public rtos::task<>{
private:
    IrReceiver & sensor;
    MSGDecoderControl & Decoder;
    rtos::clock ReceiveClock;
    void main(){
        enum class state_t {IDLE,SIGNAL};
        state_t STATE = state_t::IDLE;
        int n = 0;
        for(;;){
            switch(STATE){
                case state_t::IDLE:
                    wait(ReceiveClock);
                    if(sensor.GetIrSignal()){
                        Decoder.PauseDetected(n);
                        STATE = state_t::SIGNAL;
                    }else{
                        n+=50;
                    }
                    break;
                case state_t::SIGNAL:
                    wait(ReceiveClock);
                    if(!sensor.GetIrSignal()){
                        STATE = state_t::IDLE;
                        n = 0;
                    }
                    break;
            }
        }
    }
public:
    PauseDetectionControl(const unsigned int priority, const char* taskName, IrReceiver & ir,
      MSGDecoderControl & msg):
        task(priority, taskName),
        sensor(ir),
        Decoder(msg),
        ReceiveClock(this,50,"ReceiveClock")
    {}
};

#endif // PAUSE_DETECTION_CONTROL_HPP

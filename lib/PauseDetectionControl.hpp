#ifndef PAUSE_DETECTION_CONTROL_HPP
#define PAUSE_DETECTION_CONTROL_HPP

#include "hwlib.hpp"
#include "rtos.hpp"
#include "IrReceiver.hpp"
#include "MSGDecoderControl.hpp"

/// \brief Control object that manages the detection of ir-pauses
/// \details PauseDetectionControl detects and measures the length of pauses in an ir-signal.
/// It then sends the length of the pauses to a MSGDecoderControl for decoding.
class PauseDetectionControl : public rtos::task<>{
private:
    IrReceiver & sensor;
    MSGDecoderControl & Decoder;
    rtos::clock ReceiveClock;
    void main(){
        enum class state_t {IDLE,SIGNAL};
        state_t STATE = state_t::IDLE;
        int n = 0;
		int startTimeUS = hwlib::now_us();
        for(;;){
            switch(STATE){
                case state_t::IDLE:
                    wait(ReceiveClock);
                    if(sensor.GetIrSignal()){
                        Decoder.PauseDetected(n);
                        STATE = state_t::SIGNAL;
                    }else{
                        //n += 50;
						n+= hwlib::now_us() - startTimeUS;
						startTimeUS = hwlib::now_us();
                    }
                    break;
                case state_t::SIGNAL:
                    wait(ReceiveClock);
                    if(!sensor.GetIrSignal()){
                        STATE = state_t::IDLE;
                        n = 0;
						startTimeUS = hwlib::now_us();
                    }
                    break;
            }
        }
    }
public:
	/// \brief PauseDetectionControl constructor
	/// \details Constructs a PauseDetectionControl object with the specified parameters.
	/// @param priority The priority of this task.
	/// @param taskName The name of the task, used in debugging.
	/// @param ir Reference to the IrReceiver this class will use to detect ir-signals.
	/// @param msg Reference to the MSGDecoderControl this class will send its pauseLengths to.
    PauseDetectionControl(const unsigned int priority, const char* taskName, IrReceiver & ir,
      MSGDecoderControl & msg):
        task(priority, taskName),
        sensor(ir),
        Decoder(msg),
        ReceiveClock(this,50,"ReceiveClock")
    {}
};

#endif // PAUSE_DETECTION_CONTROL_HPP

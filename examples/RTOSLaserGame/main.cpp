#include "hwlib.hpp"
#include "PauseDetectionControl.hpp"
#include "IrReceiver.hpp"
#include "MSGDecoderControl.hpp"
#include "EncodeDecodeMSG.hpp"

int main(){
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms( 1000 );
    namespace target = hwlib::target;

    auto in = target::pin_in(hwlib::target::pins::d30);

	  auto coder = EncodeDecodeMSG();


    MessageChanneler mc;
    MSGDecoderControl msg(mc,coder);
    
    IrReceiver ir(in);
    PauseDetectionControl DETECT(ir, msg);

    rtos::run();
}

#ifndef HWLIB_IR_RECEIVER_HPP
#define HWLIB_IR_RECEIVER_HPP

class IrReceiver{
private:
    hwlib::target::pin_in &sensor;
public:
    IrReceiver(hwlib::target::pin_in &sensor):
        sensor(sensor)
    {}
    bool GetIrSignal(); // Return the sensor value
};

#endif // HWLIB_IR_RECEIVER_HPP
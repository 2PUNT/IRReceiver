#ifndef HWLIB_IR_RECEIVER_HPP
#define HWLIB_IR_RECEIVER_HPP

#include "hwlib.hpp"

/// \brief An ir-receiver.
/// \details A class that uses the output of an ir-receiver to detect ir-signals.
class IrReceiver{
private:
    hwlib::target::pin_in & sensor;
public:
	/// \brief IrReceiver constructor
	/// \details Constructs an IrReceiver object with the specified pin_in.
	/// @param sensor Reference to the pin_in that the IrReceiver's output is connected to.
    IrReceiver(hwlib::target::pin_in &sensor):
        sensor(sensor)
    {}
	
	/// \brief Get the current status of the ir-receiver.
	/// \details Returns true if the current ir-signal is high, and false if the current ir-signal is low.
    bool GetIrSignal(); // Return the sensor value
};

#endif // HWLIB_IR_RECEIVER_HPP

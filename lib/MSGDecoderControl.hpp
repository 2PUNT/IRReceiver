#ifndef MSG_DECODER_CONTROL_HPP
#ifndef MSGDecoderControlDummy_HPP
#define MSGDecoderControlDummy_HPP

/// \brief A dummy to simulate MSGDecoderControl.
class MSGDecoderControl{
public:
	/// \brief MSGDecoderControl (the dummy) constructor.
	MSGDecoderControl(){}
	
	/// \brief Prints the pauseLength using hwlib::cout.
	void PauseDetected(int pauseLength){
		hwlib::cout << pauseLength << '\n';
	}
};
#endif
#endif
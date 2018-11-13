#ifndef MSG_DECODER_CONTROL_HPP
#ifndef MSGDecoderControlDummy_HPP
#define MSGDecoderControlDummy_HPP

class MSGDecoderControl{
public:
	MSGDecoderControl(){}
	
	void PauseDetected(int pauseLength){
		hwlib::cout << pauseLength << '\n';
	}
};
#endif
#endif
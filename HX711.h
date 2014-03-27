/* Arduino library for digital weight scale of hx711
 *
 * hardware design: syyyd
 * available at http://syyyd.taobao.com
 *
 * library design: Weihong Guan (@aguegu)
 * http://aguegu.net
 *
 * library host on
 * https://github.com/aguegu/Arduino
 *
 *  Created on: Oct 31, 2012
 */

#ifndef HX711_H_
#define HX711_H_

#include "Arduino.h"

class Hx711
{
public:
	Hx711(byte times,uint8_t pin_din, uint8_t pin_slk);
	virtual ~Hx711();
	long getValue();
	long averageValue();
	void setOffset(long offset);
	void setScale(float scale = 742.f);
	float getGram();

private:
	const uint8_t _pin_dout;
	const uint8_t _pin_slk;
	long _offset;
	float _scale;
        byte times;
};

#endif /* HX711_H_ */


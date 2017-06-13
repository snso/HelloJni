/*
 * status.h
 *
 *  Created on: 2017Äê3ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef STATUS_H_
#define STATUS_H_

class status {

private:
	static int num;


public:
	status();
	status(const status &sta);
	virtual ~status();

	static int getNum();

};

#endif /* STATUS_H_ */

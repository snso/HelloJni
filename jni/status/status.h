/*
 * status.h
 *
 *  Created on: 2017��3��16��
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

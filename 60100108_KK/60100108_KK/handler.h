#ifndef __HANDLER__H__
#define __HANDLER__H__

#include <string>

class Handler
{
protected:
	virtual void save(string) = 0;
	virtual void load(string) = 0;
};

class HandlerPrint {
protected:
	virtual void print() = 0;
};


#endif // HANDLER_H_INCLUDED

#include "SnakeCommon.h"
#include <string>

class ScreenInterface {
    virtual Direction get_direction() = 0;
	virtual void tic(board_container&, int) = 0;
	virtual void close() = 0;
	virtual void set_log(std::string) = 0;
};
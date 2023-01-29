#include "SnakeCommon.h"

class ScreenInterface {
    virtual Direction get_direction() = 0;
	virtual void tic(board_container&) = 0;
	virtual void close() = 0;
	virtual void set_log(std::string) = 0;
};
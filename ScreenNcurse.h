#include "ScreenInterface.h"
#include <ncurses.h>
#include <vector>
#include <string>


class ScreenNcurse final : public ScreenInterface
{
public:
	ScreenNcurse();
	void tic(board_container&) override;
	void set_log(std::string) override;
	void close() override;
	Direction get_direction() override;
private:
	bool logging_enabled = false;
	int refresh_HZ {4};
	int refresh_delay_us;
	void set_refresh_rate_HZ_to_delay(int rate) {
    	refresh_delay_us = 1e6 / rate;
	}
	void print_ch(char);
	void print_str(std::vector<char> &);
};

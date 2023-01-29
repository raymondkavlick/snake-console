#include <ncurses.h>
#include <vector>
#include <string>

using board_row = std::vector<char>;
using board_container = std::vector<board_row>;
using point = std::pair<int,int>;

class Screen 
{
public:
	Screen();
	Screen(int);
	int get_key();
	using board_container = std::vector<std::vector<char>>;

	void tic(board_container&);
	void set_log(std::string);
	void close();
private:
	bool logging_enabled = false;
	int refresh_HZ {1};
	int refresh_delay_us;
	void set_refresh_rate_HZ_to_delay(int rate) {
    	refresh_delay_us = 1e6 / rate;
	}
	void print_ch(char);
	void print_str(std::vector<char> &);
};

#include <ncurses.h>
#include <vector>

class Screen 
{
public:
	Screen();
	Screen(int);
	~Screen();
	int get_key();
	using board_container = std::vector<std::vector<char>>;

	void tic(board_container&);
private:
	int refresh_HZ {1};
	int refresh_delay_us;
	void set_refresh_rate_HZ_to_delay(int rate) {
    	refresh_delay_us = 1e6 / rate;
	}
	void print_ch(char);
	void print_str(std::vector<char> &);
};

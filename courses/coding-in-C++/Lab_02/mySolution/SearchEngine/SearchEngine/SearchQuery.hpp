#ifndef SEARCHQUERY_HPP
#define SEARCHQUERY_HPP

#include <stdlib.h>
#include <string>

class SearchQuery
{
private:
	std::string input;
	uint8_t max_results;

public:
	SearchQuery(std::string input, uint8_t max_results)
	{
		this->input = input;
		this->max_results = max_results;
	}
	const std::string get_input()
	{
		return this->input;
	}
	const uint8_t get_max_results()
	{
		return this->max_results;
	}
	void set_input(std::string input)
	{
		this->input = input;
	}
	void set_max_results()
	{
		this->max_results = max_results;
	}
};

#endif
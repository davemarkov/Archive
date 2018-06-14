#ifndef DATA_HEADER
#define DATA_HEADER

struct Data
{
	short encoded;
	int codeLength;
	char elem;
	int cnt;
	Data *left, *right;

	Data() : encoded(0), codeLength(0), elem(0), cnt(0),
		left(nullptr), right(nullptr) {}

	bool operator<(const Data& rhs)
	{
		return cnt < rhs.cnt;
	}

	bool operator==(const Data& rhs)
	{
		return cnt == rhs.cnt;
	}

};

#endif//DATA_HEADER
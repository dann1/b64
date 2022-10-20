#include <iostream>
#include "base64.h"
// temporary workaround
#pragma GCC optimize("O2")

using namespace std;

#define puts(x) cout << x << endl;
#define help() puts("usage: b64 --decode/--encode <base64 encoded text>");

int main(int argc, char const *argv[])
{
	string modes[2] = {"--decode", "--encode"};

	string mode;
	string input;

	switch (argc)
	{
	case 1:
		help();
		return 1;

		break;
	case 2:
		mode = argv[1];

		if (mode.compare("--help") == 0 || mode.compare("-h") == 0)
		{
			help();
		}
		else
		{
			input = argv[1];
			input = base64_decode(input, false);

			puts(input);
		}

		break;

	default:
		mode = argv[1];
		input = argv[2];

		if (modes[0].compare(mode) == 0)
		{
			input = base64_decode(input, false);

			puts(input)
		}
		else if ((modes[1].compare(mode) == 0))
		{
			input = base64_encode(input, false);
		}
		else
		{
			puts("Mode not valid");
			help();
			return 1;
		}

		break;
	}
}
#include <iostream>

int main(int argc, char **argv)
{
	    if (argc == 1)
       	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; argv[i]; i++)
	{
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)(std::toupper(argv[i][j]));
        if (argv[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

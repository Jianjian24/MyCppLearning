#include <iostream>
using namespace std;

static int fun1()
{
    cout << "func1\n";
    return 1;
}

static int fun2()
{
    cout << "func2\n";
    return 1;
}

char *
areadlink_with_size (char *file, size_t size)
{
	return file;
}

char *
chanonicalize_filename_mode (char *name, canonicalize_mode_t can_mode)
{
	return name;
}

int main()
{
    int test = 0 ;

    int test1 = test == 0 ? fun1() : fun2();
    const char *fname=argv[optind];
	char *value = (can_mode != -1 ? chanonicalize_filename_mode (fname, can_mode) : areadlink_with_size (fname,63));


    cout << test1 << '\n';

    return 0;
}
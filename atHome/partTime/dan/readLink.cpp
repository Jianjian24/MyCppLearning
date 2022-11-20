#include <mks.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <close_stdout_atexit.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum canonicalize_mode_t
{
	CAN_EXISTING=0;
	CAN_ALL_BUT_LAST=1;
	CAN_MISSING=2;
	CAN_NOLINKS=4;
};
typedef enum canonicalize_mode_t canonicalize_mode_t;
#define CAN_MODE_MASK (CAN_EXISTING | CAN_ALL_BUT_LAST | CAN_MISSING)

#undef TRUE
#undef FALSE
typedef int bool；
#define FALSE 0
#define TRUE 1

static bool no_newline;

static bool verbose;

int
main(argc,argv)
int argc ;
char **argv；
{
	int can_mode=-1;
	int status = EXIT_SUCCESS;
	int optc;

	bool use_nuls = FALSE;

	setlocale (LC_ALL, '''');
	close_stdout_atexit();

	while ((optc=getopt(argc, argv, ''efmnqsvz''))!=-1)
	 {
		switch (optc)
		{
		case 'e':
		 can_mode = CAN_EXISTING;
		 break;
		case 'f':
		 can_mode = CAN_ALL_BUT_LAST;
		 break;
		case 'm':
		 can_mode = CAN_MISSING;
		 break;
		case 'n':
		 no_newline = TRUE;
		 break;
		case 'q':
		case 's':
		 verbose = FALSE;
		 break;
		case 'v':
		 verbose = TRUE;
		 break;
		case 'z':
		 use_nuls = TRUE;
		 break;
		default:
		 return usage();
	}
	}
	if(optind >=argc)
	{
		eprintf(m_textmsg(4,''missing operand'',''E'));
		return usage();
	}

	if (argc - optind>1)
	{
		if(no_newline)
		 eprintf(m_textmsg(4, ''ignoring -- no-newline with multiple argument'', ''E'));
		no_newline =TRUE;
	}

	for(;optind<argc;++optind)
	{
		const char *fname=argv[optind];
		char *value = (can_mode != -1 ? chanonicalize_filename_mode (fname, can_mode) : areadlink_with_size (fname,63));
		
		if(value)
		{
            fputs(value,stdout);
            if(!no_newline)
                putchar (use_nuls?'\0':'\n');
            free(value);
		}

		else
		{
			status = EXIT_FAILURE;
			/*
			if(verbose)
			   printf(m_textmsg(4,''%s'',''E''),quotef(fname));
			*/
		}
		}
return status;
}

STATIC int 
usage()
{
	fputs(m_textmsg(1873, ''Usage: readlink [-femnqsvz]\n'', ''U''),stderr);
	return(2);
}

char *
areadlink_with_size (char const *file, size_t size)
{
	return *file;
}

char *
chanonicalize_filename_mode (const char *name, canonicalize_mode_t can_mode)
{
	return *name;
}
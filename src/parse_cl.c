/******************************************************************************
**
** parse_cl.c
**
** Fri Jul 18 16:05:49 2014
** Linux 3.2.0-23-generic-pae (#36-Ubuntu SMP Tue Apr 10 22:19:09 UTC 2012) i686
** vagrant@precise32 (vagrant)
**
** C file for command line parser
**
** Automatically created by genparse v0.8.7
**
** See http://genparse.sourceforge.net for details and updates
**
******************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "parse_cl.h"

static struct option const long_options[] =
{
  {"help", no_argument, NULL, 'h'},
  {"version", no_argument, NULL, 'v'},
  {"size", required_argument, NULL, 's'},
  {"left", no_argument, NULL, 'l'},
  {"right", no_argument, NULL, 'r'},
  {"run", required_argument, NULL, 'u'},
  {"hi", no_argument, NULL, 'i'},
  {"low", no_argument, NULL, 'o'},
  {NULL, 0, NULL, 0}
};

/*----------------------------------------------------------------------------
**
** Cmdline ()
**
** Parse the argv array of command line parameters
**
**--------------------------------------------------------------------------*/

void Cmdline (struct arg_t *my_args, int argc, char *argv[])
{
  extern char *optarg;
  extern int optind;
  int c;
  int errflg = 0;

  my_args->h = false;
  my_args->v = false;
  my_args->l = false;
  my_args->r = false;
  my_args->u = NULL;
  my_args->i = false;
  my_args->o = false;

  optind = 0;
  while ((c = getopt_long (argc, argv, "hvs:lru:io", long_options, &optind)) != - 1)
    {
      switch (c)
        {
        case 'h':
          my_args->h = true;
          usage (EXIT_SUCCESS, argv[0]);
          break;

        case 'v':
          my_args->v = true;
          break;

        case 's':
          my_args->s = atoi (optarg);
          break;

        case 'l':
          my_args->l = true;
          break;

        case 'r':
          my_args->r = true;
          break;

        case 'u':
          my_args->u = optarg;
          break;

        case 'i':
          my_args->i = true;
          break;

        case 'o':
          my_args->o = true;
          break;

        default:
          usage (EXIT_FAILURE, argv[0]);

        }
    } /* while */

  if (errflg)
    usage (EXIT_FAILURE, argv[0]);

  if (optind >= argc)
    my_args->optind = 0;
  else
    my_args->optind = optind;
}

/*----------------------------------------------------------------------------
**
** usage ()
**
** Print out usage information, then exit
**
**--------------------------------------------------------------------------*/

void usage (int status, char *program_name)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, "Try `%s --help' for more information.\n",
            program_name);
  else
    {
      printf ("\
Usage: %s [OPTION]...\n\
\n\
  -h, --help              display this help and exit\n\
  -v, --version           output version information and exit\n\
  -s, --size              size of hands, defaults to 8 (7, 8, 9, 10, J, Q, K, A\n\
  -l, --left              left run\n\
  -r, --right             right run\n\
  -u, --run               mutti run\n\
  -i, --hi                ace hi\n\
  -o, --low               ace low (default)\n\
\n", program_name);
    }
  exit (status);
}

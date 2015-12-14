#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <getopt.h>

main ()
{
struct passwd  *pw;
uid_t uid;
uid = getuid ();
pw = (getpwuid (uid));
puts (pw->pw_name);
}

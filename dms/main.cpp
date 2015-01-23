#include <iostream>
#include <Windows.h>

// #define WAIT_TIME_SEC 5 // check the file every 10 seconds

int main(int argc, char** argv)
{
  if(argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " canaryfile seconds" << std::endl;
    std::cerr << "Example: " << argv[0] << "foo.txt 5" << std::endl;
    return 1;
  }

  char* canaryfile = argv[1];
  int seconds = atoi(argv[2]);

  while(true)
  {
    DWORD attrs = GetFileAttributesA(canaryfile); // get file attributes

    if(attrs == INVALID_FILE_ATTRIBUTES)
    {
      system("rundll32.exe user32.dll, LockWorkStation"); // passes command to the shell
    }
    else
    {
      Sleep(seconds * 1000); // Sleep() accepts the time in milliseconds
    }
  }

  return 0;
}
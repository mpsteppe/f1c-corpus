// Function: __amsg_exit @ 0058a2a6
// Size (bytes): 34


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_008d3ebc == 1) {
    FUN_005932ba();
  }
  FUN_005932f3(param_1);
  (*(code *)PTR___exit_005e65b0)(0xff);
  return;
}



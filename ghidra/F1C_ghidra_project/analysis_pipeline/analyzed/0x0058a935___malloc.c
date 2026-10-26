// Function: _malloc @ 0058a935
// Size (bytes): 18


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_008d41b0);
  return pvVar1;
}



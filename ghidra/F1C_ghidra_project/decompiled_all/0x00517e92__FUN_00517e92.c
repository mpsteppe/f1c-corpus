// Function: FUN_00517e92 @ 00517e92
// Strings:  [Out of Memory]


void * FUN_00517e92(int param_1,size_t param_2)

{
  void *pvVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    pvVar1 = _malloc(param_2);
    if (pvVar1 == (void *)0x0) {
      FUN_00511869(param_1,"Out of Memory");
    }
    return pvVar1;
  }
  return (void *)0x0;
}



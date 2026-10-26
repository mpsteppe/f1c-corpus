// Function: FUN_00418a20 @ 00418a20
// Size (bytes): 49


undefined1 FUN_00418a20(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_004189f0(param_1);
  if (cVar1 == '\0') {
    cVar1 = FUN_004189b0(param_1);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}



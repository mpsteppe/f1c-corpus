// Function: FUN_0040dcd0 @ 0040dcd0
// Size (bytes): 96


undefined4 __thiscall FUN_0040dcd0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  param_1[0x21] = 0;
  *param_1 = 1;
  FUN_0040d490();
  iVar2 = FUN_00568210(param_2);
  param_1[0x21] = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  *param_1 = 2;
  cVar1 = FUN_0040ddf0();
  if (cVar1 != '\0') {
    return 1;
  }
  *param_1 = 0xffffffff;
  return 0;
}



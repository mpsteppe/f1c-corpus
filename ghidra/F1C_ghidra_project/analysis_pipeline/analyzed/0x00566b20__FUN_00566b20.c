// Function: FUN_00566b20 @ 00566b20
// Size (bytes): 108


bool __thiscall FUN_00566b20(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_400 [1024];
  
  FUN_00566b90();
  FUN_00568620(0x400);
  iVar1 = FUN_00534b00();
  *param_1 = iVar1;
  param_1[4] = 1;
  param_1[3] = param_3;
  *(undefined1 *)(param_1 + 6) = 1;
  if (iVar1 != 0) {
    FUN_00566650(local_400);
  }
  return iVar1 != 0;
}



// Function: FUN_0048d0d0 @ 0048d0d0
// Size (bytes): 193


undefined4 __fastcall FUN_0048d0d0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  iVar1 = (**(code **)(*param_1 + 0x20))();
  iVar2 = (**(code **)(*param_1 + 0x18))();
  if (0 < iVar1 - iVar2) {
    iVar3 = (**(code **)(*param_1 + 0x18))();
    FUN_00498880(&iStack_8,auStack_4);
    iStack_8 = iStack_8 - (iVar3 + (iVar1 - iVar2) / 2);
    iVar1 = param_1[0xcd] + iStack_8;
    iVar2 = param_1[0xca] * param_1[0xcb];
    if (0 < iVar2) {
      for (; iVar1 < 0; iVar1 = iVar1 + iVar2) {
      }
      for (; iVar2 < iVar1; iVar1 = iVar1 - iVar2) {
      }
      iVar1 = iVar1 / param_1[0xcb];
      iVar2 = param_1[0xca] + -1;
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      else if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      iVar2 = param_1[0xce];
      while (iVar1 != iVar2) {
        (**(code **)(*param_1 + 0xb8))(0 < iStack_8);
        iVar2 = param_1[0xce];
      }
    }
  }
  return 0;
}



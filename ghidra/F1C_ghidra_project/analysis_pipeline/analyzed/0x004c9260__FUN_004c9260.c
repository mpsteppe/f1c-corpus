// Function: FUN_004c9260 @ 004c9260
// Size (bytes): 27


undefined4 __fastcall FUN_004c9260(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    if (iVar1 == 1) {
      return *(undefined4 *)(param_1 + 0x24);
    }
    if (iVar1 == 2) {
      return *(undefined4 *)(param_1 + 0x28);
    }
  }
  return uVar2;
}



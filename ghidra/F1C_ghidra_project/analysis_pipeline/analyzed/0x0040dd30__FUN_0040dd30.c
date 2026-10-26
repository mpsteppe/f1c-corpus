// Function: FUN_0040dd30 @ 0040dd30
// Size (bytes): 68


undefined4 __fastcall FUN_0040dd30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x88) != 0) && (*(int *)(*(int *)(param_1 + 0x88) + 4) != 0)) {
    iVar1 = FUN_0049adb0();
    if (iVar1 != 0) {
      uVar2 = FUN_0049adb0();
      uVar2 = FUN_0040d4c0(uVar2);
      return uVar2;
    }
  }
  return 0;
}



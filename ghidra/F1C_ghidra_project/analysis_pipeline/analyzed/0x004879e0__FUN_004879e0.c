// Function: FUN_004879e0 @ 004879e0
// Size (bytes): 58


undefined4 __fastcall FUN_004879e0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004874e0();
  if (iVar1 != 0) {
    FUN_00487760(1);
    FUN_00487960();
    iVar1 = (**(code **)(*param_1 + 0x98))();
    if (iVar1 == 0) {
      FUN_00486600();
      return 0;
    }
  }
  return 0xffffffff;
}



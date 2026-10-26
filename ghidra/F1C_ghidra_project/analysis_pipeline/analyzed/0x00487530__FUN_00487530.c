// Function: FUN_00487530 @ 00487530
// Size (bytes): 58


undefined4 __fastcall FUN_00487530(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004874e0();
  if (iVar1 != 0) {
    FUN_00487260(1);
    FUN_00487460();
    iVar1 = (**(code **)(*param_1 + 0x98))();
    if (iVar1 == 0) {
      FUN_00486600();
      return 0;
    }
  }
  return 0xffffffff;
}



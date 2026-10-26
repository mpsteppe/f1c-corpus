// Function: FUN_00473b90 @ 00473b90
// Size (bytes): 52


undefined4 __fastcall FUN_00473b90(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0xb);
  if (iVar1 != 0) {
    FUN_00477280(param_1);
  }
  *(undefined1 **)(param_1 + 800) = &DAT_007d0474;
  *(undefined4 *)(param_1 + 0x31c) = 0x116;
  return 0;
}



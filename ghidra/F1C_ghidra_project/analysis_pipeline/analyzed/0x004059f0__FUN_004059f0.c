// Function: FUN_004059f0 @ 004059f0
// Size (bytes): 55


void __fastcall FUN_004059f0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x10);
    if (iVar1 != 0) {
      _AIL_end_sample_4(iVar1);
      _AIL_init_sample_4(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10));
    }
    **(undefined4 **)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}



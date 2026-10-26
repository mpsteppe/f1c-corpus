// Function: FUN_004775f0 @ 004775f0
// Size (bytes): 46


undefined4 __fastcall FUN_004775f0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00477810();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x174) != param_1[0x61])) {
    param_1[0x61] = *(int *)(iVar1 + 0x174);
    (**(code **)(*param_1 + 0xa0))();
  }
  return 0;
}



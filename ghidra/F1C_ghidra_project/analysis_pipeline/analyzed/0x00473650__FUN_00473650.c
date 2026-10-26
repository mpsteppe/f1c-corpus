// Function: FUN_00473650 @ 00473650
// Size (bytes): 42


undefined4 __fastcall FUN_00473650(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x13);
  if (iVar1 != 0) {
    FUN_00477280(param_1);
  }
  (**(code **)(*param_1 + 0xac))();
  return 0;
}



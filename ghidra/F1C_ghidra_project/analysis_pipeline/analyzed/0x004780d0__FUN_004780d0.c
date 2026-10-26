// Function: FUN_004780d0 @ 004780d0
// Size (bytes): 54


undefined4 __fastcall FUN_004780d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00461cd0();
  if (iVar1 == 3) {
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x17);
  }
  else {
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x15);
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
  }
  return 0;
}



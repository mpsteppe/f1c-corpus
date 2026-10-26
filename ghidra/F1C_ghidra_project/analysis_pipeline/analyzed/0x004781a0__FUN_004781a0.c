// Function: FUN_004781a0 @ 004781a0
// Size (bytes): 54


undefined4 __fastcall FUN_004781a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00461cd0();
  if (iVar1 == 3) {
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x18);
  }
  else {
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x11);
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
  }
  return 0;
}



// Function: FUN_004782c0 @ 004782c0
// Size (bytes): 53


undefined4 __fastcall FUN_004782c0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x10);
  if ((iVar1 != 0) && (param_1[0x3a] != *(int *)(iVar1 + 0x174))) {
    param_1[0x3a] = *(int *)(iVar1 + 0x174);
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return 0;
}



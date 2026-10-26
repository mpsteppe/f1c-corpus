// Function: FUN_00548810 @ 00548810
// Size (bytes): 57


undefined4 __fastcall FUN_00548810(undefined4 *param_1)

{
  int iVar1;
  int extraout_ECX;
  int *extraout_EDX;
  
  iVar1 = param_1[9];
  *param_1 = 0;
  param_1[1] = 0;
  while (iVar1 != 0) {
    FUN_00546430();
    *extraout_EDX = *extraout_EDX + *(int *)(extraout_ECX + 0x94);
    extraout_EDX[1] = extraout_EDX[1] + *(int *)(extraout_ECX + 0x98);
    iVar1 = *(int *)(extraout_ECX + 0xc0);
  }
  return 0;
}



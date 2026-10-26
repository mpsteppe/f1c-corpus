// Function: FUN_00586c90 @ 00586c90
// Size (bytes): 12


undefined4 __fastcall FUN_00586c90(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  *param_1 = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 < 6);
}



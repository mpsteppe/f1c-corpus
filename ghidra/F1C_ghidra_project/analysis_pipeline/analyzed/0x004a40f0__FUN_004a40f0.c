// Function: FUN_004a40f0 @ 004a40f0
// Size (bytes): 24


void __fastcall FUN_004a40f0(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0x68] = 0;
  for (iVar1 = 0x68; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



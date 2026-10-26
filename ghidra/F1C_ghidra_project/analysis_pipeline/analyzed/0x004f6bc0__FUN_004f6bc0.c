// Function: FUN_004f6bc0 @ 004f6bc0
// Size (bytes): 34


void __fastcall FUN_004f6bc0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[0x10] = 0;
  param_1 = param_1 + 2;
  iVar1 = 5;
  do {
    param_1[-1] = 0;
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 3;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



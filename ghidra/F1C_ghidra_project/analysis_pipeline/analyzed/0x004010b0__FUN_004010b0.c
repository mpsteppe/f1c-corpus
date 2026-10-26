// Function: FUN_004010b0 @ 004010b0
// Size (bytes): 128


void __fastcall FUN_004010b0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = param_1 + 2;
  do {
    iVar1 = iVar1 + 1;
    *piVar2 = iVar1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 4);
  *(undefined1 *)(param_1 + 0x4b) = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  *param_1 = 0x40980000;
  param_1[1] = 0x408a0000;
  param_1[0x4a] = 0x3f7eb852;
  param_1[0x58] = 0x68;
  param_1[0x59] = 0x34;
  param_1[0x5a] = 3;
  param_1[0x57] = 1;
  return;
}



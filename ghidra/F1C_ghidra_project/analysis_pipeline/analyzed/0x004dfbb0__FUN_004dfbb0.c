// Function: FUN_004dfbb0 @ 004dfbb0
// Size (bytes): 237


undefined4 * __fastcall FUN_004dfbb0(undefined4 *param_1)

{
  int extraout_EDX;
  int iVar1;
  
  FUN_004dfa50();
  param_1[0x24] = 0;
  param_1[0x25] = 0xffffffff;
  iVar1 = 4;
  do {
    FUN_004dfb00();
    FUN_004dfa50();
    FUN_004dfa50();
    FUN_004dfb60();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004dfb00();
  FUN_004dfa50();
  FUN_004dfa50();
  iVar1 = 8;
  do {
    FUN_004dfa50();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  do {
    FUN_004dfb90();
  } while (extraout_EDX != 1);
  iVar1 = 0xb;
  do {
    FUN_004de5f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *param_1 = 0;
  param_1[0x2ea] = 0;
  param_1[0xaf5] = 0;
  FUN_004e09e0();
  return param_1;
}



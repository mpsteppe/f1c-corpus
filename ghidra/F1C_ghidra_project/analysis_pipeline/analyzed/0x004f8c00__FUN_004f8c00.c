// Function: FUN_004f8c00 @ 004f8c00
// Size (bytes): 67


undefined4 __fastcall FUN_004f8c00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_008afc8c == (code *)0x0) {
    return 4;
  }
  iVar1 = (*DAT_008afc8c)(param_1,param_2,param_3);
  if (iVar1 == 1) {
    return 0;
  }
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return 6;
  }
  return 7;
}



// Function: FUN_004d2260 @ 004d2260
// Size (bytes): 95


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d2260(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_008aae64;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  FUN_004b33b0(4,0x15,8,0xff,(float)_DAT_008afea0,1);
  *(undefined4 *)(iVar1 + 8) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  return;
}



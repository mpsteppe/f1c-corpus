// Function: FUN_00498740 @ 00498740
// Size (bytes): 106


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00498740(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 100) = DAT_007cb2fc;
  *(undefined4 *)(param_1 + 0x68) = DAT_007cb300;
  *(undefined4 *)(param_1 + 0x6c) = DAT_007cb304;
  uVar1 = FUN_0044f7d0();
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  uVar1 = __ftol();
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = __ftol();
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  return;
}



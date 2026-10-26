// Function: FUN_004b2c20 @ 004b2c20
// Size (bytes): 44


void __fastcall FUN_004b2c20(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0xf);
  uVar2 = __ftol();
  *(uint *)(param_1 + 0xf) = (uVar2 & 0x3f) << 2 ^ uVar1 & 0xffffff03;
  return;
}



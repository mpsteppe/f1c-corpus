// Function: FUN_004dae80 @ 004dae80
// Size (bytes): 25


uint __fastcall FUN_004dae80(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  uVar2 = uVar1;
  if ((0 < (int)uVar1) && (uVar2 = (int)uVar1 / 6, (int)uVar1 % 6 == 0)) {
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  return uVar2 & 0xffffff00;
}



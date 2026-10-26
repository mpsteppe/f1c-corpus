// Function: FUN_004bc340 @ 004bc340
// Size (bytes): 75


uint __fastcall FUN_004bc340(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_007c569c;
  if (((DAT_007c569c == 5) &&
      (((uVar1 = *(uint *)(param_1 + 0x30), uVar1 != 1 && (uVar1 != 3)) ||
       ((DAT_007cef84 != 0 && ((uVar1 != 3 && (DAT_007c56a4 == 5)))))))) &&
     ((DAT_007c56a8 == 5 || ((DAT_007c56a8 == 6 || (uVar1 = DAT_007c56a8, DAT_007c56a8 == 8)))))) {
    return CONCAT31((int3)(DAT_007c56a8 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}



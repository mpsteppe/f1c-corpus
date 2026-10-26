// Function: FUN_0040dd80 @ 0040dd80
// Size (bytes): 69


uint __fastcall FUN_0040dd80(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_1 + 1;
  switch(uVar1) {
  case 3:
  case 4:
    iVar2 = FUN_0040c870();
    param_1[0x23] = iVar2;
    param_1[0x24] = iVar2;
    uVar1 = DAT_007c54dc;
    param_1[0x25] = DAT_007c54dc;
    *param_1 = 4;
  case 5:
    return CONCAT31((int3)(uVar1 >> 8),1);
  default:
    *param_1 = -1;
  case 0:
  case 1:
  case 2:
  case 6:
    return uVar1 & 0xffffff00;
  }
}



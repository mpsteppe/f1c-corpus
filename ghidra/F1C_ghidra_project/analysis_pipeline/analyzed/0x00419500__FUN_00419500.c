// Function: FUN_00419500 @ 00419500
// Size (bytes): 390


void FUN_00419500(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int local_20 [8];
  
  if (((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (DAT_007c56a8 != 8)) {
    FUN_004144d0();
    if ((DAT_007c56a4 == 5) && (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894))) {
      iVar3 = FUN_004d1b50(0);
      if ((-1 < iVar3) &&
         ((iVar3 < 0x68 &&
          (fVar1 = *(float *)(&DAT_005f0780 + (iVar3 * 0x1230 + param_2) * 4), DAT_0059e440 < fVar1)
          ))) {
        fVar2 = *(float *)(param_1 + 0x404c + param_2 * 4);
        if (fVar2 < fVar1 == (fVar2 == fVar1)) {
          if (param_2 == 1) {
            FUN_004144f0(0xd,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          }
          else if (param_2 == 2) {
            FUN_004144f0(0xe,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          }
        }
        else if (param_2 == 1) {
          FUN_004144f0(0x13,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        }
        else if (param_2 == 2) {
          FUN_004144f0(0x14,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        }
      }
      if (local_20[0] != -1) {
        FUN_00418560(local_20);
      }
    }
    if ((param_2 == 2) && (*(int *)(param_1 + 0x3450) == 1)) {
      FUN_0041a170(param_1);
    }
  }
  return;
}



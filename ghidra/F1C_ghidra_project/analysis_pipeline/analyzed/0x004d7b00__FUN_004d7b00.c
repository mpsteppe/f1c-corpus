// Function: FUN_004d7b00 @ 004d7b00
// Size (bytes): 228


void __fastcall FUN_004d7b00(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  do {
    *(undefined4 *)(param_1 + iVar4 * 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc + iVar4 * 4) = 0xffffffff;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  iVar4 = 0;
  do {
    if (iVar4 == 1) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    else if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x18) = DAT_005ea404;
    }
    else {
      *(undefined4 *)(param_1 + 0x18 + iVar4 * 4) = (&DAT_005ea3f8)[iVar4];
    }
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x24 + iVar4 * 4) = (&DAT_005ea3fc)[iVar4];
    iVar6 = DAT_008acff0;
    if (0 < DAT_008acfec) {
      do {
        fVar1 = *(float *)(iVar6 + 4 + iVar5 * 8);
        fVar2 = *(float *)(param_1 + 0x18 + iVar4 * 4);
        if ((fVar2 < fVar1 != (fVar2 == fVar1)) &&
           (fVar2 = *(float *)(param_1 + 0x24 + iVar4 * 4), fVar1 < fVar2 != (fVar1 == fVar2))) {
          iVar3 = *(int *)(param_1 + iVar4 * 4);
          if ((iVar3 == -1) || (fVar1 < *(float *)(iVar6 + 4 + iVar3 * 8))) {
            *(int *)(param_1 + iVar4 * 4) = iVar5;
            iVar6 = DAT_008acff0;
          }
          if ((*(int *)(param_1 + 0xc + iVar4 * 4) == -1) ||
             (*(float *)(iVar6 + 4 + *(int *)(param_1 + iVar4 * 4) * 8) < fVar1)) {
            *(int *)(param_1 + 0xc + iVar4 * 4) = iVar5;
            iVar6 = DAT_008acff0;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_008acfec);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return;
}



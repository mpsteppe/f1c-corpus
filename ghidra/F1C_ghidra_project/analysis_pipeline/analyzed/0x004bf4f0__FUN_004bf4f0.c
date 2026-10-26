// Function: FUN_004bf4f0 @ 004bf4f0
// Size (bytes): 316


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004bf4f0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_005c329c;
  iVar5 = 0;
  DAT_008acfa0 = 1;
  if (0 < DAT_005c329c) {
    do {
      iVar1 = (&DAT_007c54f0)[iVar5];
      if ((*(int *)(iVar1 + 0x4064) != 3) && (*(int *)(iVar1 + 0x4064) != 2)) {
        if (DAT_0059e440 < *(float *)(param_1 + iVar5 * 4)) {
          fVar2 = *(float *)(param_1 + iVar5 * 4) - *(float *)(param_1 + 0x1a0 + iVar5 * 4);
          *(int *)(iVar1 + 0x403c) = *(int *)(iVar1 + 0x403c) + 1;
          fVar3 = fVar2 + *(float *)(param_1 + 0x354);
          if (fVar3 < DAT_0059e440) {
            fVar3 = DAT_0059e440;
          }
          *(float *)(iVar1 + 0x4098) = fVar3;
          *(float *)(iVar1 + 0x40b8) = (*(float *)(param_1 + 0x354) - _DAT_008acf90) + fVar2;
          if (*(int *)(iVar1 + 0x4064) != 3) {
            *(undefined4 *)(iVar1 + 0x4064) = 1;
          }
          FUN_004bf390(iVar1);
        }
        if (*(int *)((&DAT_007c54f0)[iVar5] + 0x4064) == 0) {
          *(undefined4 *)((&DAT_007c54f0)[iVar5] + 0x4064) = 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  _DAT_0083ee5c = &DAT_007d2e54;
  _DAT_0083ee58 = &DAT_007d2e54;
  DAT_0083ee54 = &DAT_007d2e54;
  DAT_007d2e50 = 0;
  _DAT_008aae6c = &DAT_0083ee64;
  _DAT_008aae68 = &DAT_0083ee64;
  DAT_008aae64 = &DAT_0083ee64;
  DAT_0083ee60 = 0;
  return;
}



// Function: FUN_00404250 @ 00404250
// Size (bytes): 519


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404250(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int local_4;
  
  iVar6 = 0;
  iVar7 = 0;
  *(float *)(param_1 + 0x170) = _DAT_0059e43c - (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004fb260(*(undefined4 *)(param_1 + 0x170));
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x130));
  }
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004faf60();
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x130));
  }
  FUN_004047d0();
  FUN_004046b0();
  FUN_00404790();
  *(undefined4 *)(param_1 + 0x174) = 0xffffffff;
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0x134) + 300 + iVar6);
      pfVar8 = (float *)(*(int *)(param_1 + 0x134) + iVar6);
      if ((*(int *)(param_1 + 0x10) <= iVar7) &&
         (pfVar5 = (float *)FUN_004038e0(pfVar8,1), pfVar5 != (float *)0x0)) {
        fVar1 = *pfVar5;
        fVar2 = pfVar5[2];
        fVar3 = pfVar5[8];
        fVar4 = pfVar5[10];
        pfVar8[0x45] = (float)pfVar5;
        pfVar8[6] = fVar3 * (*pfVar8 - fVar1) + fVar4 * (pfVar8[2] - fVar2);
        if (pfVar5[0x43] == 0.0) {
          if (pfVar5[0x44] != 0.0) {
            pfVar8[0x4a] = *(float *)((int)pfVar5[0x44] + 0x120);
          }
        }
        else {
          pfVar8[0x4a] = *(float *)((int)pfVar5[0x43] + 0x124);
        }
      }
      if (((iVar7 == 1) && (pfVar8[0x45] == 0.0)) &&
         (pfVar5 = (float *)FUN_004038e0(pfVar8,0), pfVar5 != (float *)0x0)) {
        fVar1 = pfVar5[8] * (*pfVar8 - *pfVar5) + pfVar5[10] * (pfVar8[2] - pfVar5[2]);
        if (DAT_0059e440 <= fVar1) {
          if (pfVar5[0x15] <= fVar1) goto LAB_00404420;
          pfVar8[0x45] = (float)pfVar5;
          pfVar8[0x4a] = *(float *)((int)pfVar5[0x43] + 0x124);
        }
        else if (pfVar5[0x14] <= -fVar1) {
LAB_00404420:
          pfVar8[0x45] = 0.0;
          pfVar8[0x4a] = -NAN;
        }
        else {
          pfVar8[0x45] = (float)pfVar5;
          pfVar8[0x4a] = *(float *)((int)pfVar5[0x43] + 0x124);
        }
      }
      local_4 = local_4 + 1;
      iVar6 = iVar6 + 0x13c;
    } while (local_4 < *(int *)(param_1 + 0x130));
  }
  return;
}



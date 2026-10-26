// Function: FUN_0056a390 @ 0056a390
// Size (bytes): 573


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056a390(int param_1,double *param_2,double *param_3)

{
  double *pdVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  int local_90;
  int local_8c;
  
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x22c)) {
    local_90 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x230) + local_90;
      iVar2 = *(int *)(iVar8 + 0x30);
      dVar4 = *(double *)(*(int *)(param_1 + 0x230) + 0x28 + local_90) * *(double *)(param_1 + 0x84)
              - *(double *)(iVar8 + 0x20) * *(double *)(param_1 + 0x8c);
      dVar5 = *(double *)(iVar8 + 0x18) * *(double *)(param_1 + 0x8c) -
              *(double *)(iVar8 + 0x28) * *(double *)(param_1 + 0x7c);
      dVar7 = *(double *)(iVar8 + 0x20) * *(double *)(param_1 + 0x7c) -
              *(double *)(iVar8 + 0x18) * *(double *)(param_1 + 0x84);
      pdVar1 = (double *)(*(int *)(param_1 + 0x224) + iVar2 * 8);
      dVar3 = (double)CONCAT44(DAT_005e523c,DAT_005e5238) *
              (*(double *)(param_1 + 4) + *(double *)(iVar8 + 0x18)) +
              (dVar4 + *(double *)(param_1 + 100)) * _DAT_005e5240 +
              (*(double *)(iVar8 + 0x28) * param_2[1] - *(double *)(iVar8 + 0x20) * param_2[2]) +
              *param_3 + (dVar7 * *(double *)(param_1 + 0x84) - dVar5 * *(double *)(param_1 + 0x8c))
      ;
      dVar6 = (double)CONCAT44(DAT_005e523c,DAT_005e5238) *
              (*(double *)(iVar8 + 0x20) + *(double *)(param_1 + 0xc)) +
              (dVar5 + *(double *)(param_1 + 0x6c)) * _DAT_005e5240 +
              (*(double *)(iVar8 + 0x18) * param_2[2] - *(double *)(iVar8 + 0x28) * *param_2) +
              param_3[1] +
              (dVar4 * *(double *)(param_1 + 0x8c) - dVar7 * *(double *)(param_1 + 0x7c));
      dVar4 = (double)CONCAT44(DAT_005e523c,DAT_005e5238) *
              (*(double *)(param_1 + 0x14) + *(double *)(iVar8 + 0x28)) +
              (dVar7 + *(double *)(param_1 + 0x74)) * _DAT_005e5240 +
              (*(double *)(iVar8 + 0x20) * *param_2 - *(double *)(iVar8 + 0x18) * param_2[1]) +
              (dVar5 * *(double *)(param_1 + 0x7c) - dVar4 * *(double *)(param_1 + 0x84)) +
              param_3[2];
      if (*(char *)(iVar8 + 0x34) == '\0') {
        *pdVar1 = dVar3 + *pdVar1;
        pdVar1 = (double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8);
        *pdVar1 = dVar6 + *pdVar1;
        pdVar1 = (double *)(*(int *)(param_1 + 0x224) + 0x10 + iVar2 * 8);
        *pdVar1 = dVar4 + *pdVar1;
      }
      else {
        *pdVar1 = *pdVar1 - dVar3;
        *(double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8) =
             *(double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8) - dVar6;
        *(double *)(*(int *)(param_1 + 0x224) + 0x10 + iVar2 * 8) =
             *(double *)(*(int *)(param_1 + 0x224) + 0x10 + iVar2 * 8) - dVar4;
      }
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x38;
    } while (local_8c < *(int *)(param_1 + 0x22c));
  }
  return;
}



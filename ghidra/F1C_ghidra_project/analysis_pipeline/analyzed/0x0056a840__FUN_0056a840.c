// Function: FUN_0056a840 @ 0056a840
// Size (bytes): 541


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056a840(int param_1,double *param_2,double *param_3)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int local_90;
  int local_8c;
  
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x23c)) {
    local_90 = 0;
    do {
      iVar5 = *(int *)(param_1 + 0x240) + local_90;
      dVar2 = *(double *)(param_1 + 0x84) * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + local_90)
              - *(double *)(param_1 + 0x8c) * *(double *)(iVar5 + 0x20);
      dVar3 = *(double *)(param_1 + 0x8c) * *(double *)(iVar5 + 0x18) -
              *(double *)(param_1 + 0x7c) * *(double *)(iVar5 + 0x28);
      dVar4 = *(double *)(param_1 + 0x7c) * *(double *)(iVar5 + 0x20) -
              *(double *)(param_1 + 0x84) * *(double *)(iVar5 + 0x18);
      dVar2 = ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(iVar5 + 0x18) + *(double *)(param_1 + 4)) + *param_3 +
               (param_2[1] * *(double *)(iVar5 + 0x28) - param_2[2] * *(double *)(iVar5 + 0x20)) +
               (dVar4 * *(double *)(param_1 + 0x84) - dVar3 * *(double *)(param_1 + 0x8c)) +
              (dVar2 + *(double *)(param_1 + 100)) * _DAT_005e5240) * *(double *)(iVar5 + 0x40) +
              ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(param_1 + 0xc) + *(double *)(iVar5 + 0x20)) + param_3[1] +
               (*(double *)(iVar5 + 0x18) * param_2[2] - *param_2 * *(double *)(iVar5 + 0x28)) +
               (dVar2 * *(double *)(param_1 + 0x8c) - dVar4 * *(double *)(param_1 + 0x7c)) +
              (dVar3 + *(double *)(param_1 + 0x6c)) * _DAT_005e5240) * *(double *)(iVar5 + 0x48) +
              ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(param_1 + 0x14) + *(double *)(iVar5 + 0x28)) +
               (*param_2 * *(double *)(iVar5 + 0x20) - *(double *)(iVar5 + 0x18) * param_2[1]) +
               (dVar3 * *(double *)(param_1 + 0x7c) - dVar2 * *(double *)(param_1 + 0x84)) +
               (dVar4 + *(double *)(param_1 + 0x74)) * _DAT_005e5240 + param_3[2]) *
              *(double *)(iVar5 + 0x50);
      if (*(char *)(iVar5 + 0x34) == '\0') {
        *(double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8) =
             dVar2 + *(double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8);
      }
      else {
        pdVar1 = (double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8);
        *pdVar1 = *pdVar1 - (dVar2 - (double)CONCAT44(DAT_005e523c,DAT_005e5238) *
                                     *(double *)(iVar5 + 0x38));
      }
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x58;
    } while (local_8c < *(int *)(param_1 + 0x23c));
  }
  return;
}



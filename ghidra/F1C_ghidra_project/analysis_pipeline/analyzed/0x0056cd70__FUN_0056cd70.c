// Function: FUN_0056cd70 @ 0056cd70
// Size (bytes): 411


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056cd70(int *param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int local_14;
  int local_10;
  
  local_10 = 0;
  iVar5 = 0;
  if (0 < param_4) {
    do {
      iVar3 = *(int *)(*param_1 + 4 + iVar5);
      iVar6 = *(int *)(param_2 + local_10 * 4);
      piVar8 = (int *)(*param_1 + iVar5);
      iVar7 = 0;
      if (*(char *)(iVar3 + 1) != '\0') {
        do {
          uVar9 = (uint)*(byte *)(*(int *)(iVar3 + 4) + iVar7);
          iVar7 = iVar7 + 1;
          *(double *)(iVar5 + iVar6) =
               *(double *)(iVar5 + iVar6) -
               *(double *)(*(int *)(param_2 + uVar9 * 4) + iVar5) * *(double *)(iVar6 + uVar9 * 8);
        } while (iVar7 < (int)(uint)*(byte *)(iVar3 + 1));
      }
      dVar4 = _DAT_0059e420 / *(double *)(iVar5 + iVar6);
      local_14 = 1;
      if (1 < *piVar8) {
        do {
          pbVar1 = (byte *)(piVar8[1] + local_14 * 8);
          iVar3 = *(int *)(param_2 + (uint)*pbVar1 * 4);
          iVar7 = 0;
          if (pbVar1[1] != 0) {
            do {
              pbVar2 = (byte *)(*(int *)(pbVar1 + 4) + iVar7);
              iVar7 = iVar7 + 1;
              *(double *)(iVar5 + iVar3) =
                   *(double *)(iVar5 + iVar3) -
                   *(double *)(*(int *)(param_2 + (uint)*pbVar2 * 4) + iVar5) *
                   *(double *)(iVar3 + (uint)*pbVar2 * 8);
            } while (iVar7 < (int)(uint)pbVar1[1]);
          }
          *(double *)(iVar6 + (uint)*pbVar1 * 8) = dVar4 * *(double *)(iVar5 + iVar3);
          local_14 = local_14 + 1;
        } while (local_14 < *piVar8);
      }
      iVar3 = *(int *)(*param_1 + 4 + param_4 * 8);
      iVar7 = iVar3 + iVar5;
      iVar10 = 0;
      if (*(char *)(iVar3 + 1 + iVar5) != '\0') {
        do {
          uVar9 = (uint)*(byte *)(*(int *)(iVar7 + 4) + iVar10);
          iVar10 = iVar10 + 1;
          *(double *)(iVar5 + param_3) =
               *(double *)(iVar5 + param_3) -
               *(double *)(iVar6 + uVar9 * 8) * *(double *)(param_3 + uVar9 * 8);
        } while (iVar10 < (int)(uint)*(byte *)(iVar7 + 1));
      }
      local_10 = local_10 + 1;
      *(double *)(iVar5 + param_3) = dVar4 * *(double *)(iVar5 + param_3);
      iVar5 = iVar5 + 8;
    } while (local_10 < param_4);
  }
  for (param_4 = param_4 + -2; -1 < param_4; param_4 = param_4 + -1) {
    iVar3 = *(int *)(param_2 + param_4 * 4);
    iVar5 = param_4 * 8;
    iVar6 = param_1[1] + iVar5;
    iVar7 = 0;
    if (*(char *)(param_1[1] + 1 + iVar5) != '\0') {
      do {
        uVar9 = (uint)*(byte *)(*(int *)(iVar6 + 4) + iVar7);
        iVar7 = iVar7 + 1;
        *(double *)(iVar5 + param_3) =
             *(double *)(iVar5 + param_3) -
             *(double *)(iVar3 + uVar9 * 8) * *(double *)(param_3 + uVar9 * 8);
      } while (iVar7 < (int)(uint)*(byte *)(iVar6 + 1));
    }
  }
  return;
}



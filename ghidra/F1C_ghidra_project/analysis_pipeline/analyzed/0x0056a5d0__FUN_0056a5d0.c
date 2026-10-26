// Function: FUN_0056a5d0 @ 0056a5d0
// Size (bytes): 617


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056a5d0(int param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double *pdVar7;
  int iVar8;
  int local_90;
  int local_8c;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined1 local_38 [24];
  undefined1 local_20 [28];
  
  dVar4 = _DAT_005e5240 * *(double *)(param_1 + 0x7c) + *param_2;
  dVar5 = _DAT_005e5240 * *(double *)(param_1 + 0x84) + param_2[1];
  dVar6 = _DAT_005e5240 * *(double *)(param_1 + 0x8c) + param_2[2];
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x234)) {
    local_90 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x238) + local_90;
      iVar1 = *(int *)(iVar8 + 0x78);
      iVar2 = *(int *)(iVar8 + 0x7c);
      dVar3 = (*(double *)(*(int *)(param_1 + 0x238) + 0x70 + local_90) * *(double *)(iVar8 + 0x50)
              - *(double *)(iVar8 + 0x68) * *(double *)(iVar8 + 0x58)) * *(double *)(param_1 + 0x7c)
              + (*(double *)(iVar8 + 0x60) * *(double *)(iVar8 + 0x58) -
                *(double *)(iVar8 + 0x70) * *(double *)(iVar8 + 0x48)) * *(double *)(param_1 + 0x84)
                + (*(double *)(iVar8 + 0x68) * *(double *)(iVar8 + 0x48) -
                  *(double *)(iVar8 + 0x60) * *(double *)(iVar8 + 0x50)) *
                  *(double *)(param_1 + 0x8c);
      local_40 = *(double *)(iVar8 + 0x48) * *(double *)(param_1 + 0x7c) +
                 *(double *)(param_1 + 0x84) * *(double *)(iVar8 + 0x50) +
                 *(double *)(param_1 + 0x8c) * *(double *)(iVar8 + 0x58);
      local_48 = *(double *)(iVar8 + 0x60) * *(double *)(param_1 + 0x7c) +
                 *(double *)(iVar8 + 0x68) * *(double *)(param_1 + 0x84) +
                 *(double *)(iVar8 + 0x70) * *(double *)(param_1 + 0x8c);
      if (*(char *)(iVar8 + 0x80) == '\0') {
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + iVar2 * 8);
        *pdVar7 = ((dVar5 * *(double *)(iVar8 + 0x50) +
                   dVar6 * *(double *)(iVar8 + 0x58) + dVar4 * *(double *)(iVar8 + 0x48)) -
                  local_48 * dVar3) + *pdVar7;
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8);
        dVar3 = local_40 * dVar3 +
                dVar4 * *(double *)(iVar8 + 0x60) +
                dVar5 * *(double *)(iVar8 + 0x68) + dVar6 * *(double *)(iVar8 + 0x70) + *pdVar7;
      }
      else {
        FUN_00435e00(iVar8,local_38);
        FUN_00435e00(*(undefined4 *)(iVar1 + 0x10),local_20);
        FUN_0056c540(&local_60);
        local_60 = local_60 * _DAT_005e5238;
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + iVar2 * 8);
        local_58 = local_58 * _DAT_005e5238;
        local_50 = local_50 * _DAT_005e5238;
        *pdVar7 = *pdVar7 - (((local_58 + dVar5) * *(double *)(iVar8 + 0x50) +
                             (local_50 + dVar6) * *(double *)(iVar8 + 0x58) +
                             (local_60 + dVar4) * *(double *)(iVar8 + 0x48)) - local_48 * dVar3);
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8);
        dVar3 = *pdVar7 - (local_40 * dVar3 +
                          (local_60 + dVar4) * *(double *)(iVar8 + 0x60) +
                          (local_58 + dVar5) * *(double *)(iVar8 + 0x68) +
                          (local_50 + dVar6) * *(double *)(iVar8 + 0x70));
      }
      *pdVar7 = dVar3;
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x84;
    } while (local_8c < *(int *)(param_1 + 0x234));
  }
  return;
}



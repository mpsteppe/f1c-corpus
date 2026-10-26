// Function: FUN_0056baf0 @ 0056baf0
// Size (bytes): 582


void __fastcall FUN_0056baf0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  double dVar5;
  int iVar6;
  double *pdVar7;
  int iVar8;
  int iVar9;
  int local_88;
  int local_84;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_28;
  double local_20;
  
  if (0 < *(int *)(param_1 + 0x23c)) {
    local_88 = 0;
    iVar8 = 1;
    do {
      iVar9 = *(int *)(param_1 + 0x240) + local_88;
      cVar1 = *(char *)(iVar9 + 0x34);
      iVar2 = *(int *)(iVar9 + 0x30);
      local_50 = *(double *)(*(int *)(param_1 + 0x240) + 0x20 + local_88) *
                 *(double *)(iVar9 + 0x50) - *(double *)(iVar9 + 0x28) * *(double *)(iVar9 + 0x48);
      local_48 = *(double *)(iVar9 + 0x40) * *(double *)(iVar9 + 0x28) -
                 *(double *)(iVar9 + 0x18) * *(double *)(iVar9 + 0x50);
      local_40 = *(double *)(iVar9 + 0x18) * *(double *)(iVar9 + 0x48) -
                 *(double *)(iVar9 + 0x40) * *(double *)(iVar9 + 0x20);
      FUN_00435e00(&local_50,&local_80);
      local_58 = *(double *)(param_1 + 0xb4);
      local_68 = local_58 * *(double *)(iVar9 + 0x40);
      pdVar7 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + iVar2 * 8);
      local_60 = local_58 * *(double *)(iVar9 + 0x48);
      local_58 = local_58 * *(double *)(iVar9 + 0x50);
      local_28 = local_80 * *(double *)(iVar9 + 0x20) - local_78 * *(double *)(iVar9 + 0x18);
      local_20 = (local_78 * *(double *)(iVar9 + 0x28) - local_70 * *(double *)(iVar9 + 0x20)) +
                 local_68;
      *pdVar7 = ((local_70 * *(double *)(iVar9 + 0x18) - local_80 * *(double *)(iVar9 + 0x28)) +
                local_60) * *(double *)(iVar9 + 0x48) +
                (local_58 + local_28) * *(double *)(iVar9 + 0x50) +
                local_20 * *(double *)(iVar9 + 0x40) + *pdVar7;
      iVar9 = iVar8;
      local_84 = local_88;
      if (iVar8 < *(int *)(param_1 + 0x23c)) {
        do {
          local_84 = local_84 + 0x58;
          iVar6 = *(int *)(param_1 + 0x240) + local_84;
          local_28 = local_80 * *(double *)(iVar6 + 0x20) - local_78 * *(double *)(iVar6 + 0x18);
          local_20 = (local_78 * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + local_84) -
                     local_70 * *(double *)(iVar6 + 0x20)) + local_68;
          iVar3 = *(int *)(iVar6 + 0x30);
          dVar5 = local_20 * *(double *)(iVar6 + 0x40) +
                  ((local_70 * *(double *)(iVar6 + 0x18) - local_80 * *(double *)(iVar6 + 0x28)) +
                  local_60) * *(double *)(iVar6 + 0x48) +
                  (local_58 + local_28) * *(double *)(iVar6 + 0x50);
          if (*(char *)(iVar6 + 0x34) == cVar1) {
            if (iVar3 < iVar2) {
              pdVar7 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + iVar3 * 8);
            }
            else {
              pdVar7 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + iVar2 * 8);
            }
            *pdVar7 = dVar5 + *pdVar7;
          }
          else if (iVar3 < iVar2) {
            iVar6 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
            *(double *)(iVar6 + iVar3 * 8) = *(double *)(iVar6 + iVar3 * 8) - dVar5;
          }
          else {
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
            *(double *)(iVar3 + iVar2 * 8) = *(double *)(iVar3 + iVar2 * 8) - dVar5;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < *(int *)(param_1 + 0x23c));
      }
      local_88 = local_88 + 0x58;
      bVar4 = iVar8 < *(int *)(param_1 + 0x23c);
      iVar8 = iVar8 + 1;
    } while (bVar4);
  }
  return;
}



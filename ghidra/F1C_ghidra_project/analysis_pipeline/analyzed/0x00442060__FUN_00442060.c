// Function: FUN_00442060 @ 00442060
// Size (bytes): 833


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00442060(int param_1,int param_2,float param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  int local_3c;
  int local_38;
  double local_20;
  double local_18;
  double local_10;
  
  param_3 = param_3 * (float)_DAT_0059ed78;
  iVar1 = param_2 * 0x464 + 0x28c + param_1;
  *(undefined1 *)(iVar1 + 0x1c5) = 1;
  uVar6 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar2 = *(float *)(&DAT_008aae74 + uVar6 * 4);
  fVar10 = (float10)_DAT_0059e890;
  fVar9 = (float10)fsin((float10)fVar2 * fVar10);
  if ((param_2 == 0) || (param_2 == 3)) {
    *(double *)(iVar1 + 0x1d0) =
         (double)(fVar9 * (float10)param_3 + (float10)*(double *)(iVar1 + 0x1d0));
  }
  else {
    *(double *)(iVar1 + 0x1d0) =
         (double)((float10)*(double *)(iVar1 + 0x1d0) - fVar9 * (float10)param_3);
  }
  if (_DAT_0059ed70 <= *(double *)(iVar1 + 0x1d0)) {
    if (_DAT_0059ed68 < *(double *)(iVar1 + 0x1d0)) {
      *(undefined4 *)(iVar1 + 0x1d4) = 0x3fc65718;
      goto LAB_00442130;
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0x1d4) = 0xbfc65718;
LAB_00442130:
    *(undefined4 *)(iVar1 + 0x1d0) = 0x4ae74487;
  }
  fVar10 = (float10)fcos((float10)fVar2 * fVar10);
  *(double *)(iVar1 + 0x1d8) =
       (double)(fVar10 * (float10)param_3 + (float10)*(double *)(iVar1 + 0x1d8));
  if (_DAT_0059ed70 <= *(double *)(iVar1 + 0x1d8)) {
    if (*(double *)(iVar1 + 0x1d8) <= _DAT_0059ed68) goto LAB_00442182;
    *(undefined4 *)(iVar1 + 0x1dc) = 0x3fc65718;
  }
  else {
    *(undefined4 *)(iVar1 + 0x1dc) = 0xbfc65718;
  }
  *(undefined4 *)(iVar1 + 0x1d8) = 0x4ae74487;
LAB_00442182:
  FUN_00441450();
  local_3c = 0;
  if (0 < *(int *)(param_1 + 0x15bc)) {
    local_38 = 0;
    do {
      iVar3 = *(int *)(iVar1 + 0x15c);
      iVar5 = *(int *)(param_1 + 0x15c0) + local_38;
      if (*(int *)(*(int *)(param_1 + 0x15c0) + 4 + local_38) == iVar3) {
        iVar7 = *(int *)(iVar5 + 8);
        iVar5 = *(int *)(iVar5 + 0x10);
LAB_004421d2:
        if ((iVar7 != 0) && (iVar5 != 0)) {
          iVar8 = *(int *)(iVar1 + 0x160);
          if (((local_38 == 0x60) || (local_38 == 0x90)) && (*(int *)(param_1 + 0x141c) != 0)) {
            iVar8 = *(int *)(param_1 + 0x141c);
          }
          FUN_00435e00(iVar7,&local_20);
          FUN_004388d0(&local_20,iVar5);
          FUN_00435e00(iVar7 + 0x18,&local_20);
          *(double *)(iVar5 + 0x18) =
               local_20 * *(double *)(iVar8 + 0x1c) +
               local_18 * *(double *)(iVar8 + 0x34) + local_10 * *(double *)(iVar8 + 0x4c);
          *(double *)(iVar5 + 0x20) =
               local_20 * *(double *)(iVar8 + 0x24) +
               local_18 * *(double *)(iVar8 + 0x3c) + local_10 * *(double *)(iVar8 + 0x54);
          *(double *)(iVar5 + 0x28) =
               local_20 * *(double *)(iVar8 + 0x2c) +
               local_18 * *(double *)(iVar8 + 0x44) + local_10 * *(double *)(iVar8 + 0x5c);
          local_20 = *(double *)(iVar3 + 0x1c) * *(double *)(iVar7 + 0x30) +
                     *(double *)(iVar3 + 0x24) * *(double *)(iVar7 + 0x38) +
                     *(double *)(iVar3 + 0x2c) * *(double *)(iVar7 + 0x40);
          local_18 = *(double *)(iVar3 + 0x34) * *(double *)(iVar7 + 0x30) +
                     *(double *)(iVar3 + 0x3c) * *(double *)(iVar7 + 0x38) +
                     *(double *)(iVar3 + 0x44) * *(double *)(iVar7 + 0x40);
          local_10 = *(double *)(iVar3 + 0x4c) * *(double *)(iVar7 + 0x30) +
                     *(double *)(iVar3 + 0x54) * *(double *)(iVar7 + 0x38) +
                     *(double *)(iVar3 + 0x5c) * *(double *)(iVar7 + 0x40);
          *(double *)(iVar5 + 0x30) =
               local_20 * *(double *)(iVar8 + 0x1c) +
               local_18 * *(double *)(iVar8 + 0x34) + local_10 * *(double *)(iVar8 + 0x4c);
          *(double *)(iVar5 + 0x38) =
               local_20 * *(double *)(iVar8 + 0x24) +
               local_18 * *(double *)(iVar8 + 0x3c) + local_10 * *(double *)(iVar8 + 0x54);
          *(double *)(iVar5 + 0x40) =
               local_20 * *(double *)(iVar8 + 0x2c) +
               local_18 * *(double *)(iVar8 + 0x44) + local_10 * *(double *)(iVar8 + 0x5c);
          FUN_0056d020();
        }
      }
      else if (*(int *)(iVar5 + 0xc) == iVar3) {
        iVar7 = *(int *)(iVar5 + 0x10);
        iVar5 = *(int *)(iVar5 + 8);
        goto LAB_004421d2;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 0x30;
    } while (local_3c < *(int *)(param_1 + 0x15bc));
  }
  dVar4 = (double)param_3 + *(double *)(iVar1 + 0x1e0);
  *(double *)(iVar1 + 0x1e0) = dVar4;
  if ((_DAT_0059ed60 < dVar4) && (*(int *)(*(int *)(param_1 + 0x1f00) + 0x4068) == 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x1f00) + 0x4068) = 4;
  }
  return;
}



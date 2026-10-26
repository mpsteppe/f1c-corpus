// Function: FUN_0044a2d0 @ 0044a2d0
// Size (bytes): 346


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0044a2d0(undefined4 *param_1,float param_2,int param_3,float param_4,float param_5,
            undefined4 param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_38 [6];
  float local_20;
  undefined4 local_1c [6];
  float local_4;
  
  iVar8 = 0;
  if (param_2 != 0.0) {
    fVar4 = param_2;
    pfVar5 = (float *)(param_3 + 8);
    do {
      param_2 = 3.4028235e+38;
      iVar6 = 0;
      fVar2 = _DAT_0059ef30;
      do {
        pfVar1 = *(float **)((int)fVar4 + iVar6 * 8);
        fVar3 = param_4 * *pfVar1 + param_5 * pfVar1[3];
        if (fVar3 < param_2) {
          param_2 = fVar3;
        }
        if (fVar2 < fVar3) {
          fVar2 = fVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      *pfVar5 = fVar2;
      pfVar5[-2] = fVar4;
      pfVar5[-1] = param_2;
      iVar8 = iVar8 + 1;
      pfVar5[1] = (fVar2 + param_2) * _DAT_0059e450;
      fVar4 = *(float *)((int)fVar4 + 0x1c);
      pfVar5 = pfVar5 + 4;
    } while (fVar4 != 0.0);
  }
  FUN_005890aa(param_3,iVar8,0x10,&LAB_0044a130);
  iVar6 = iVar8 / 2;
  iVar7 = (iVar8 + 1) / 2;
  if (iVar6 != iVar7) {
    FUN_0044a170(param_3,iVar6,iVar8,0);
    FUN_0044a170(param_3,iVar7,iVar8,0);
    if (local_4 <= local_20) {
      if ((char)param_6 == '\0') {
        puVar9 = local_1c;
        for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
          *param_1 = *puVar9;
          puVar9 = puVar9 + 1;
          param_1 = param_1 + 1;
        }
        return;
      }
      FUN_0044a170(param_3,iVar7,iVar8,1);
      return;
    }
    if ((char)param_6 == '\0') {
      puVar9 = local_38;
      for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
        *param_1 = *puVar9;
        puVar9 = puVar9 + 1;
        param_1 = param_1 + 1;
      }
      return;
    }
    param_6 = 1;
  }
  FUN_0044a170(param_3,iVar6,iVar8,param_6);
  return;
}



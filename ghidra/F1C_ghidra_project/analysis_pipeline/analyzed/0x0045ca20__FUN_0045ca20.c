// Function: FUN_0045ca20 @ 0045ca20
// Size (bytes): 460


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_0045ca20(int param_1,int param_2,float *param_3,float param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined4 local_20 [8];
  
  if ((&DAT_005ef9a0)[param_2 * 0x1230] != 2) {
    *param_3 = 0.0;
    return true;
  }
  uVar8 = FUN_0045c780(param_2);
  iVar3 = (int)((ulonglong)uVar8 >> 0x20);
  iVar2 = (int)uVar8;
  if (iVar2 == 0) {
    *param_3 = 9.999;
    return false;
  }
  if (DAT_0059e440 < *(float *)(param_1 + 0x1124 + iVar3 * 4)) {
    *param_3 = *(float *)(param_1 + 0x1124 + iVar3 * 4);
    return true;
  }
  bVar7 = iVar2 == 0x10;
  if ((param_4._0_1_ != '\0') && (!bVar7)) {
    *param_3 = 9.999;
    return bVar7;
  }
  puVar5 = (undefined4 *)(iVar3 * 0x20 + 0x424 + param_1);
  puVar6 = local_20;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_005890aa(local_20,iVar2,2,&LAB_0045c760);
  param_4 = (float)__ftol();
  fVar1 = _DAT_0059e43c / (float)(int)param_4;
  iVar3 = (iVar2 - (int)param_4) / 2;
  iVar2 = iVar3 + (int)param_4;
  *param_3 = 0.0;
  for (; iVar3 < iVar2; iVar3 = iVar3 + 1) {
    uVar8 = FUN_0045c7c0(*(undefined2 *)((int)local_20 + iVar3 * 2),&param_4);
    param_3 = (float *)((ulonglong)uVar8 >> 0x20);
    *param_3 = param_4 * fVar1 + *param_3;
  }
  if (bVar7) {
    *(float *)(param_1 + 0x1124 + param_2 * 4) = *param_3;
    if ((*param_3 <= DAT_007d108c) && (DAT_0059e440 <= *param_3)) {
      FUN_0045c7a0(0,param_1 + 0x12c4 + param_2 * 2);
      return true;
    }
    FUN_0045c7a0(DAT_007d108c * _DAT_0059e7f8 - *param_3,param_1 + 0x12c4 + param_2 * 2);
  }
  return bVar7;
}



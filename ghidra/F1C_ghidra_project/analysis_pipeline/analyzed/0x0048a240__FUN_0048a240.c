// Function: FUN_0048a240 @ 0048a240
// Size (bytes): 362


undefined4 __thiscall FUN_0048a240(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_c;
  int local_8;
  int local_4;
  
  local_8 = *(int *)(param_1 + 4);
  local_4 = *(int *)(param_1 + 8);
  piVar4 = param_5;
  piVar6 = param_2;
  piVar7 = param_3;
  if ((0 < *(int *)(param_1 + 0x160)) &&
     (piVar1 = (int *)FUN_00486460(3), piVar4 = param_5, piVar6 = param_2, piVar7 = param_3,
     piVar1 != (int *)0x0)) {
    local_c = piVar1[1] - *piVar1;
    iVar5 = piVar1[3] - piVar1[2];
    iVar2 = FUN_00487060(0);
    iVar3 = FUN_004870e0(0);
    iVar3 = iVar3 + *(int *)(param_1 + 0x150);
    if (iVar3 < local_8) {
      iVar3 = local_8;
    }
    if (local_4 - iVar5 < iVar3) {
      iVar3 = local_4 - iVar5;
    }
    local_8 = iVar2 + local_c;
    local_4 = iVar3 + iVar5;
    FUN_004868c0(3,0,iVar3,local_4,iVar2,local_8);
    iVar8 = iVar2;
    iVar9 = iVar3;
    iVar10 = local_c;
    FUN_00490920(iVar2,iVar3,local_c,iVar5);
    FUN_004918d0(iVar8,iVar9,iVar10,iVar5);
    *param_2 = iVar3;
    *param_3 = local_4;
    *param_4 = iVar2;
    *param_5 = local_8;
    piVar4 = param_5;
    piVar6 = param_2;
    piVar7 = param_3;
  }
  param_3 = (int *)0x0;
  local_c = 0;
  param_5 = (int *)0x258;
  param_2 = (int *)0x320;
  FUN_00489fd0(&param_5,&param_3,&param_2,&local_c);
  iVar3 = *piVar6;
  if ((int)param_5 <= *piVar6) {
    iVar3 = (int)param_5;
  }
  *piVar6 = iVar3;
  iVar3 = *piVar7;
  if (*piVar7 <= (int)param_3) {
    iVar3 = (int)param_3;
  }
  *piVar7 = iVar3;
  iVar3 = *param_4;
  if ((int)param_2 <= *param_4) {
    iVar3 = (int)param_2;
  }
  *param_4 = iVar3;
  if (*piVar4 <= local_c) {
    *piVar4 = local_c;
    return 0;
  }
  *piVar4 = *piVar4;
  return 0;
}



// Function: FUN_005813e0 @ 005813e0
// Size (bytes): 542


uint __thiscall FUN_005813e0(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  DWORD DVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined2 local_38;
  u_short local_36;
  u_long local_34;
  undefined1 local_28 [20];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cb33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00587030(0xffffffff,0xff,0);
  local_4 = 0;
  FUN_00587310(param_2);
  iVar7 = 0;
  piVar6 = (int *)0x0;
  if ((*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) &&
     ((DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar1 == 0 || (DVar1 == 0x80)))) {
    piVar6 = (int *)(param_1 + 0xac8);
  }
  piVar3 = (int *)*piVar6;
  piVar6[2] = (int)piVar3;
  if ((piVar3 != (int *)0x0) && (iVar4 = *piVar3, iVar4 != 0)) {
    while( true ) {
      if (*(int *)(iVar4 + 0x14) == local_14) {
        iVar7 = iVar4;
      }
      if (piVar6[2] == 0) break;
      piVar3 = *(int **)(piVar6[2] + 4);
      piVar6[2] = (int)piVar3;
      if ((piVar3 == (int *)0x0) || (iVar4 = *piVar3, iVar4 == 0)) break;
    }
    if (iVar7 != 0) {
      FUN_0057b820(local_28);
      goto LAB_00581558;
    }
  }
  pvVar2 = operator_new(0x20);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_0057b7d0(local_28);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (iVar7 != 0) {
    piVar3 = operator_new(0xc);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = iVar7;
      piVar3[1] = 0;
      *(undefined1 *)(piVar3 + 2) = 1;
    }
    if (*piVar6 == 0) {
      *piVar6 = (int)piVar3;
      piVar6[2] = (int)piVar3;
    }
    else {
      *(int **)(piVar6[1] + 4) = piVar3;
    }
    piVar6[1] = (int)piVar3;
    piVar6[3] = piVar6[3] + 1;
  }
  iVar4 = FUN_00587220();
  if ((iVar4 == 2) && (param_4 != '\0')) {
    local_38 = 2;
    local_34 = htonl(0);
    local_36 = htons(0);
    FUN_0057b9f0(&local_38);
    FUN_0057dd40(&local_38,iVar7);
  }
LAB_00581558:
  FUN_00587230(param_3);
  iVar4 = FUN_00585d20();
  if ((iVar4 == 3) && (iVar4 = FUN_00587220(), iVar4 == 2)) {
    local_38 = 2;
    local_34 = htonl(0);
    local_36 = htons(0);
    FUN_0057b9f0(&local_38);
    FUN_0057dd40(&local_38,iVar7);
  }
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  local_4 = 0xffffffff;
  uVar5 = FUN_005870d0();
  ExceptionList = local_c;
  return uVar5 & 0xffffff00;
}



// Function: FUN_00540250 @ 00540250
// Size (bytes): 631


undefined4 __thiscall
FUN_00540250(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,int param_8,int param_9,int param_10)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_8;
  
  bVar3 = param_10 == -2;
  local_44 = (int *)0x0;
  local_48 = (int *)0x0;
  local_40 = (int *)0x0;
  local_3c = (int *)0x0;
  if ((8 < *(int *)(param_2 + 0x30)) || (8 < *(int *)(param_5 + 0x30))) {
    bVar3 = true;
  }
  uVar1 = *(uint *)(param_2 + 0x18);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) != 0) {
      local_44 = *(int **)(param_2 + 0xc);
      goto LAB_005402ac;
    }
LAB_005402b4:
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) goto LAB_005402f4;
      local_40 = *(int **)(param_2 + 0x14);
    }
    else {
      local_40 = *(int **)(param_2 + 0x10);
    }
    if (local_40 != (int *)0x0) {
      iVar2 = (**(code **)(*local_40 + 0x3c))(local_40,0,&local_44);
      *param_1 = iVar2;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  else {
    local_44 = *(int **)(param_2 + 8);
LAB_005402ac:
    if (local_44 == (int *)0x0) goto LAB_005402b4;
  }
LAB_005402f4:
  uVar1 = *(uint *)(param_5 + 0x18);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) != 0) {
      local_48 = *(int **)(param_5 + 0xc);
    }
  }
  else {
    local_48 = *(int **)(param_5 + 8);
  }
  if (local_48 == (int *)0x0) {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) goto LAB_0054035a;
      local_3c = *(int **)(param_5 + 0x14);
    }
    else {
      local_3c = *(int **)(param_5 + 0x10);
    }
    if (local_3c != (int *)0x0) {
      iVar2 = (**(code **)(*local_3c + 0x3c))(local_3c,0,&local_48);
      *param_1 = iVar2;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
LAB_0054035a:
  if (bVar3) {
    iStack_30 = param_3;
    iStack_28 = param_3 + param_8;
    piVar7 = &iStack_38;
    iStack_2c = param_4;
    iStack_24 = param_4 + param_9;
    uStack_34 = param_7;
    iStack_38 = param_6;
    piVar6 = local_48;
    iVar2 = (**(code **)(*(int *)param_1[0x440] + 0x70))
                      ((int *)param_1[0x440],local_44,&iStack_30,1);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  else {
    iStack_1c = param_4;
    iStack_14 = param_4 + param_9;
    piVar7 = (int *)0x10;
    piVar6 = &iStack_20;
    iStack_20 = param_3;
    iStack_18 = param_3 + param_8;
    piVar5 = &iStack_30;
    iVar2 = (**(code **)(*local_44 + 0x24))(local_44);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iStack_1c = param_3;
    iStack_14 = param_3 + param_9;
    piVar4 = (int *)0x0;
    iStack_20 = param_2;
    iStack_18 = param_2 + param_8;
    iVar2 = (**(code **)(*unaff_EDI + 0x24))(unaff_EDI,&local_48,&iStack_20);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    FUN_005401a0(unaff_EBX,unaff_EBP,unaff_ESI,unaff_EDI,param_8,param_9,param_2,
                 *(undefined4 *)(param_2 + 0x30));
    (**(code **)(*piVar5 + 0x28))(piVar5);
    (**(code **)(*piVar4 + 0x28))(piVar4);
  }
  if (unaff_EDI != (int *)0x0) {
    iVar2 = (**(code **)(*piVar7 + 8))(piVar7);
    *param_1 = iVar2;
  }
  if (unaff_ESI != 0) {
    iVar2 = (**(code **)(*piVar6 + 8))(piVar6);
    *param_1 = iVar2;
  }
  *(uint *)(iStack_8 + 0x18) = *(uint *)(iStack_8 + 0x18) & 0xfffffbff;
  return 0;
}



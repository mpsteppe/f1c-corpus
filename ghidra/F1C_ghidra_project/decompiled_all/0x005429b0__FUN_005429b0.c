// Function: FUN_005429b0 @ 005429b0
// Strings:  [%s_MIP%.2d%s]


undefined4 __thiscall
FUN_005429b0(int param_1,char *param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  char local_610 [14];
  char acStack_602 [770];
  undefined1 local_300 [768];
  
  if ((param_6 & 0xf) == 0) {
    return 0;
  }
  pvVar3 = operator_new(0x3c);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005426a0();
  }
  uVar5 = param_6 & 0x800;
  if (uVar5 != 0) {
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 0x800;
    FUN_005435c0(*(undefined4 *)(param_1 + 0x34));
  }
  uVar10 = param_6 & 0x800000;
  if (uVar10 != 0) {
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 0x800000;
  }
  if ((param_6 & 0x4000) == 0) {
    *(int *)(iVar4 + 0x1c) = param_3;
    *(int *)(iVar4 + 0x20) = param_4;
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 1;
    if (((param_6 & 0x1000000) == 0) && (iVar6 = FUN_00542ec0(param_2), iVar6 != 0))
    goto LAB_00542dfd;
  }
  else {
    iVar6 = 2 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)(acStack_602 + iVar6)] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(acStack_602 + 2);
    pvVar3 = operator_new(0x3c);
    if (pvVar3 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_005426a0();
    }
    if (uVar5 != 0) {
      *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 0x800;
      FUN_005435c0(*(undefined4 *)(param_1 + 0x34));
    }
    if (uVar10 != 0) {
      *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 0x800000;
    }
    *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 1;
    iVar7 = FUN_00542ec0(acStack_602 + 2);
    if (iVar7 != 0) {
LAB_00542aad:
      FUN_00557470();
      FUN_00587bcf(iVar6);
      return 0xffffffff;
    }
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 4;
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar6 + 0x1c);
    *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar6 + 0x20);
    *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(iVar6 + 0x30);
    uVar2 = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar4 + 0x2c) = uVar2;
    iVar7 = FUN_0053f720(iVar4,uVar2);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    iVar7 = FUN_0053fc30(iVar6,iVar4,0);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    FUN_00542e50();
    uVar9 = 0xffffffff;
    pcVar11 = acStack_602 + 2;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    cVar1 = acStack_602[~uVar9];
    for (iVar7 = ~uVar9 - 2; (cVar1 != '.' && (iVar7 != 0)); iVar7 = iVar7 + -1) {
      cVar1 = acStack_602[iVar7 + 1];
    }
    pcVar11 = acStack_602 + iVar7 + 2;
    pcVar8 = pcVar11;
    do {
      cVar1 = *pcVar8;
      pcVar8[(int)(local_610 + -(int)pcVar11)] = cVar1;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    iVar7 = *(int *)(param_1 + 0x2c);
    iVar12 = 1;
    *pcVar11 = '\0';
    if (1 < iVar7) {
      do {
        if (uVar5 != 0) {
          *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 0x800;
          FUN_005435c0(*(undefined4 *)(param_1 + 0x34));
        }
        if (uVar10 != 0) {
          *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 0x800000;
        }
        *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 1;
        FUN_0058815f(local_300,s__s_MIP__2d_s_005dbdb4,acStack_602 + 2,iVar12,local_610);
        iVar7 = FUN_00542ec0(local_300);
        if (iVar7 != 0) goto LAB_00542aad;
        iVar7 = FUN_0053fc30(iVar6,iVar4,iVar12);
        if (iVar7 != 0) {
          return 0xffffffff;
        }
        FUN_00542e50();
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(int *)(param_1 + 0x2c));
    }
    FUN_00557470();
    FUN_00587bcf(iVar6);
  }
  if (uVar5 != 0) {
    FUN_005435c0(0);
  }
  if (*(int *)(iVar4 + 0x30) == 8) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x800000;
    param_5 = 8;
  }
  iVar6 = FUN_005426e0(param_5,param_6);
  if (iVar6 != 0) {
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(iVar4);
    return 0xffffffff;
  }
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);
  }
  else {
    *(int *)(param_1 + 0x1c) = param_3;
  }
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar4 + 0x20);
  }
  else {
    *(int *)(param_1 + 0x20) = param_4;
  }
  *(uint *)(param_1 + 0x18) = param_6;
  uVar5 = *(uint *)(iVar4 + 0x18) & 0xf;
  if (((param_6 & 1) != 0) &&
     (iVar6 = FUN_0053fd40(iVar4,uVar5,param_1,1,param_6 & 0x1000000), iVar6 != 0)) {
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(iVar4);
    return 0xffffffff;
  }
  if (((*(byte *)(param_1 + 0x18) & 2) != 0) &&
     (iVar6 = FUN_0053fd40(iVar4,uVar5,param_1,2,param_6 & 0x1000000), iVar6 != 0)) {
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(iVar4);
    return 0xffffffff;
  }
  if (((*(byte *)(param_1 + 0x18) & 4) != 0) &&
     (iVar6 = FUN_0053fd40(iVar4,uVar5,param_1,4,param_6 & 0x1000000), iVar6 != 0)) {
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(iVar4);
    return 0xffffffff;
  }
  if (((*(byte *)(param_1 + 0x18) & 8) == 0) ||
     (iVar6 = FUN_0053fd40(iVar4,uVar5,param_1,8,param_6 & 0x1000000), iVar6 == 0)) {
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(iVar4);
    return 0;
  }
  FUN_00542e50();
LAB_00542dfd:
  FUN_00557470();
  FUN_00587bcf(iVar4);
  return 0xffffffff;
}



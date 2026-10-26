// Function: FUN_0053fed0 @ 0053fed0
// Size (bytes): 377


undefined4 __thiscall
FUN_0053fed0(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint param_5,
            int param_6)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_20;
  int local_1c;
  int local_18;
  undefined4 local_c;
  
  piVar1 = param_4;
  local_20 = 0;
  if ((param_4[6] & 0x800U) == 0) {
    if ((param_4[6] & 0x800000U) != 0) goto LAB_0053ff0e;
  }
  else if (param_4[0xd] != 0) {
    local_20 = param_4[0xd] | 0xff000000;
    goto LAB_0053ff0e;
  }
  local_20 = 0xffff00ff;
LAB_0053ff0e:
  iVar3 = FUN_005006d5(param_2,param_3,&local_1c);
  iVar4 = param_6;
  uVar2 = param_5;
  *param_1 = iVar3;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (param_6 == 0) {
    piVar1[8] = local_18;
    piVar1[7] = local_1c;
    piVar1[6] = piVar1[6] | param_5;
    FUN_0055c450(local_c,piVar1 + 9,piVar1 + 0xc);
    iVar3 = FUN_0053f720(piVar1,piVar1[0xb]);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  if (uVar2 == 4) {
    iVar4 = (**(code **)(*(int *)piVar1[4] + 0x3c))((int *)piVar1[4],iVar4,&param_4);
    *param_1 = iVar4;
    if (iVar4 != 0) {
      return 0xffffffff;
    }
  }
  else if (uVar2 == 8) {
    iVar4 = (**(code **)(*(int *)piVar1[5] + 0x3c))((int *)piVar1[5],iVar4,&param_4);
    *param_1 = iVar4;
    if (iVar4 != 0) {
      return 0xffffffff;
    }
  }
  else if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) != 0) {
      param_4 = (int *)piVar1[3];
    }
  }
  else {
    param_4 = (int *)piVar1[2];
  }
  iVar4 = FUN_005008e4(param_4,0,0,param_2,param_3,0,1,local_20,&local_1c);
  *param_1 = iVar4;
  if (iVar4 != 0) {
    return 0xffffffff;
  }
  if ((uVar2 == 4) || (uVar2 == 8)) {
    (**(code **)(*param_4 + 8))(param_4);
  }
  return 0;
}



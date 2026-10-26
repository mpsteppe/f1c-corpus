// Function: FUN_00405160 @ 00405160
// Size (bytes): 273


int FUN_00405160(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  int local_4;
  
  if (param_3 == 0) {
LAB_00405182:
    sVar4 = 0;
  }
  else if (param_3 == 1) {
    sVar4 = 1;
  }
  else {
    if (param_3 != 2) goto LAB_00405182;
    sVar4 = 2;
  }
  uVar5 = 0;
  param_3 = 0;
  local_4 = 0;
  uVar8 = param_1;
  FUN_00404fe0(0,param_1);
  iVar2 = FUN_00407e40(uVar5,uVar8);
  if (iVar2 == 0) {
    uVar8 = param_1;
    FUN_00404fe0(param_1);
    cVar1 = FUN_00407fb0(uVar8);
    if (cVar1 != '\0') {
      piVar7 = &local_4;
      puVar6 = &param_3;
      uVar8 = param_1;
      FUN_00404fe0(param_1,puVar6,piVar7);
      cVar1 = FUN_00408050(uVar8,puVar6,piVar7);
      if (cVar1 != '\0') goto LAB_004051e6;
    }
    iVar2 = FUN_0058c724(param_1,param_2,sVar4);
  }
  else {
    param_3 = *(int *)(iVar2 + 0x28);
    local_4 = *(int *)(iVar2 + 0x24);
LAB_004051e6:
    if (sVar4 == 0) {
      uVar8 = 0;
      param_2 = param_3 + param_2;
    }
    else {
      if (sVar4 != 1) {
        if (sVar4 != 2) {
          return 0;
        }
        if (param_2 != 0) {
          return 0;
        }
        iVar2 = FUN_0058c724(param_1,local_4 + param_3,0);
        if (iVar2 == 1) {
          return 1;
        }
        return iVar2 - param_3;
      }
      uVar8 = 1;
    }
    iVar3 = FUN_0058c724(param_1,param_2,uVar8);
    iVar2 = 1;
    if (iVar3 != 1) {
      return iVar3 - param_3;
    }
  }
  return iVar2;
}



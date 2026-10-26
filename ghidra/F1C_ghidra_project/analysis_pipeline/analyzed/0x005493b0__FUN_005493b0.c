// Function: FUN_005493b0 @ 005493b0
// Size (bytes): 136


void __thiscall FUN_005493b0(int param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xfc);
  if (iVar4 == 0) {
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
      *(undefined4 *)(param_1 + 0xfc) = 0;
    }
    else {
      iVar3 = FUN_00548e00();
      *(int *)(param_1 + 0xfc) = iVar3;
    }
  }
  else {
    for (iVar3 = *(int *)(iVar4 + 0x14); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
      iVar4 = iVar3;
    }
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00548e00();
    }
    *(int *)(iVar4 + 0x14) = iVar3;
  }
  iVar4 = iVar3 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar4] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(iVar3);
  return;
}



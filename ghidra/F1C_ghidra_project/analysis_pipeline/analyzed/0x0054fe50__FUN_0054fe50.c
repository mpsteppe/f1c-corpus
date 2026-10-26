// Function: FUN_0054fe50 @ 0054fe50
// Size (bytes): 109


undefined4 __thiscall FUN_0054fe50(int param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005426a0();
  }
  *(undefined4 *)(param_1 + 0x54) = uVar3;
  uVar4 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  cVar1 = param_2[~uVar4 - 2];
  iVar5 = ~uVar4 - 2;
  while ((cVar1 != '\\' && (iVar5 = iVar5 + -1, -1 < iVar5))) {
    cVar1 = param_2[iVar5];
  }
  param_2 = param_2 + iVar5 + 1;
  iVar5 = (param_1 + 4) - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar5] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(param_1 + 4);
  return 0;
}



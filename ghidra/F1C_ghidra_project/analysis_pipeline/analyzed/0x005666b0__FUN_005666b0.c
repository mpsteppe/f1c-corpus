// Function: FUN_005666b0 @ 005666b0
// Size (bytes): 247


undefined4 __thiscall FUN_005666b0(int *param_1,int param_2,char *param_3,int param_4)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int local_4;
  
  uVar5 = 0xffffffff;
  pcVar7 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  pcVar7 = (char *)*param_1;
  iVar6 = ~uVar5 - 1;
  if (pcVar7 == (char *)0x0) {
    local_4 = 0;
  }
  else {
    uVar5 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    local_4 = ~uVar5 - 1;
  }
  if ((-1 < param_2) && (param_2 <= local_4)) {
    if (pcVar7 == (char *)0x0) {
      if (param_4 < iVar6) {
        param_4 = iVar6;
      }
      param_1[1] = param_4;
      puVar2 = operator_new(param_4 + 1);
      *param_1 = (int)puVar2;
      *puVar2 = 0;
    }
    else {
      iVar4 = param_1[1];
      if (iVar4 < iVar4 + iVar6) {
        if (param_4 < iVar6) {
          param_4 = iVar6;
        }
        pcVar3 = operator_new(iVar4 + param_4 + 1);
        pcVar7 = (char *)*param_1;
        pcVar9 = pcVar3;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar9 = cVar1;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        FUN_00587bcf(*param_1);
        *param_1 = (int)pcVar3;
        param_1[1] = iVar4 + param_4;
      }
    }
    for (; param_2 <= local_4; local_4 = local_4 + -1) {
      ((undefined1 *)(*param_1 + local_4))[iVar6] = *(undefined1 *)(*param_1 + local_4);
    }
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        iVar8 = *param_1 + iVar4;
        pcVar7 = param_3 + iVar4;
        iVar4 = iVar4 + 1;
        *(char *)(iVar8 + param_2) = *pcVar7;
      } while (iVar4 < iVar6);
    }
    return 0;
  }
  return 0xffffffff;
}



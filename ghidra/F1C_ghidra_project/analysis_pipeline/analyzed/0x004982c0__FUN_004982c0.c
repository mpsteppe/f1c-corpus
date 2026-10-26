// Function: FUN_004982c0 @ 004982c0
// Size (bytes): 234


undefined4 __thiscall FUN_004982c0(int param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  char in_stack_00000018;
  undefined4 uVar7;
  int local_8;
  char *local_4;
  
  pcVar3 = param_2;
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = (char *)(param_1 + 0x1518);
  iVar6 = -1;
  pcVar4 = pcVar1;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  if (iVar6 != -2) {
    pcVar4 = param_2;
    local_4 = pcVar1;
    if (in_stack_00000018 != '\0') {
      iVar6 = FUN_00423a00(param_2,&DAT_005ec4cc);
      if (iVar6 != 0) {
        pcVar4 = pcVar3;
        do {
          cVar2 = *pcVar4;
          pcVar4[(int)&DAT_005ec4cc - (int)pcVar3] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
      }
      pcVar4 = &DAT_005ec4cc;
    }
    FUN_00494f00(pcVar1,pcVar4,&param_2,&local_8);
    iVar6 = (int)param_2 - unaff_EBX;
    if (unaff_EBP < (int)local_4 - local_8) {
      local_8 = (((int)local_4 - local_8) / 2 - unaff_EBP / 2) + local_8;
    }
    uVar7 = param_3;
    uVar5 = FUN_00495150(param_3);
    FUN_00494f10(unaff_EDI,pcVar3,iVar6,local_8,uVar5,uVar7);
  }
  return 0;
}



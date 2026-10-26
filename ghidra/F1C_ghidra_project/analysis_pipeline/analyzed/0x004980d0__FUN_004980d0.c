// Function: FUN_004980d0 @ 004980d0
// Size (bytes): 286


undefined4 __thiscall FUN_004980d0(int param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  int unaff_retaddr;
  char in_stack_00000018;
  undefined4 uVar8;
  int local_8;
  char *local_4;
  
  pcVar3 = param_2;
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = (char *)(param_1 + 0x1518);
  iVar7 = -1;
  pcVar4 = pcVar1;
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  if (iVar7 != -2) {
    pcVar4 = param_2;
    local_4 = pcVar1;
    if (in_stack_00000018 != '\0') {
      iVar7 = FUN_00423a00(param_2,&DAT_005ec4cc);
      if (iVar7 != 0) {
        pcVar4 = pcVar3;
        do {
          cVar2 = *pcVar4;
          pcVar4[(int)&DAT_005ec4cc - (int)pcVar3] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
      }
      pcVar4 = &DAT_005ec4cc;
    }
    FUN_00494f00(pcVar1,pcVar4,&local_8,&param_2);
    iVar7 = ((int)param_2 - unaff_retaddr) / 2 + unaff_retaddr;
    if (unaff_EBX < (int)local_4 - local_8) {
      local_8 = (((int)local_4 - local_8) / 2 - unaff_EBX / 2) + local_8;
    }
    uVar8 = param_3;
    uVar5 = FUN_00495150(param_3);
    FUN_00494f10(unaff_EDI,pcVar3,iVar7 - unaff_EBP / 2,local_8,uVar5,uVar8);
    iVar6 = unaff_EBX + 0x1e;
    unaff_EBP = unaff_EBP + 0x14;
    FUN_00490920(iVar7,local_8,unaff_EBP,iVar6);
    FUN_004918d0(iVar7,local_8,unaff_EBP,iVar6);
  }
  return 0;
}



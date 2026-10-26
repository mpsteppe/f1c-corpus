// Function: FUN_00422fd0 @ 00422fd0
// Size (bytes): 129


undefined4 __thiscall FUN_00422fd0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  char local_400 [1024];
  
  puVar4 = *(undefined1 **)(param_1 + 0x80);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  else if (puVar4 == (undefined1 *)0x0) {
    return 0;
  }
  if ((param_2 != (char *)0x0) && (iVar2 = FUN_00588410(puVar4,&DAT_005ea438), iVar2 != 0)) {
    pcVar3 = param_2;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_400 + -(int)param_2)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_0058815f(param_2,&DAT_005be860,puVar4,local_400);
    return 1;
  }
  return 0;
}



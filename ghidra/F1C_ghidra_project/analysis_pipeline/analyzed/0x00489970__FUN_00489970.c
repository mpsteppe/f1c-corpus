// Function: FUN_00489970 @ 00489970
// Size (bytes): 158


undefined1 * __thiscall FUN_00489970(int param_1,int param_2)

{
  undefined1 *puVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  char local_50;
  undefined4 local_4f;
  
  local_50 = DAT_005ea438;
  puVar5 = &local_4f;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  pcVar3 = (char *)FUN_00489920();
  if (pcVar3 != (char *)0x0) {
    puVar1 = (undefined1 *)(param_1 + 0xe1);
    *puVar1 = 0;
    iVar4 = -(int)pcVar3;
    do {
      cVar2 = *pcVar3;
      pcVar3[(int)(&local_50 + iVar4)] = cVar2;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    pcVar3 = (char *)FUN_005897ca(&local_50,&DAT_005c692c);
    if (0 < param_2) {
      do {
        pcVar3 = (char *)FUN_005897ca(0,&DAT_005c692c);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    if (pcVar3 != (char *)0x0) {
      iVar4 = (int)puVar1 - (int)pcVar3;
      do {
        cVar2 = *pcVar3;
        pcVar3[iVar4] = cVar2;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      return puVar1;
    }
  }
  return (undefined1 *)0x0;
}



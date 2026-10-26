// Function: FUN_00498560 @ 00498560
// Size (bytes): 105


void __thiscall FUN_00498560(int param_1,char *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  char local_40 [63];
  undefined1 local_1;
  
  if (param_2 != (char *)0x0) {
    iVar4 = -1;
    pcVar3 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      _strncpy(local_40,param_2,0x3f);
      local_1 = 0;
      puVar2 = (undefined1 *)FUN_00566810();
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0;
      }
      pcVar3 = local_40;
      do {
        cVar1 = *pcVar3;
        pcVar3[(param_1 + 0x1518) - (int)local_40] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
  }
  return;
}



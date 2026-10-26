// Function: FUN_00497ec0 @ 00497ec0
// Size (bytes): 208


int __thiscall FUN_00497ec0(int param_1,char *param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char local_50 [80];
  
  iVar6 = -1;
  if (param_2 == (char *)0x0) {
    return -1;
  }
  iVar3 = -1;
  pcVar4 = param_2;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    iVar6 = -(int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)(local_50 + iVar6)] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_50);
    iVar6 = FUN_00497f90(local_50);
    if (iVar6 != 0) {
      return -1;
    }
    iVar6 = FUN_00495810(local_50);
    if (iVar6 == 0) {
      puVar2 = (undefined1 *)FUN_00587c20(local_50,&DAT_005beb48);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0;
      }
      pcVar4 = local_50;
      pcVar5 = (char *)(*(int *)(param_1 + 0x1514) * 0x50 + 0x114 + param_1);
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      *(int *)(param_1 + 0x1514) = *(int *)(param_1 + 0x1514) + 1;
    }
  }
  return iVar6;
}



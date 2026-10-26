// Function: FUN_004b0b20 @ 004b0b20
// Size (bytes): 211


void FUN_004b0b20(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  char local_100 [256];
  
  pcVar3 = (char *)FUN_00463c40();
  if (pcVar3 != (char *)0x0) {
    _strncpy(param_1,pcVar3,param_2 - 1U);
    param_1[param_2 - 1U] = '\0';
    return;
  }
  *param_1 = '\0';
  pcVar3 = (char *)FUN_004b0b10();
  iVar2 = -(int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(local_100 + iVar2)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar3 = local_100;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = local_100 + (~uVar5 - 1);
  if (local_100 < pcVar3) {
    do {
      if (*pcVar3 == '\\') {
        pcVar3 = pcVar3 + 1;
        break;
      }
      pcVar3 = pcVar3 + -1;
    } while (local_100 < pcVar3);
  }
  puVar4 = (undefined1 *)FUN_00566810();
  if (puVar4 != (undefined1 *)0x0) {
    *puVar4 = 0;
  }
  if (pcVar3 != (char *)0x0) {
    _strncpy(param_1,pcVar3,param_2 - 1U);
    param_1[param_2 - 1U] = '\0';
  }
  return;
}



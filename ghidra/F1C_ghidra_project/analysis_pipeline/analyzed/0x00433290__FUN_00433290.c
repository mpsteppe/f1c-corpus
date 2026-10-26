// Function: FUN_00433290 @ 00433290
// Size (bytes): 209


void FUN_00433290(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = (char *)*param_1;
  pcVar4 = pcVar5;
  if (pcVar5 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  uVar2 = 0xffffffff;
  pcVar3 = pcVar4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  for (pcVar3 = pcVar4 + (~uVar2 - 1); (pcVar4 < pcVar3 && (*pcVar3 != '\\')); pcVar3 = pcVar3 + -1)
  {
  }
  pcVar4 = (char *)FUN_004328e0();
  if (pcVar4 != (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar3 = pcVar4;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (pcVar5 == (char *)0x0) {
      pcVar5 = &DAT_005ea438;
    }
    _strncmp(pcVar4,pcVar5,~uVar2 - 1);
  }
  FUN_00568910(param_3);
  uVar2 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar5 = param_2 + (~uVar2 - 1);
  do {
    if (pcVar5 <= param_2) {
LAB_00433340:
      if (*param_2 == '\0') {
        _strncpy(param_2,&DAT_005c4068,param_3 - 1U);
        param_2[param_3 - 1U] = '\0';
      }
      return;
    }
    if (*pcVar5 == '.') {
      *pcVar5 = '\0';
      goto LAB_00433340;
    }
    pcVar5 = pcVar5 + -1;
  } while( true );
}



// Function: FUN_004b51e0 @ 004b51e0
// Size (bytes): 179


undefined1 * __thiscall FUN_004b51e0(undefined1 *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  FUN_004b4f70();
  _strncpy(param_1 + 1,(char *)(param_2 + 0x4620),0x3f);
  pcVar4 = (char *)(param_2 + 0x4714);
  uVar2 = 0xffffffff;
  param_1[0x40] = 0;
  pcVar3 = pcVar4;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  for (pcVar3 = pcVar4 + (~uVar2 - 1); pcVar4 < pcVar3; pcVar3 = pcVar3 + -1) {
    if (*pcVar3 == '\\') {
      pcVar3 = pcVar3 + 1;
      break;
    }
  }
  _strncpy(param_1 + 0x41,pcVar3,0x1f);
  param_1[0x60] = 0;
  pcVar4 = *(char **)(param_2 + 0x780);
  if (pcVar4 == (char *)0x0) {
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
  pcVar3 = pcVar4 + (~uVar2 - 1);
  do {
    if (pcVar3 <= pcVar4) {
LAB_004b5270:
      _strncpy(param_1 + 0x61,pcVar3,0x1f);
      param_1[0x80] = 0;
      *param_1 = *(undefined1 *)(param_2 + 0x4894);
      return param_1;
    }
    if (*pcVar3 == '\\') {
      pcVar3 = pcVar3 + 1;
      goto LAB_004b5270;
    }
    pcVar3 = pcVar3 + -1;
  } while( true );
}



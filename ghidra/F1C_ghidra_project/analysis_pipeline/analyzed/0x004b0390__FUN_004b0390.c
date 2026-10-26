// Function: FUN_004b0390 @ 004b0390
// Size (bytes): 81


undefined4 __thiscall FUN_004b0390(int param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_1 + 0x1b4);
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
LAB_004b03c0:
      _strncpy(param_2,pcVar3,param_3 - 1U);
      param_2[param_3 - 1U] = '\0';
      return 1;
    }
    if (*pcVar3 == '\\') {
      pcVar3 = pcVar3 + 1;
      goto LAB_004b03c0;
    }
    pcVar3 = pcVar3 + -1;
  } while( true );
}



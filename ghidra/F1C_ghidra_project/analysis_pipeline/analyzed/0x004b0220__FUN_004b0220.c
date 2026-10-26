// Function: FUN_004b0220 @ 004b0220
// Size (bytes): 136


undefined4 FUN_004b0220(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char local_200 [512];
  
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    return 0xffffffff;
  }
  FUN_00568620(0x200);
  _strncpy(param_1,local_200,param_2 - 1U);
  uVar3 = 0xffffffff;
  param_1[param_2 - 1U] = '\0';
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar3 - 1)) {
    for (pcVar2 = param_1 + (~uVar3 - 2); (param_1 <= pcVar2 && (*pcVar2 != '\\'));
        pcVar2 = pcVar2 + -1) {
      *pcVar2 = '\0';
    }
  }
  return 0;
}



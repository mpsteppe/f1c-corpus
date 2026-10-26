// Function: FUN_004894d0 @ 004894d0
// Size (bytes): 39


undefined4 FUN_004894d0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  iVar2 = -1;
  do {
    pcVar3 = param_1;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar3;
  } while (cVar1 != '\0');
  *(undefined2 *)(pcVar3 + -1) = DAT_005c692c;
  return 0;
}



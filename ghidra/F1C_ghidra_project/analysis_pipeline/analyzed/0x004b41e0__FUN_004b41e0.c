// Function: FUN_004b41e0 @ 004b41e0
// Size (bytes): 103


undefined4 __thiscall FUN_004b41e0(int param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_00566bd0(param_1,4);
  pcVar2 = *(char **)(param_1 + 4);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  param_2 = ~(byte)iVar4 - 1;
  FUN_00566bd0(&param_2,1);
  if (param_2 != '\0') {
    puVar3 = *(undefined1 **)(param_1 + 4);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566bd0(puVar3,param_2);
  }
  return 1;
}



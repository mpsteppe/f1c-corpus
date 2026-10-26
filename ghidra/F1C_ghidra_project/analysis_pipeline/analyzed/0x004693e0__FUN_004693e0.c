// Function: FUN_004693e0 @ 004693e0
// Size (bytes): 204


char * __thiscall FUN_004693e0(int param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x450))) {
    puVar3 = *(undefined4 **)(param_1 + 0x444);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (puVar3 == (undefined4 *)0x0) goto LAB_004694a3;
      puVar3 = (undefined4 *)puVar3[1];
    }
    if ((puVar3 != (undefined4 *)0x0) && ((undefined4 *)*puVar3 != (undefined4 *)0x0)) {
      pcVar6 = *(char **)*puVar3;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = &DAT_005ea438;
      }
      pcVar1 = (char *)(param_1 + 0x344);
      pcVar4 = pcVar1;
      do {
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        *pcVar4 = cVar2;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = 0xffffffff;
      pcVar6 = pcVar1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      for (pcVar6 = (char *)(~uVar5 + 0x343 + param_1); pcVar1 < pcVar6; pcVar6 = pcVar6 + -1) {
        if (*pcVar6 == '.') {
          *pcVar6 = '\0';
          break;
        }
      }
      uVar5 = 0xffffffff;
      pcVar6 = pcVar1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      pcVar6 = (char *)(~uVar5 + 0x343 + param_1);
      if (pcVar6 <= pcVar1) {
        return pcVar6;
      }
      do {
        if (*pcVar6 == '\\') {
          return pcVar6 + 1;
        }
        pcVar6 = pcVar6 + -1;
      } while (pcVar1 < pcVar6);
      return pcVar6;
    }
  }
LAB_004694a3:
  return &DAT_005ea438;
}



// Function: FUN_005667b0 @ 005667b0
// Size (bytes): 92


undefined4 __thiscall FUN_005667b0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((char *)*param_1 == (char *)0x0) {
    if ((param_2 == 0) && (param_3 == 0)) {
      return 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
    pcVar3 = (char *)*param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((-1 < param_2) && (param_3 <= (int)(~uVar2 - 1))) {
      param_2 = param_3 - param_2;
      do {
        *(undefined1 *)((*param_1 - param_2) + param_3) = *(undefined1 *)(*param_1 + param_3);
        param_3 = param_3 + 1;
      } while (param_3 <= (int)(~uVar2 - 1));
      return 0;
    }
  }
  return 0xffffffff;
}



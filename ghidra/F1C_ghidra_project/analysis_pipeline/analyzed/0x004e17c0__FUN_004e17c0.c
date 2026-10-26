// Function: FUN_004e17c0 @ 004e17c0
// Size (bytes): 222


void __thiscall FUN_004e17c0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
    if (param_3 == 0) {
      if ((*(int *)(param_2 * 0x128 + 0x144 + param_1) != 0) &&
         (*(char *)(param_2 * 0x128 + param_1 + 0x184) != '\0')) {
        return;
      }
      FUN_004e0e20(param_2);
      return;
    }
    if (*(int *)(param_2 * 0x128 + 0x144 + param_1) == 0) {
      return;
    }
    if (*(char *)(param_2 * 0x128 + param_1 + 0x184) == '\0') {
      return;
    }
    FUN_004e0e70(param_2);
    return;
  case 4:
    piVar1 = (int *)(param_1 + 0x5e4);
    break;
  case 5:
    piVar1 = (int *)(param_1 + 0x628);
    break;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    piVar1 = (int *)((param_2 + -6) * 0x44 + 0x66c + param_1);
    break;
  default:
    goto switchD_004e17d6_default;
  }
  if (param_3 == 0) {
    if ((*piVar1 != 0) && ((char)piVar1[0x10] == '\0')) {
      FUN_004e0d00(piVar1);
      return;
    }
  }
  else if ((*piVar1 == 0) || ((char)piVar1[0x10] != '\0')) {
    FUN_004e0d70(piVar1);
  }
switchD_004e17d6_default:
  return;
}



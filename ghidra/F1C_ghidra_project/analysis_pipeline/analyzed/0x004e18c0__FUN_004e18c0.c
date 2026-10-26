// Function: FUN_004e18c0 @ 004e18c0
// Size (bytes): 134


undefined4 __thiscall FUN_004e18c0(int param_1,int param_2)

{
  int *piVar1;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
    piVar1 = (int *)(param_2 * 0x128 + 0x144 + param_1);
    if (*piVar1 == 0) {
      return 1;
    }
    goto LAB_004e1932;
  case 4:
    if ((*(int *)(param_1 + 0x5e4) != 0) && (*(char *)(param_1 + 0x624) == '\0')) {
      return 1;
    }
    break;
  case 5:
    if ((*(int *)(param_1 + 0x628) != 0) && (*(char *)(param_1 + 0x668) == '\0')) {
      return 1;
    }
    break;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    piVar1 = (int *)(param_2 * 0x44 + 0x4d4 + param_1);
    if (*piVar1 == 0) {
      return 0;
    }
LAB_004e1932:
    if ((char)piVar1[0x10] == '\0') {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_0040d2d0 @ 0040d2d0
// Size (bytes): 99


void FUN_0040d2d0(char param_1)

{
  int iVar1;
  
  if (param_1 == '\0') {
    iVar1 = DAT_007c54dc + -1;
  }
  else {
    iVar1 = DAT_007c54dc + 1;
  }
  if (iVar1 < 0) {
    iVar1 = DAT_005c329c + -1;
  }
  else if (DAT_005c329c <= iVar1) {
    iVar1 = 0;
  }
  FUN_0040d240(*(undefined4 *)((&DAT_007c54f0)[iVar1] + 0x4894));
  iVar1 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_004f0d20();
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_005c329c);
  }
  return;
}



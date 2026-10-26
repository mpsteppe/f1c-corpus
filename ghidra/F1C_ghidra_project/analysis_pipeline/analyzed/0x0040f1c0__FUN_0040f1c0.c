// Function: FUN_0040f1c0 @ 0040f1c0
// Size (bytes): 280


char __thiscall FUN_0040f1c0(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 3:
    cVar2 = FUN_0045a8e0(param_2,param_1 + 0xc);
    if (cVar2 == '\0') {
      FUN_0040f600();
      FUN_004bde20(param_1);
      return '\0';
    }
    break;
  case 1:
  case 4:
    cVar2 = FUN_0045a8e0(param_2,param_1 + 0xc);
    if (cVar2 == '\0') {
      FUN_0040f600();
      FUN_004bde20(param_1);
      return '\0';
    }
    break;
  case 2:
  case 5:
    cVar2 = FUN_0045a8e0(param_2,param_1 + 0xc);
    if (cVar2 == '\0') {
      FUN_0040f600();
      FUN_004bde20(param_1);
      return '\0';
    }
    break;
  case 6:
    if ((*(uint *)(**(int **)(param_1 + 0x20) + 0x48bc) >> 3 & 1) != 0) {
      FUN_004e4930(param_2);
    }
    FUN_004e9600();
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x34d4);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0x34d8);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x34dc);
    FUN_004bde20(param_1);
    return '\x01';
  default:
    cVar2 = '\0';
  }
  FUN_004bde20(param_1);
  return cVar2;
}



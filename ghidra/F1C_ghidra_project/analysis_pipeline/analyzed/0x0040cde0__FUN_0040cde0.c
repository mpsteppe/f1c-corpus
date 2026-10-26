// Function: FUN_0040cde0 @ 0040cde0
// Size (bytes): 621


undefined4 __thiscall FUN_0040cde0(int param_1,int param_2,char param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = false;
  switch(param_2) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    if ((param_3 != '\0') && (*(int *)(param_1 + 8) == *(int *)(param_1 + 0x18))) {
      uVar2 = 1;
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(3,uVar2,0);
    if ((*(char *)(DAT_007c54e0 + 0x344c) != '\0') && (DAT_007cfe88 == '\0')) {
      FUN_004e0ed0(0);
      FUN_00409440(2,0,0);
      *(undefined4 *)(param_1 + 0x14) = 3;
      *(undefined4 *)(param_1 + 0xc) = 2;
      bVar1 = true;
    }
    if (bVar1) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  case 4:
    if ((param_3 != '\0') && (*(int *)(param_1 + 8) == *(int *)(param_1 + 0x18))) {
      uVar2 = 1;
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(4,uVar2,0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  case 5:
    if ((0 < *(int *)(*(int *)(param_1 + 0x20) + 0x10)) ||
       (0 < *(int *)(*(int *)(param_1 + 0x1c) + 0x10))) {
      if ((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 8) != *(int *)(param_1 + 0x1c))) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 0x20);
      }
      (**(code **)(**(int **)(param_1 + 8) + 0x10))();
    }
    FUN_004e0ed0(0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  default:
    return 1;
  case 7:
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(5,0,0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  case 8:
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(6,0,0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  case 9:
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(7,0,0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  case 10:
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    FUN_004e0ed0(0);
    FUN_00409440(8,0,0);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  }
  uVar2 = 2;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else if (param_2 == 1) {
    uVar2 = 1;
  }
  if (param_3 == '\0') {
    FUN_00409440(uVar2,1,1);
    *(int *)(param_1 + 0xc) = param_2;
    return 0;
  }
  FUN_00409440(uVar2,1,0);
  *(int *)(param_1 + 0xc) = param_2;
  return 0;
}



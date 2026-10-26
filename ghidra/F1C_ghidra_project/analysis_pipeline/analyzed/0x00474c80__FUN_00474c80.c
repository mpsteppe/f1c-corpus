// Function: FUN_00474c80 @ 00474c80
// Size (bytes): 290


uint __thiscall FUN_00474c80(int param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x31c) - 0x1a2;
  switch(uVar1) {
  case 0:
    *param_2 = 1;
    return 1;
  case 1:
    *param_2 = 2;
    return 1;
  case 2:
    *param_2 = 4;
    return 1;
  case 3:
    *param_2 = 8;
    return 1;
  case 4:
    *param_2 = 0x10;
    return 1;
  case 5:
    *param_2 = 0x20;
    return 1;
  case 6:
    *param_2 = 0x40;
    return 1;
  case 7:
    *param_2 = 0x80;
    return 1;
  case 8:
    *param_2 = 0x100;
    return 0x101;
  case 9:
    *param_2 = 0x200;
    return 0x201;
  case 10:
    *param_2 = 0x400;
    return 0x401;
  default:
    *param_2 = 0xffffffff;
    return uVar1 & 0xffffff00;
  }
}



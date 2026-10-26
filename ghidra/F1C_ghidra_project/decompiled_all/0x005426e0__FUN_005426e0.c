// Function: FUN_005426e0 @ 005426e0
// Strings:  [Undefined video format]


undefined4 __thiscall FUN_005426e0(int param_1,int param_2,undefined4 param_3)

{
  if (((-1 < (char)((uint)param_3 >> 8)) && (param_2 == 0)) &&
     (param_2 = DAT_008b8de4, DAT_008b8de4 == 0xff)) {
    FUN_0053c590(0xffffffff,s_Undefined_video_format_005dbd7c);
    return 0xffffffff;
  }
  switch(param_2) {
  case 1:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 1;
    return 0;
  case 2:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 2;
    return 0;
  case 3:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 4;
    return 0;
  case 4:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 8;
    return 0;
  case 5:
  case 6:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 0x10;
    return 0;
  case 7:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 0x18;
    return 0;
  case 8:
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 0x20;
    return 0;
  default:
    *(undefined4 *)(param_1 + 0x30) = 0xff;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return 0;
  }
}



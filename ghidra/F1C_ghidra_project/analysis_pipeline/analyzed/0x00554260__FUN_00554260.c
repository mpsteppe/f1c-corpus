// Function: FUN_00554260 @ 00554260
// Size (bytes): 79


undefined4 __thiscall FUN_00554260(int *param_1,undefined4 param_2,int param_3)

{
  switch(param_2) {
  case 1:
    break;
  case 2:
    param_1 = param_1 + 1;
    break;
  case 3:
    param_1 = param_1 + 2;
    break;
  case 4:
    param_1 = param_1 + 5;
    break;
  case 5:
    param_1 = param_1 + 6;
    break;
  case 6:
    param_1 = param_1 + 7;
    break;
  default:
    goto switchD_0055426c_caseD_7;
  case 0xd:
    param_1 = param_1 + 3;
    break;
  case 0xe:
    param_1 = param_1 + 4;
  }
  if ((param_1 != (int *)0x0) && (*param_1 != param_3)) {
    *param_1 = param_3;
    return 1;
  }
switchD_0055426c_caseD_7:
  return 0;
}



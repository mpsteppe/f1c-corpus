// Function: FUN_004ed250 @ 004ed250
// Size (bytes): 269


void __thiscall FUN_004ed250(int *param_1,int param_2)

{
  int *piVar1;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
    if (*(int *)(*param_1 + 0x4068) == 0) {
      *(undefined4 *)(*param_1 + 0x4068) = 6;
    }
    FUN_004e0e70(param_2);
    param_1[0xf58] = 2;
    if (param_1[0xcaf] == 0) {
      FUN_0043e770(param_2);
      FUN_0041afd0(*param_1,param_2);
      return;
    }
    break;
  case 4:
    piVar1 = param_1 + 0x332;
    goto LAB_004ed2e3;
  case 5:
    piVar1 = param_1 + 0x343;
LAB_004ed2e3:
    FUN_004e0d70(piVar1);
    FUN_004a56b0(1);
    if (param_1[0xf58] == 0) {
      param_1[0xf58] = 1;
    }
    param_1[0xe9c] = param_1[0xea0];
    FUN_004e8010(0);
    FUN_0041afd0(*param_1,param_2);
    return;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    FUN_004e0d70(param_1 + param_2 * 0x11 + 0x2ee);
  }
  FUN_0041afd0(*param_1,param_2);
  return;
}



// Function: FUN_004dc340 @ 004dc340
// Size (bytes): 193


void __fastcall
FUN_004dc340(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int *param_6,
            int *param_7)

{
  switch(param_5) {
  case 0:
    *param_6 = param_1;
    *param_7 = param_2;
    return;
  case 1:
    *param_6 = param_1 - param_3;
    *param_7 = param_2;
    return;
  case 2:
    *param_6 = param_1 - param_3 / 2;
    *param_7 = param_2;
    return;
  case 4:
    *param_6 = param_1 - param_3;
    *param_7 = param_2 - param_4;
    return;
  case 5:
    param_1 = param_1 - param_3 / 2;
  case 3:
    *param_6 = param_1;
    *param_7 = param_2 - param_4;
    return;
  case 6:
    break;
  case 7:
    param_1 = param_1 - param_3;
    break;
  case 8:
    param_1 = param_1 - param_3 / 2;
    break;
  default:
    goto switchD_004dc350_default;
  }
  *param_6 = param_1;
  *param_7 = param_2 - param_4 / 2;
switchD_004dc350_default:
  return;
}



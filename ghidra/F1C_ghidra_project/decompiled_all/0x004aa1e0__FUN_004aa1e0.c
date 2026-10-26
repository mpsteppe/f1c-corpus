// Function: FUN_004aa1e0 @ 004aa1e0
// Strings:  [RPLAY , RPLAY , MULTI , MULTI , CHAMP , CHAMP , GPRIX , GPRIX ]


undefined4 FUN_004aa1e0(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  char *pcVar1;
  
  switch(param_1) {
  case 0:
    pcVar1 = s_CURNT_005cd6fc;
    break;
  case 1:
    pcVar1 = s_PRACT_005cd6f4;
    break;
  case 2:
    pcVar1 = s_QUICK_005cd6ec;
    break;
  case 3:
    pcVar1 = s_GPRIX_005cd6e4;
    break;
  case 4:
    pcVar1 = s_CHAMP_005cd6dc;
    break;
  case 5:
    pcVar1 = s_MULTI_005cd6d4;
    break;
  case 6:
    pcVar1 = s_RPLAY_005cd6cc;
    break;
  default:
    *param_3 = 0;
    return 0;
  }
  FUN_0058815f(param_3,&DAT_005be860,pcVar1,param_2);
  return 1;
}



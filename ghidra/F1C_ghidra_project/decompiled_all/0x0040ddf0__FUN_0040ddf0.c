// Function: FUN_0040ddf0 @ 0040ddf0
// Strings:  [CinematicEvent]


uint __fastcall FUN_0040ddf0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = *param_1 + 1;
  uVar3 = 0;
  switch(*param_1) {
  case 2:
  case 3:
  case 4:
  case 5:
    uVar2 = FUN_005679c0(s_CinematicEvent_005beb50);
    uVar1 = FUN_0040d4c0(uVar2);
    if ((char)uVar1 != '\0') {
      param_1[0x26] = 0;
      param_1[0x27] = 0;
      *param_1 = 2;
      return 1;
    }
    break;
  case -1:
  case 0:
  case 1:
switchD_0040de02_caseD_ffffffff:
    return uVar3 & 0xffffff00;
  }
  *param_1 = -1;
  uVar3 = uVar1;
  goto switchD_0040de02_caseD_ffffffff;
}



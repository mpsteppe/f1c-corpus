// Function: FUN_0042ce30 @ 0042ce30
// Strings:  [Unknown, Warmup, Qualify, Practice4, Practice3, Practice2, Practice1, TestDay]


char * __fastcall FUN_0042ce30(undefined4 param_1,char param_2)

{
  if (param_2 != '\0') {
    switch(param_1) {
    case 0:
      return s_Test_Day_005c3548;
    case 1:
      return s_Practice_1_005c353c;
    case 2:
      return s_Practice_2_005c3530;
    case 3:
      return s_Practice_3_005c3524;
    case 4:
      return s_Practice_4_005c3518;
    case 5:
      goto switchD_0042ce39_caseD_5;
    case 6:
switchD_0042ce39_caseD_6:
      return s_Warmup_005c34d0;
    case 7:
switchD_0042ce39_caseD_7:
      return &DAT_005c34c8;
    default:
switchD_0042ce39_default:
      return s_Unknown_005c307c;
    }
  }
  switch(param_1) {
  case 0:
    return s_TestDay_005c3510;
  case 1:
    return s_Practice1_005c3504;
  case 2:
    return s_Practice2_005c34f8;
  case 3:
    return s_Practice3_005c34ec;
  case 4:
    return s_Practice4_005c34e0;
  case 5:
switchD_0042ce39_caseD_5:
    return s_Qualify_005c34d8;
  case 6:
    goto switchD_0042ce39_caseD_6;
  case 7:
    goto switchD_0042ce39_caseD_7;
  default:
    goto switchD_0042ce39_default;
  }
}



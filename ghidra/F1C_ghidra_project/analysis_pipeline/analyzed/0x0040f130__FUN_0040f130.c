// Function: FUN_0040f130 @ 0040f130
// Size (bytes): 105


void __fastcall FUN_0040f130(int *param_1)

{
  switch(param_1[7]) {
  case 0:
  case 3:
    break;
  case 1:
  case 4:
    break;
  case 2:
  case 5:
    break;
  default:
    goto switchD_0040f13b_default;
  }
  FUN_00459830(param_1 + 3);
  if (*param_1 == -1) {
    FUN_004be180(param_1);
    FUN_004be010(param_1);
    return;
  }
  FUN_00410af0(param_1);
  FUN_004bdf90(param_1);
  FUN_004be010(param_1);
switchD_0040f13b_default:
  return;
}



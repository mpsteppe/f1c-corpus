// Function: FUN_00553310 @ 00553310
// Size (bytes): 85


void __fastcall FUN_00553310(uint *param_1)

{
  if (((*param_1 & 1) != 0) || ((*param_1 & 2) != 0)) {
    if (param_1[6] != 0) {
      FUN_00587bcf(param_1[6]);
    }
    param_1[6] = 0;
  }
  if (param_1[5] != 0) {
    FUN_00540eb0(param_1[5]);
    if (param_1[5] != 0) {
      FUN_00587bcf(param_1[5]);
    }
    param_1[5] = 0;
  }
  FUN_004b0170();
  return;
}



// Function: FUN_00434240 @ 00434240
// Size (bytes): 79


void __fastcall FUN_00434240(int *param_1)

{
  if (((char)param_1[2] != '\0') && (param_1 = (int *)*param_1, param_1 != (int *)0x0)) {
    FUN_00432cc0();
    if (param_1[5] != 0) {
      FUN_00587bcf(param_1[5]);
    }
    if (param_1[2] != 0) {
      FUN_00587bcf(param_1[2]);
    }
    if (*param_1 != 0) {
      FUN_00587bcf(*param_1);
    }
    FUN_00587bcf(param_1);
  }
  return;
}



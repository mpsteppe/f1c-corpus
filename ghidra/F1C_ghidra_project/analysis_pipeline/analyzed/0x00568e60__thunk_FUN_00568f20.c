// Function: thunk_FUN_00568f20 @ 00568e60
// Size (bytes): 5


void __fastcall thunk_FUN_00568f20(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
    *param_1 = 0;
  }
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  if (param_1[0x8c] != 0) {
    FUN_00587bcf(param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  param_1[0x8d] = 0;
  if (param_1[0x8e] != 0) {
    FUN_00587bcf(param_1[0x8e]);
    param_1[0x8e] = 0;
  }
  param_1[0x8f] = 0;
  if (param_1[0x90] != 0) {
    FUN_00587bcf(param_1[0x90]);
    param_1[0x90] = 0;
  }
  return;
}



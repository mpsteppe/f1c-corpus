// Function: FUN_004c3130 @ 004c3130
// Size (bytes): 194


void __fastcall FUN_004c3130(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0xf5];
  while (iVar1 != 0) {
    iVar2 = param_1[0xf5];
    iVar1 = *(int *)(iVar2 + 0x10);
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 8) != 0) {
        FUN_00587bcf(*(int *)(iVar2 + 8));
      }
      FUN_00414370();
      FUN_00587bcf(iVar2);
    }
    param_1[0xf5] = iVar1;
  }
  if (param_1[0xf6] != 0) {
    FUN_00587bcf(param_1[0xf6]);
  }
  if (param_1[0xf3] != 0) {
    FUN_00587bcf(param_1[0xf3]);
  }
  if (param_1[8] != 0) {
    FUN_00587bcf(param_1[8]);
  }
  if (param_1[6] != 0) {
    FUN_00587bcf(param_1[6]);
  }
  if (param_1[4] != 0) {
    FUN_00587bcf(param_1[4]);
  }
  if (param_1[2] != 0) {
    FUN_00587bcf(param_1[2]);
  }
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  return;
}



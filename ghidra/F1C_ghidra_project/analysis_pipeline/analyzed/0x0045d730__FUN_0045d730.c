// Function: FUN_0045d730 @ 0045d730
// Size (bytes): 338


void __fastcall FUN_0045d730(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1b780);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00418d60(1);
  }
  *(undefined4 *)(param_1 + 0x1b780) = 0;
  *(undefined4 *)(param_1 + 0x1b784) = 0;
  *(undefined4 *)(param_1 + 0x1b788) = 0;
  *(undefined4 *)(param_1 + 0x1b78c) = 0;
  iVar1 = *(int *)(param_1 + 0x1b770);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00418d60(1);
  }
  *(undefined4 *)(param_1 + 0x1b770) = 0;
  *(undefined4 *)(param_1 + 0x1b774) = 0;
  *(undefined4 *)(param_1 + 0x1b778) = 0;
  *(undefined4 *)(param_1 + 0x1b77c) = 0;
  iVar1 = *(int *)(param_1 + 0x1b758);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00418d60(1);
  }
  *(undefined4 *)(param_1 + 0x1b758) = 0;
  *(undefined4 *)(param_1 + 0x1b75c) = 0;
  *(undefined4 *)(param_1 + 0x1b760) = 0;
  *(undefined4 *)(param_1 + 0x1b764) = 0;
  iVar1 = 0x68;
  do {
    FUN_004b0170();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = *(int *)(param_1 + 0x3fc8);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_004646f0(1);
  }
  *(undefined4 *)(param_1 + 0x3fc8) = 0;
  *(undefined4 *)(param_1 + 0x3fcc) = 0;
  *(undefined4 *)(param_1 + 0x3fd0) = 0;
  *(undefined4 *)(param_1 + 0x3fd4) = 0;
  *(undefined ***)(param_1 + 0x3fbc) = &PTR_FUN_0059f0cc;
  iVar1 = 0x68;
  do {
    FUN_004b0170();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xbc));
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xb4));
  }
  FUN_004b0170();
  return;
}



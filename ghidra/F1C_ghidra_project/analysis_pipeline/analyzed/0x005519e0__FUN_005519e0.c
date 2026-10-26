// Function: FUN_005519e0 @ 005519e0
// Size (bytes): 77


undefined4 __thiscall FUN_005519e0(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x2c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x30) = *(undefined4 *)(param_2 + 0x30);
  }
  if (*(int *)(param_2 + 0x30) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  }
  if (param_2 == *(int *)(param_1 + 0x118)) {
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_2 + 0x30);
  }
  FUN_00550ac0();
  FUN_00557470();
  FUN_00587bcf(param_2);
  return 0;
}



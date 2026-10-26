// Function: FUN_00567cc0 @ 00567cc0
// Size (bytes): 64


void FUN_00567cc0(int param_1)

{
  if (param_1 != 0) {
    FUN_00567cc0(*(undefined4 *)(param_1 + 4));
    FUN_00567cc0(*(undefined4 *)(param_1 + 8));
    FUN_00567cc0(*(undefined4 *)(param_1 + 0xc));
    FUN_00567940();
    FUN_00587bcf(param_1);
  }
  return;
}



// Function: FUN_0055d410 @ 0055d410
// Size (bytes): 77


void __thiscall FUN_0055d410(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x14) = param_3;
    uVar1 = 2;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0x24) = param_3;
    uVar1 = 3;
  }
  else {
    if (param_2 != 3) goto LAB_0055d44b;
    *(undefined4 *)(param_1 + 0x34) = param_3;
    uVar1 = 4;
  }
  FUN_005416a0(param_1,*(undefined4 *)(param_1 + 4),uVar1);
LAB_0055d44b:
  *(uint *)(DAT_008b8f28 + 0xec) = *(uint *)(DAT_008b8f28 + 0xec) | 0x800;
  return;
}



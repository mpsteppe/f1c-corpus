// Function: FUN_005514c0 @ 005514c0
// Size (bytes): 153


void __thiscall FUN_005514c0(int param_1,undefined4 param_2)

{
  float10 fVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    if ((*(uint *)(param_1 + 4) & 0x1000) != 0) {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffefff | 0x8000;
      *(undefined4 *)(param_1 + 8) = 0;
      FUN_00556440();
    }
    if ((char)((uint)*(undefined4 *)(param_1 + 4) >> 8) < '\0') {
      fVar1 = (float10)FUN_005565b0();
      *(float *)(param_1 + 0x10) = (float)fVar1;
      if ((float10)*(float *)(*(int *)(param_1 + 0x1c) + 8) <= fVar1) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8);
        if ((*(uint *)(param_1 + 4) & 0x20000) != 0) {
          FUN_005514a0();
          FUN_00551210(param_2,*(undefined4 *)(param_1 + 0x10));
          return;
        }
        FUN_00551440();
        FUN_00551480();
      }
      FUN_00551210(param_2,*(undefined4 *)(param_1 + 0x10));
    }
  }
  return;
}



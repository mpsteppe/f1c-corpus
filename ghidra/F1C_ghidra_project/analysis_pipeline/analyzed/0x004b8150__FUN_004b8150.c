// Function: FUN_004b8150 @ 004b8150
// Size (bytes): 68


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004b8150(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x6cc))) {
    puVar1 = *(undefined4 **)(param_1 + 0x6c0);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (puVar1 == (undefined4 *)0x0) goto LAB_004b818b;
      puVar1 = (undefined4 *)puVar1[1];
    }
    if ((puVar1 != (undefined4 *)0x0) && ((float *)*puVar1 != (float *)0x0)) {
      return (float10)*(float *)*puVar1;
    }
  }
LAB_004b818b:
  return (float10)_DAT_0059e670;
}



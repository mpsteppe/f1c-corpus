// Function: FUN_004f15da @ 004f15da
// Size (bytes): 75


void __thiscall FUN_004f15da(int param_1)

{
  int in_EAX;
  int unaff_ESI;
  float10 in_ST0;
  float10 fVar1;
  undefined4 in_stack_00000010;
  
  *(float *)(in_EAX + -4) = (float)in_ST0;
  if (*(int *)(unaff_ESI + 0x39f8) < param_1) {
    if ((DAT_007d01c4 & 4) != 0) {
      fVar1 = (float10)FUN_005881f0();
      *(float *)(unaff_ESI + 0x3984) = (float)(fVar1 * (float10)*(float *)(unaff_ESI + 0x3984));
    }
    *(undefined4 *)(unaff_ESI + 0x3bf4) = in_stack_00000010;
    FUN_004e8010(0);
    return;
  }
  FUN_0059d9b5();
  return;
}



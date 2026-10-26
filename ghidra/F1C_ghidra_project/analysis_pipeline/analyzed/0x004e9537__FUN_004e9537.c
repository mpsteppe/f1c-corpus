// Function: FUN_004e9537 @ 004e9537
// Size (bytes): 194


float10 FUN_004e9537(void)

{
  float fVar1;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar2;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float fStack0000001c;
  float fStack00000020;
  float in_stack_00000024;
  
  fStack0000001c =
       (float)(in_ST0 / ((float10)*(float *)(unaff_EDI + 0x90) *
                        (float10)*(float *)(unaff_ESI + 0x3514)));
  fVar1 = SQRT(in_stack_00000024);
  fStack00000020 = in_stack_00000018 * *(float *)(unaff_ESI + 0x3cbc);
  fVar2 = (float10)FUN_005895a2((double)fStack00000020);
  in_stack_00000024 = (float)(int)ROUND((float)fVar2);
  if ((int)in_stack_00000024 < 0) {
    fVar2 = (float10)*(float *)(unaff_ESI + 0x3cc0);
  }
  else {
    if (0xd < (int)in_stack_00000024) {
      in_stack_00000024 = 1.82169e-44;
    }
    fVar2 = (float10)*(float *)(unaff_ESI + 0x3cc0 + (int)in_stack_00000024 * 4);
    fVar2 = ((float10)fStack00000020 - (float10)(int)in_stack_00000024) *
            ((float10)*(float *)(unaff_ESI + 0x3cc4 + (int)in_stack_00000024 * 4) - fVar2) + fVar2;
  }
  fVar2 = fVar2 * (float10)*(float *)(unaff_ESI + 0x3518) * (float10)(fVar1 / in_stack_00000010);
  if ((float10)fStack0000001c < fVar2) {
    fVar2 = (float10)fStack0000001c;
  }
  return (fVar2 - (float10)*(float *)(unaff_ESI + 0x3d44) * (float10)*(float *)(unaff_ESI + 0x3518)
                  * (float10)in_stack_00000014) -
         (float10)*(float *)(*(int *)(unaff_EBP + 0x10) + 8);
}



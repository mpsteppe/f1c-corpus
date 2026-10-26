// Function: FUN_0042ed00 @ 0042ed00
// Size (bytes): 47


float10 __thiscall FUN_0042ed00(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0042dd00(*(undefined4 *)(param_2 * 0x40 + 0xbc4 + param_1),
                                *(undefined4 *)(param_1 + 0x1644));
  if (param_2 == 0x2b) {
    fVar1 = -fVar1;
  }
  return fVar1;
}



// Function: FUN_005912bc @ 005912bc
// Size (bytes): 178


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005912bc(void)

{
  float10 in_ST0;
  float10 fVar1;
  float10 in_ST1;
  
  if (((uint)((unkuint10)in_ST1 >> 0x30) & 0x7fff0000) != 0) {
    fVar1 = (float10)FUN_005910b6();
    return fVar1;
  }
  if (SUB104(in_ST1,0) != 0 || (int)((unkuint10)in_ST1 >> 0x20) != 0) {
    fVar1 = (float10)FUN_005910b6(in_ST1 * (float10)_DAT_005e7514);
    return fVar1;
  }
  return in_ST0 - (float10)(unkint10)(in_ST0 / in_ST1) * in_ST1;
}



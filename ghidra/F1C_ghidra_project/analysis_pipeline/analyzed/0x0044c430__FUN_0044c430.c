// Function: FUN_0044c430 @ 0044c430
// Size (bytes): 49


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044c430(void)

{
  float10 fVar1;
  int local_4;
  
  local_4 = 0;
  do {
    fVar1 = (float10)local_4;
    local_4 = local_4 + 1;
    fVar1 = (float10)fsin(fVar1 * (float10)_DAT_0059ef50);
    *(float *)(local_4 * 4 + 0x7ca384) = (float)fVar1;
  } while (local_4 < 7);
  (&DAT_007ca388)[local_4] = 0x3f800000;
  return;
}



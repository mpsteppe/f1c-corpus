// Function: FUN_004e45b0 @ 004e45b0
// Size (bytes): 477


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e45b0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  float fVar2;
  int extraout_ECX;
  int unaff_ESI;
  int in_stack_000000f4;
  double in_stack_000000f8;
  int in_stack_00001acc;
  
  FUN_005881c0();
  FUN_004e4790();
  iVar1 = *(int *)(extraout_ECX + 0x32bc);
  if (iVar1 == 0) {
    FUN_0043e050();
  }
  else {
    if (iVar1 < 1) {
      return;
    }
    if (3 < iVar1) {
      return;
    }
  }
  FUN_0042e320();
  FUN_004f34e0();
  FUN_004f4270();
  FUN_004f4270();
  *(int *)(extraout_ECX + 0x3498) = in_stack_000000f4;
  if (in_stack_000000f4 < 1) {
    *(undefined4 *)(extraout_ECX + 0x3498) = 1;
  }
  else if (0x40 < in_stack_000000f4) {
    *(undefined4 *)(extraout_ECX + 0x3498) = 0x40;
  }
  *(float *)(extraout_ECX + 0x349c) =
       (float)((float10)in_stack_000000f8 * (float10)in_stack_000000f8);
  fVar2 = _DAT_0059e43c / (float)(*(int *)(extraout_ECX + 0x3498) * 0x28);
  *(float *)(extraout_ECX + 0x34a0) = fVar2;
  *(float *)(extraout_ECX + 0x34a4) =
       _DAT_0059e43c / (float)((*(int *)(extraout_ECX + 0x3498) * 5 + 5) * 8);
  *(float *)(extraout_ECX + 0x34a8) = fVar2;
  *(float *)(extraout_ECX + 0x34ac) = (float)_DAT_008afea0;
  FUN_004e5f60();
  FUN_004e8010();
  if (param_10 != 0) {
    FUN_00587bcf();
  }
  if (param_8 != 0) {
    FUN_00587bcf();
  }
  if (param_6 != 0) {
    FUN_00587bcf();
  }
  if (param_4 != 0) {
    FUN_00587bcf();
  }
  if (param_2 != 0) {
    FUN_00587bcf();
  }
  if (unaff_ESI != 0) {
    FUN_00587bcf();
  }
  FUN_0042ddd0();
  if (in_stack_00001acc != 0) {
    FUN_00587bcf();
  }
  return;
}



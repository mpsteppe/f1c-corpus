// Function: FUN_0043e050 @ 0043e050
// Size (bytes): 478


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043e050(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBX;
  int in_stack_00001acc;
  undefined4 in_stack_0000378c;
  
  FUN_005881c0();
  *(undefined4 *)(extraout_ECX + 0x1f00) = in_stack_0000378c;
  iVar1 = FUN_00567740();
  *(undefined4 *)(extraout_ECX + 0x60) = 0;
  *(undefined4 *)(extraout_ECX + 100) = 0;
  *(double *)(extraout_ECX + 0x68) = _DAT_0059e420 / (double)(400 >> ((byte)DAT_007ce958 & 0x1f));
  _DAT_005e5240 = (double)(400 >> ((byte)DAT_007ce958 & 0x1f)) * _DAT_0059ec70;
  _DAT_005e5238 = _DAT_005e5240 * _DAT_005e5240;
  _DAT_005e5240 = _DAT_005e5240 + _DAT_005e5240;
  FUN_0042e320();
  FUN_004f34e0();
  FUN_004f4270();
  FUN_004f4270();
  FUN_00438da0();
  FUN_00439210();
  FUN_0043c250();
  FUN_00438cc0();
  FUN_00438f00();
  if (iVar1 != 0x200) {
    FUN_00567780();
  }
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
  if (unaff_EBX != 0) {
    FUN_00587bcf();
  }
  FUN_0042ddd0();
  if (in_stack_00001acc != 0) {
    FUN_00587bcf();
  }
  return;
}



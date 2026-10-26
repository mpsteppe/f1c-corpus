// Function: FUN_004efa40 @ 004efa40
// Size (bytes): 123


void __thiscall FUN_004efa40(int param_1,char param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x32bc) == 0) {
    FUN_004471f0();
    return;
  }
  if (param_2 == '\0') {
    uVar1 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    *(float *)(param_1 + 0x39b8) =
         *(float *)(&DAT_008ab274 + uVar1 * 4) * *(float *)(param_1 + 0x39c0) +
         *(float *)(param_1 + 0x39c4) + *(float *)(param_1 + 0x39bc);
  }
  else if (*(float *)(param_1 + 0x3994) < *(float *)(param_1 + 0x399c)) {
    *(undefined4 *)(param_1 + 0x3994) = *(undefined4 *)(param_1 + 0x399c);
    return;
  }
  return;
}



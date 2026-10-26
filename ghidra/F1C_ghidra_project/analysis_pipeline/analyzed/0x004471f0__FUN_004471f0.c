// Function: FUN_004471f0 @ 004471f0
// Size (bytes): 119


void __thiscall FUN_004471f0(int param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = *(double *)(param_1 + 0x1c5c) < *(double *)(param_1 + 0x1c84);
  *(undefined1 *)(param_1 + 0x1c59) = 1;
  if (param_2 == '\0') {
    if (bVar1) {
      uVar2 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      *(double *)(param_1 + 0x1d10) =
           (double)(*(float *)(&DAT_008ab274 + uVar2 * 4) * (float)*(double *)(param_1 + 0x1d20) +
                    (float)*(double *)(param_1 + 0x1d28) + (float)*(double *)(param_1 + 0x1d18));
    }
  }
  else if (bVar1) {
    *(undefined4 *)(param_1 + 0x1c5c) = *(undefined4 *)(param_1 + 0x1c84);
    *(undefined4 *)(param_1 + 0x1c60) = *(undefined4 *)(param_1 + 0x1c88);
    return;
  }
  return;
}



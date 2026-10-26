// Function: FUN_004ef930 @ 004ef930
// Size (bytes): 258


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ef930(int param_1,int param_2)

{
  *(undefined1 *)(param_1 + 0x39ec) = 0;
  if (*(char *)(param_1 + 0x39ee) == '\0') {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x3a08) = 0;
      *(undefined4 *)(param_1 + 0x3a04) = 0;
      *(undefined4 *)(param_1 + 0x39f0) = 0;
      return;
    }
    if (*(float *)(param_1 + 0x3a04) < DAT_0059e440 !=
        (*(float *)(param_1 + 0x3a04) == DAT_0059e440)) {
      if (*(int *)(param_1 + 0x39f0) < param_2) {
        FUN_004f88a0();
        *(undefined4 *)(param_1 + 0x3a04) = *(undefined4 *)(param_1 + 0x39fc);
        if ((param_2 == 1) && (*(int *)(param_1 + 0x39f0) == 0)) {
          *(undefined4 *)(param_1 + 0x3a08) = 1;
          *(undefined4 *)(param_1 + 0x39f0) = 0;
          *(undefined1 *)(param_1 + 0x39ec) = 1;
          return;
        }
      }
      else {
        FUN_004f89a0();
        *(undefined4 *)(param_1 + 0x3a04) = *(undefined4 *)(param_1 + 0x3a00);
        if ((((0 < param_2) && (DAT_0059e440 < *(float *)(param_1 + 0x3578))) &&
            (DAT_0059e440 < *(float *)(param_1 + 0x3978))) &&
           (*(float *)(param_1 + 0x3998) * _DAT_0059e450 < *(float *)(param_1 + 0x3994))) {
          FUN_004ef4f0();
        }
      }
      *(int *)(param_1 + 0x3a08) = param_2;
      *(undefined4 *)(param_1 + 0x39f0) = 0;
    }
  }
  return;
}



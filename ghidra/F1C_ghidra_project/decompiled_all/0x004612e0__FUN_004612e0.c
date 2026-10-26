// Function: FUN_004612e0 @ 004612e0
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, Applying frame time %.3f toward opening track (%.3f)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004612e0(int param_1)

{
  char cVar1;
  float local_4;
  
  if (((*(int *)(param_1 + 0x3fc4) != 2) && (*(int *)(param_1 + 0x3fc4) != 1)) &&
     (DAT_0059e440 <= *(float *)(param_1 + 0x2c))) {
    if (*(float *)(param_1 + 0x2c) == DAT_0059f0b4) {
      FUN_0045e570();
    }
    local_4 = (float)_DAT_008afe90;
    if (DAT_007c569c != 5) {
      cVar1 = FUN_004d7a50();
      if (cVar1 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_Applying_frame_time___3f_toward_o_005c6134,(double)local_4,
                     (double)*(float *)(param_1 + 0x2c));
      }
    }
    if (_DAT_0059e444 <= local_4) {
      if (_DAT_0059e450 < local_4) {
        local_4 = 0.5;
      }
    }
    else {
      local_4 = 0.01;
    }
    local_4 = *(float *)(param_1 + 0x2c) - local_4;
    *(float *)(param_1 + 0x2c) = local_4;
    if (local_4 < DAT_0059e440 != (local_4 == DAT_0059e440)) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined4 *)(param_1 + 0x2c) = 0xbf800000;
    }
  }
  return;
}



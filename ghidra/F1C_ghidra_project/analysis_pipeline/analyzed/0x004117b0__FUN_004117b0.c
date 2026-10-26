// Function: FUN_004117b0 @ 004117b0
// Size (bytes): 130


undefined4
FUN_004117b0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((-1 < param_1) && (param_1 < 2)) {
    uVar1 = 0;
    if (param_1 != 0) {
      if (param_1 != 1) {
        return 1;
      }
      *param_2 = DAT_005bf8d0;
      *param_3 = DAT_005bf8d4;
      *param_4 = &PTR_s_Audio_Commentary_Tv__005bf8e8;
      *param_5 = &PTR_s_Audio_Commentary_Tv__005bf8f0;
      return uVar1;
    }
    *param_2 = DAT_005bf8c8;
    *param_3 = DAT_005bf8cc;
    *param_4 = &PTR_s_Audio_Commentary_Pws__005bf8d8;
    *param_5 = &PTR_s_Audio_Commentary_Pws__005bf8e0;
  }
  return uVar1;
}



// Function: FUN_004a68b0 @ 004a68b0
// Size (bytes): 716


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a68b0(int *param_1,float param_2)

{
  float local_4;
  
  if (param_2 < (float)param_1[0x69]) {
    if (((char)param_1[0x6b] != '\0') &&
       ((float)param_1[0x69] - _DAT_0059e800 < param_2 !=
        ((float)param_1[0x69] - _DAT_0059e800 == param_2))) {
      *(undefined1 *)(param_1 + 0x6b) = 0;
      FUN_0040d410();
    }
    if ((param_1[0x70] != 0) && ((float)param_1[0x6d] < param_2)) {
      local_4 = (param_2 - (float)param_1[0x6d]) * _DAT_0059e96c + (float)param_1[0x6c];
      if ((float)param_1[0x6e] < local_4) {
        local_4 = (float)param_1[0x6e];
      }
      FUN_004f1890(local_4);
    }
    if (param_1[0x71] != 0) {
      if ((float)param_1[0x75] < param_2) {
        FUN_004f1ba0(0,0,0,0);
        return;
      }
      if (param_2 <= (float)param_1[0x74] + _DAT_0059e8cc) {
        if (param_2 <= (float)param_1[0x74] + _DAT_0059e7e8) {
          local_4 = 0.0;
        }
        else {
          local_4 = ((param_2 - (float)param_1[0x74]) - _DAT_0059e7e8) * _DAT_005acb64;
        }
      }
      else {
        local_4 = 0.096;
      }
      if (param_2 <= (float)param_1[0x74] + _DAT_0059e800) {
        if (param_2 <= (float)param_1[0x74] + _DAT_005acb60) {
          param_2 = 0.0;
        }
        else {
          param_2 = ((param_2 - (float)param_1[0x74]) - _DAT_005acb60) * _DAT_005acb64;
        }
      }
      else {
        param_2 = 0.096;
      }
      FUN_004f1ba0(local_4,local_4,param_2,param_2);
    }
  }
  else {
    if (param_1[0x70] != 0) {
      FUN_004f1890(param_1[0x6e]);
      if ((DAT_0059e440 < (float)param_1[0x6e]) && (*(int *)(*param_1 + 0x4068) == 9)) {
        *(undefined4 *)(*param_1 + 0x4068) = 0;
      }
    }
    FUN_004a5c80(4);
    param_1[0x6a] = (int)((float)_DAT_008afea0 - (float)param_1[0x68]);
    if ((*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) == param_1[1]) &&
       (*(int *)(*param_1 + 0x4064) != 1)) {
      FUN_004d8760(6,0);
    }
    if (*(int *)(*param_1 + 13000) == 1) {
      FUN_0042a6f0();
      FUN_00424cd0(0xf,0);
    }
    FUN_004f1ba0(0,0,0,0);
    FUN_004f1b50(0);
    if (param_1[2] != 0) {
      FUN_004a34a0(0);
      if ((0 < DAT_007cf884) && (*(char *)(*param_1 + 0x105c) != '\x01')) {
        *(undefined1 *)(*param_1 + 0x105c) = 1;
        FUN_004e0ed0();
        return;
      }
    }
  }
  return;
}



// Function: FUN_004f0d20 @ 004f0d20
// Size (bytes): 167


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f0d20(undefined4 *param_1)

{
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_34 = 0x3f800000;
  if (param_1[1] != *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894)) {
    FUN_004d1140(*param_1,&local_30,local_18);
    FUN_004efb20(&local_24,local_c);
    if ((local_30 - local_24) * (local_30 - local_24) +
        (local_2c - local_20) * (local_2c - local_20) +
        (local_28 - local_1c) * (local_28 - local_1c) < _DAT_0059e46c) {
      local_34 = DAT_007cf83c;
    }
  }
  FUN_004e2ca0(local_34);
  return;
}



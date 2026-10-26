// Function: FUN_0047daf0 @ 0047daf0
// Strings:  [Remove bookmark, Drop bookmark, Forward scan fast, Forward scan, PlayBackwards, Reverse scan, Reverse scan fast, Begin]


undefined4 * __thiscall FUN_0047daf0(undefined4 *param_1,int param_2)

{
  FUN_00488b00(1,0xffffffff);
  *param_1 = &PTR_LAB_005a6b20;
  param_1[0x3b] = param_2;
  if (param_2 == 0x1e0) {
    FUN_00486f30(s_Begin_005c7368,0xffffffff);
    FUN_00486f30(&PTR_DAT_005c7364,0xffffffff);
    FUN_00486f30(s_Reverse_scan_fast_005c7350,0xffffffff);
    FUN_00486f30(s_Reverse_scan_005c7340,0xffffffff);
    FUN_00486f30(s_PlayBackwards_005c7330,0xffffffff);
    FUN_00486f30(&DAT_005c7328,0xffffffff);
    FUN_00486f30(&DAT_005c7320,0xffffffff);
    FUN_00486f30(s_Forward_scan_005c7310,0xffffffff);
    FUN_00486f30(s_Forward_scan_fast_005c72fc,0xffffffff);
    FUN_00486f30(s_Drop_bookmark_005c72ec,0xffffffff);
    FUN_00486f30(s_Remove_bookmark_005c72dc,0xffffffff);
  }
  return param_1;
}



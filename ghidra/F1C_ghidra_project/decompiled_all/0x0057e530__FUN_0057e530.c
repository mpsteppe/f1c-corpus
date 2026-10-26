// Function: FUN_0057e530 @ 0057e530
// Strings:  [<HotPacket::Winsock>]


bool __fastcall FUN_0057e530(int param_1)

{
  bool bVar1;
  
  bVar1 = DAT_008d3e28 != (HWND)0x0;
  if (bVar1) {
    DestroyWindow(DAT_008d3e28);
    UnregisterClassA(PTR_s_<HotPacket_Winsock>_005e5374,*(HINSTANCE *)(param_1 + 0x774));
    DAT_008d3e28 = (HWND)0x0;
  }
  return bVar1;
}



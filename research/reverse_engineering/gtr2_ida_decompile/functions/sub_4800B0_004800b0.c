BOOL __fastcall sub_4800B0(char a1, char a2)
{
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  HWND DlgItem; // edi
  HWND v10; // esi
  const char *v12; // [esp-8h] [ebp-5B8h]
  char v13[4]; // [esp+Ch] [ebp-5A4h] BYREF
  CHAR v14[76]; // [esp+10h] [ebp-5A0h] BYREF
  char Buffer[4]; // [esp+5Ch] [ebp-554h] BYREF
  CHAR String[80]; // [esp+60h] [ebp-550h] BYREF
  LPARAM v17[64]; // [esp+B0h] [ebp-500h] BYREF
  LPARAM lParam[256]; // [esp+1B0h] [ebp-400h] BYREF

  String[0] = 0;
  v14[0] = 0;
  if ( !a2 )
  {
    memset(v17, 0, sizeof(v17));
    if ( SendDlgItemMessageA(hWnd, a1 != 0 ? 1000 : 1003, 0x191u, 0x100u, (LPARAM)lParam) == 1 )
    {
      SendDlgItemMessageA(hWnd, a1 != 0 ? 1000 : 1003, 0x189u, lParam[0], (LPARAM)v17);
      if ( sub_616840("SeasonRaces") )
      {
        v3 = sub_53B670(&unk_BE1CFD, v17);
        if ( v3 )
        {
          if ( sub_616630((char *)(v3 + 260)) )
          {
            v4 = sub_616630("TrackName");
            if ( v4 )
            {
              v5 = (const char *)sub_48D380(v4);
              sub_41D810(Buffer, 0x4Fu, "%s", v5);
            }
            v6 = sub_616630("Track Type");
            v7 = sub_616630("Length");
            if ( v6 && v7 )
            {
              v12 = (const char *)sub_48D380(v7);
              v8 = (const char *)sub_48D380(v6);
              sub_41D810(v13, 0x4Fu, "%s, %s", v8, v12);
            }
          }
        }
      }
    }
  }
  DlgItem = GetDlgItem(hWnd, 1041 - (a1 != 0));
  v10 = GetDlgItem(hWnd, 1046 - (a1 != 0));
  SetWindowTextA(DlgItem, String);
  return SetWindowTextA(v10, v14);
}

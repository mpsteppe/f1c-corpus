BOOL __fastcall sub_46BEE0(char a1, char a2)
{
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  HWND DlgItem; // edi
  HWND v10; // esi
  const char *v12; // [esp-4h] [ebp-5B0h]
  CHAR Buffer[80]; // [esp+Ch] [ebp-5A0h] BYREF
  CHAR String[80]; // [esp+5Ch] [ebp-550h] BYREF
  char v15[256]; // [esp+ACh] [ebp-500h] BYREF
  LPARAM lParam[256]; // [esp+1ACh] [ebp-400h] BYREF

  String[0] = 0;
  Buffer[0] = 0;
  if ( !a2 )
  {
    v15[0] = byte_629120;
    memset(&v15[1], 0, 255);
    if ( SendDlgItemMessageA(hWnd, a1 != 0 ? 1000 : 1003, 0x191u, 0x100u, (LPARAM)lParam) == 1 )
    {
      SendDlgItemMessageA(hWnd, a1 != 0 ? 1000 : 1003, 0x189u, lParam[0], (LPARAM)v15);
      if ( sub_57AE50(aSeasonraces) )
      {
        v3 = sub_4E8DD0(v15);
        if ( v3 )
        {
          if ( sub_57A720((char *)(v3 + 260)) )
          {
            v4 = sub_57A720(aTrackname_0);
            if ( v4 )
            {
              v5 = (const char *)sub_57A6D0(v4);
              sub_405480(String, 0x4Fu, "%s", v5);
            }
            v6 = sub_57A720(aTrackType);
            v7 = sub_57A720(aLength);
            if ( v6 && v7 )
            {
              v12 = (const char *)sub_57A6D0(v7);
              v8 = (const char *)sub_57A6D0(v6);
              sub_405480(Buffer, 0x4Fu, "%s, %s", v8, v12);
            }
          }
        }
      }
    }
  }
  DlgItem = GetDlgItem(hWnd, 1041 - (a1 != 0));
  v10 = GetDlgItem(hWnd, 1046 - (a1 != 0));
  SetWindowTextA(DlgItem, String);
  return SetWindowTextA(v10, Buffer);
}

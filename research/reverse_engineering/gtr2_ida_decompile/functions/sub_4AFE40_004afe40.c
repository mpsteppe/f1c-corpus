int __thiscall sub_4AFE40(_DWORD **this)
{
  int v2; // eax
  _BYTE *v3; // edx
  char v4; // cl
  bool v5; // zf
  _BYTE *v6; // eax
  char *v8; // [esp+4h] [ebp-214h]
  char v9[256]; // [esp+18h] [ebp-200h] BYREF
  _BYTE v10[252]; // [esp+118h] [ebp-100h] BYREF
  __int16 v11; // [esp+214h] [ebp-4h]
  char v12; // [esp+216h] [ebp-2h]

  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 54);
  if ( !v2 )
    return 0;
  v3 = (_BYTE *)sub_4CE170(v2);
  if ( !v3 )
    return 0;
  memset(v10, 0, sizeof(v10));
  v4 = *v3;
  v5 = *v3 == 9;
  v11 = 0;
  v12 = 0;
  if ( !v5 )
  {
    v6 = v3;
    do
    {
      v6[v10 - v3] = v4;
      v4 = *++v6;
    }
    while ( v4 != 9 );
  }
  sub_4ABBB0();
  sub_4DF020(this[12]);
  if ( !CGarageOnline::Connect((CGarageOnline *)dword_B6CBB8)
    || !CGarageOnline::FileExists((CGarageOnline *)dword_B6CBB8, v9) )
  {
    return 0;
  }
  if ( CGarageOnline::LocalFileExists((CGarageOnline *)dword_B6CBB8, v9) )
  {
    sub_4CD6D0("TIMETRIAL_ONLINE_DOWNLOAD_SETUP_OVERWRITE_CONFIRMATION");
  }
  else
  {
    v8 = sub_41D840(&byte_91CC38, "Downloading TimeTrial...");
    sub_4EB900(off_16C9A1C, v8);
    CGarageOnline::DownloadFile((CGarageOnline *)dword_B6CBB8, v9);
  }
  return -1;
}

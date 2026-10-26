int __thiscall sub_4AFD60(_DWORD **this)
{
  int v2; // eax
  int v4; // [esp+14h] [ebp-108h]
  char v5[256]; // [esp+1Ch] [ebp-100h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 49);
  if ( !v2 )
    return 0;
  if ( !sub_4CE170(v2) )
    return 0;
  sub_4ABA50();
  sub_4DF020(this[12]);
  if ( !CGarageOnline::FileExists((CGarageOnline *)dword_B6CBB4, v5) )
    return 0;
  if ( CGarageOnline::LocalFileExists((CGarageOnline *)dword_B6CBB4, v5) )
  {
    sub_4CD6D0("GARAGE_ONLINE_DOWNLOAD_SETUP_OVERWRITE_CONFIRMATION");
    return -1;
  }
  else
  {
    CGarageOnline::DownloadFile((CGarageOnline *)dword_B6CBB4, v5);
    if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 51) )
    {
      sub_437830();
      sub_48CB50(v4);
    }
    return -1;
  }
}

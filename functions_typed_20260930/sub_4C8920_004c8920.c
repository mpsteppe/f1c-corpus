void sub_4C8920()
{
  const char *v0; // eax
  float v1; // [esp+Ch] [ebp-220h]
  LPVOID v2[2]; // [esp+18h] [ebp-214h] BYREF
  int v3; // [esp+20h] [ebp-20Ch]
  int v4; // [esp+24h] [ebp-208h]
  char v5; // [esp+28h] [ebp-204h]
  _BYTE v6[509]; // [esp+2Ch] [ebp-200h] BYREF
  __int16 v7; // [esp+229h] [ebp-3h]
  char v8; // [esp+22Bh] [ebp-1h]

  if ( dword_8AC4CC && !(*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4CC + 8))(dword_8AC4CC) )
  {
    v2[0] = 0;
    v2[1] = (LPVOID)-1;
    StringCopyWithBufferRealloc(byte_5EA438);
    v6[0] = byte_5EA438[0];
    memset(&v6[1], 0, 0x1FCu);
    v7 = 0;
    v8 = 0;
    v0 = (const char *)dword_5EC3E0;
    v3 = -1;
    v4 = -1;
    v5 = 0;
    if ( !dword_5EC3E0 )
      v0 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v6, "%s%s", v0, aPitPitsoundsMp);
    StringCopyWithBufferRealloc(v6);
    v3 = -1;
    v4 = -1;
    v5 = 0;
    (*(void (__thiscall **)(int, LPVOID *, int, _DWORD))(*(_DWORD *)dword_8AC4CC + 4))(dword_8AC4CC, v2, 1, 0);
    v1 = flt_7CF3A4 * flt_7CF2CC;
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_8AC4CC + 28))(LODWORD(v1));
    if ( v2[0] )
      FreeWrapper_7bcf(v2[0]);
  }
}


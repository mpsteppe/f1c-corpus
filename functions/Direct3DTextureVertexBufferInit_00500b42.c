int __stdcall sub_500B42(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v12[10]; // [esp+4h] [ebp-50h] BYREF
  _BYTE v13[36]; // [esp+2Ch] [ebp-28h] BYREF
  _BYTE v14[4]; // [esp+50h] [ebp-4h] BYREF

  sub_506538(v14);
  v8 = 0;
  if ( a1 && a4 )
  {
    v9 = 1;
    if ( a1 == a4 )
      v9 = 65537;
    v10 = sub_506971(v12, a4, a5, a6, 0, v9);
    if ( v10 < 0 || (v10 = AudioSoundBufferSetup(a1, a2, a3, v12[0], v12[1], v12[2], v12[3], a5, v13, a7, a8), v10 < 0) )
      v8 = v10;
  }
  else
  {
    v8 = -2005530516;
  }
  ThunkToFUN0050653e(v14);
  return v8;
}

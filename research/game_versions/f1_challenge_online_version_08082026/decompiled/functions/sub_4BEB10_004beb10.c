void __thiscall sub_4BEB10(int this, _BYTE *a2, int a3)
{
  double v4; // st7
  int v5; // esi
  int i; // eax
  char v7; // [esp+Ah] [ebp-1C2h]
  char v8; // [esp+10h] [ebp-1BCh]

  *a2 = 0;
  v4 = *(float *)(this + 856);
  *(_DWORD *)(this + 860) = dword_8ACF8C;
  v5 = dword_5C329C;
  v7 = 1;
  *(_DWORD *)(this + 864) = dword_7C56A4;
  v8 = 0;
  if ( v4 <= 0.0 || *(float *)(this + 852) < (double)*(float *)(this + 856) )
  {
    if ( dword_7C56A4 == 7 )
    {
      for ( i = 0; i < v5; ++i )
      {
        if ( *(_DWORD *)(dword_7C54F0[i] + 16484) == 1 )
          v8 = 1;
      }
    }
  }
  else
  {
    v8 = 1;
    v7 = 0;
  }
  if ( !*(_BYTE *)(this + 834) )
    sub_4BF0A0(a3, v8);
  *(float *)(this + 852) = *(float *)(this + 852) + *(float *)(this + 848);
  if ( v7 )
  {
    if ( v5 > 0 )
      JUMPOUT(0x4BEC10);
    JUMPOUT(0x4BEEF2);
  }
  JUMPOUT(0x4BEF10);
}

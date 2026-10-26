int __thiscall sub_4E1520(int this, char a2)
{
  int v3; // ecx
  int v4; // eax
  int result; // eax
  _DWORD *i; // esi
  _DWORD *v7; // eax
  const CHAR *v8; // eax
  double v9; // st7

  v3 = *(_DWORD *)(this + 24);
  if ( !v3 )
  {
    v4 = sub_4DDFE0();
    sub_4DD980(&unk_B6E2A0, v4, 0, 0, *(_DWORD *)(v4 + 4), *(_DWORD *)(v4 + 8), 656386);
    sub_4DF290((_DWORD *)this, 0, (int)"No draw stack available", 0, 0, 0, 1);
    if ( a2 )
      sub_58FB60(&unk_FB1E98, 0);
    return -1;
  }
  if ( dword_75B17C && dword_75B17C != 3 && dword_75B17C != 5 )
    return -1;
  if ( !*(_BYTE *)(this + 36) )
  {
    for ( i = (_DWORD *)v3; ; i = (_DWORD *)i[23] )
    {
      v7 = (_DWORD *)i[17];
      if ( v7 )
      {
        if ( v7[4] - v7[3] >= 800 && v7[2] - v7[1] >= 600 )
          break;
      }
      if ( !i[23] )
        break;
    }
    sub_4E0EA0(v3);
    for ( ; i; i = (_DWORD *)i[22] )
      (*(void (__thiscall **)(_DWORD *))(*i + 24))(i);
    sub_4DE0A0();
    sub_4DFB90((_DWORD *)this);
    sub_4DFE50(this, (int)i);
    sub_4DE730(this);
  }
  if ( *(float *)(this + 64) <= 0.0 )
  {
    if ( a2 )
      sub_58FB60(&unk_FB1E98, 0);
    *(_BYTE *)(this + 36) = 0;
    return 0;
  }
  else
  {
    v8 = *(const CHAR **)(this + 56);
    if ( !v8 )
      v8 = WindowName;
    sub_4E1950(v8, 1);
    v9 = *(float *)(this + 64) - *(float *)(this + 268);
    *(_BYTE *)(this + 36) = 0;
    result = 0;
    *(float *)(this + 64) = v9;
  }
  return result;
}

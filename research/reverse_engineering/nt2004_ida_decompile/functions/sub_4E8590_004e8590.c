int __thiscall sub_4E8590(void *this, int a2)
{
  __int64 v2; // rax
  _DWORD *v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int *v7; // eax
  int v8; // eax

  if ( a2 < 0 )
    return 0;
  v2 = sub_577280(this);
  if ( SHIDWORD(v2) >= (int)v2 )
    return 0;
  sub_4E84F0(v3, SHIDWORD(v2));
  if ( v4 < *(_DWORD *)(v5 + 20) )
  {
    v6 = *(_DWORD *)(v5 + 8);
    if ( v4 <= 0 )
    {
LABEL_7:
      if ( v6 )
      {
        v7 = *(int **)v6;
        goto LABEL_10;
      }
    }
    else
    {
      while ( v6 )
      {
        v6 = *(_DWORD *)(v6 + 4);
        if ( --v4 <= 0 )
          goto LABEL_7;
      }
    }
  }
  v7 = 0;
LABEL_10:
  v8 = *v7;
  if ( v8 >= 0 && v8 < dword_7D6A58 )
    return dword_7D6A5C + 1232 * v8;
  return 0;
}

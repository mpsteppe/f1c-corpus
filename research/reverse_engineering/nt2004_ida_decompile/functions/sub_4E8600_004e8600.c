int __thiscall sub_4E8600(void *this, int a2)
{
  __int64 v2; // rax
  _DWORD *v3; // ecx
  int v4; // edx
  int v5; // ecx
  _DWORD *v6; // eax

  if ( a2 < 0 )
    return 0;
  v2 = sub_577280(this);
  if ( SHIDWORD(v2) >= (int)v2 )
    return 0;
  sub_4E84F0(v3, SHIDWORD(v2));
  if ( v4 >= *(_DWORD *)(v5 + 20) )
    return MEMORY[0];
  v6 = *(_DWORD **)(v5 + 8);
  if ( v4 > 0 )
  {
    while ( v6 )
    {
      v6 = (_DWORD *)v6[1];
      if ( --v4 <= 0 )
        goto LABEL_7;
    }
    return MEMORY[0];
  }
LABEL_7:
  if ( !v6 )
    return MEMORY[0];
  return *(_DWORD *)*v6;
}

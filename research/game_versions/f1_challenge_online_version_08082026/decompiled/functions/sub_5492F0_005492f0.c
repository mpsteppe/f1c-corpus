int __thiscall sub_5492F0(_DWORD *this, const char *a2)
{
  int v3; // esi
  _DWORD *v4; // eax
  char *v5; // eax
  int i; // eax
  _DWORD *v7; // eax
  const CHAR *v8; // esi

  v3 = this[62];
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 20); i; i = *(_DWORD *)(i + 20) )
      v3 = i;
    v7 = (_DWORD *)sub_587C03(24);
    if ( v7 )
      v5 = (char *)sub_548E00(v7);
    else
      v5 = 0;
    *(_DWORD *)(v3 + 20) = v5;
  }
  else
  {
    v4 = (_DWORD *)sub_587C03(24);
    if ( v4 )
    {
      v5 = (char *)sub_548E00(v4);
      this[62] = v5;
    }
    else
    {
      v5 = 0;
      this[62] = 0;
    }
  }
  v8 = v5;
  strcpy(v5, a2);
  return sub_589901(v8);
}

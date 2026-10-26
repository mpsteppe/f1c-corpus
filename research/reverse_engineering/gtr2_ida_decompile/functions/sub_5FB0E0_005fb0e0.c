int __thiscall sub_5FB0E0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  _DWORD *v8; // eax

  v5 = (_DWORD *)this[72];
  this[74] = v5;
  if ( !v5 )
    return 0;
  v6 = (_DWORD *)*v5;
  if ( !v6 )
    return 0;
  while ( v6[2] != a2 || v6[3] != a3 || v6[5] != a4 || a5 && v6[6] != a5 )
  {
    v7 = this[74];
    if ( v7 )
      this[74] = *(_DWORD *)(v7 + 4);
    v8 = (_DWORD *)this[74];
    if ( v8 )
    {
      v6 = (_DWORD *)*v8;
      if ( v6 )
        continue;
    }
    return 0;
  }
  return v6[1];
}

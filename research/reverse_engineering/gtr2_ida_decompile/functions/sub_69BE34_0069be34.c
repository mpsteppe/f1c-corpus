int __thiscall sub_69BE34(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // edx
  int result; // eax

  v3 = sub_69BD09(this, a2);
  v4 = v3;
  if ( !v3 )
    return -2147467259;
  v5 = v3[4];
  if ( !v5 || *(_DWORD *)(v5 + 4) != 9 || !sub_695130(v4[4]) )
    return -2147467259;
  result = sub_698043(a3, (double *)(*(_DWORD *)(*(_DWORD *)(v6 + 32) + 8) + 16), v6 + 48);
  if ( result >= 0 )
    return 0;
  return result;
}

unsigned int __thiscall sub_65DA50(_DWORD *this, _BYTE *a2, _DWORD *a3)
{
  _BYTE *i; // edi
  unsigned int v5; // edi
  void *v6; // eax

  if ( (unsigned int)a2 >= this[1] || !sub_633848() && *a2 != 95 )
    return 0;
  for ( i = a2 + 1; (unsigned int)i < this[1] && (isalnum((char)*i) || *i == 95); ++i )
    ;
  v5 = i - a2;
  v6 = (void *)sub_67EB7E(v5 + 1, 1u);
  if ( !v6 )
    return 0;
  qmemcpy(v6, a2, v5);
  *((_BYTE *)v6 + v5) = 0;
  *a3 = v6;
  return v5;
}

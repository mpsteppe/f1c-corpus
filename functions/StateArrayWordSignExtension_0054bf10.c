void __thiscall sub_54BF10(_DWORD *this, int a2)
{
  _DWORD *i; // ecx
  int v3; // eax
  int j; // edx
  unsigned int v5; // esi

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    v3 = i[71];
    for ( j = 0; j < i[70]; ++j )
    {
      v5 = *(_DWORD *)v3 & 0xFFFF0000;
      *(_DWORD *)v3 = v5;
      *(_DWORD *)v3 = v5 | *(__int16 *)(v3 + 2);
    }
  }
}

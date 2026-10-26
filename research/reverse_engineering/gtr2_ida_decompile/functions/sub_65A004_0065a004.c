int __thiscall sub_65A004(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // eax

  v3 = operator new(0xCu);
  v4 = a2;
  if ( v3 )
    v5 = sub_659F73(v3, a2);
  else
    v5 = 0;
  if ( !v5 )
    return -2147024882;
  v5[1] = this[26];
  this[26] = v5;
  this[166] = v4;
  return 0;
}

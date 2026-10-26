int __thiscall sub_62C280(_DWORD *this)
{
  _DWORD *v1; // esi
  bool v2; // sf
  int v3; // ecx

  if ( !this )
    return -2;
  v1 = (_DWORD *)this[7];
  if ( !v1 || !this[8] || !this[9] )
    return -2;
  this[5] = 0;
  this[2] = 0;
  this[6] = 0;
  this[11] = 2;
  v1[4] = v1[2];
  v2 = (int)v1[6] < 0;
  v1[5] = 0;
  if ( v2 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  this[12] = 1;
  *(_DWORD *)((char *)v1 + 30) = 0;
  sub_62DF50(v1);
  sub_62B590(v3, (int)v1);
  return 0;
}

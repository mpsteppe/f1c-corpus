int __thiscall sub_49F6F0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  v2 = this[100] + this[94];
  this[94] = v2;
  v3 = this[99];
  if ( v3 < v2 )
    v2 = v3;
  this[94] = v2;
  sub_49FF10(this);
  sub_4A0090(this);
  return 0;
}

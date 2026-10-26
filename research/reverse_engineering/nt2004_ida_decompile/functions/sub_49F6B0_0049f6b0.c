int __thiscall sub_49F6B0(_DWORD *this)
{
  int v2; // ecx

  v2 = this[94] - this[100];
  this[94] = v2;
  this[94] = v2 < 0 ? 0 : v2;
  sub_49FF10(this);
  sub_4A0090(this);
  return 0;
}

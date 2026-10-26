int __thiscall sub_489560(_DWORD *this)
{
  int v2; // edx

  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  v2 = this[83] - this[89];
  this[83] = v2;
  this[83] = v2 < 0 ? 0 : v2;
  sub_489D00(this);
  FloatToIntConversion(this);
  return 0;
}

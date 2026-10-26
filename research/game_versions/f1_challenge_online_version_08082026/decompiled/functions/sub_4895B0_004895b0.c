int __thiscall sub_4895B0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  v2 = this[89] + this[83];
  v3 = this[88];
  this[83] = v2;
  if ( v3 < v2 )
    v2 = v3;
  this[83] = v2;
  sub_489D00(this);
  sub_489E90(this);
  return 0;
}

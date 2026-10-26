int __thiscall UtilityFunction_d1a0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax

  v3 = this[202] - 1;
  v4 = 2 * (a2 == 1) - 1 + this[206];
  this[206] = v4;
  *((_BYTE *)this + 828) = a2 == 1;
  if ( v4 < 0 )
    v4 = v3;
  this[206] = v4;
  this[206] = v4 > v3 ? 0 : v4;
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return (*(int (__thiscall **)(_DWORD *, int, _DWORD))(*this + 188))(this, a2, this[206]);
}


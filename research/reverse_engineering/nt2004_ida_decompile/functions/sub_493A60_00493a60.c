_DWORD *__thiscall sub_493A60(_DWORD *this, char a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  *this = &off_5D6D68;
  v3 = this[71];
  while ( v3 )
  {
    v4 = (_DWORD *)v3;
    v5 = *(_BYTE *)(v3 + 12) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_5BE8AE(v4);
  }
  this[71] = 0;
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  sub_49C520(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}

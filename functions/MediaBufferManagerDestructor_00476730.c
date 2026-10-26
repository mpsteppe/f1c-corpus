LPVOID *__thiscall sub_476730(LPVOID *this, char a2)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  if ( this[98] )
    FreeWrapper_7bcf(this[98]);
  *this = &off_5A4550;
  v3 = this[60];
  while ( v3 )
  {
    v4 = v3;
    v5 = *((_BYTE *)v3 + 12) == 0;
    v3 = (_DWORD *)v3[1];
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    FreeWrapper_7bcf(v4);
  }
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  this[63] = 0;
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

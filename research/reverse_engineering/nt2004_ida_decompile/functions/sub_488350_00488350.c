_DWORD *__thiscall sub_488350(_DWORD *this, char a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  *this = &off_5DC668;
  v3 = this[216];
  while ( v3 )
  {
    v4 = (_DWORD *)v3;
    v5 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_5BE8AE(v4);
  }
  this[216] = 0;
  this[217] = 0;
  this[218] = 0;
  this[219] = 0;
  sub_4A2330(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}

// Address: 0x00476730
// Size: 139 bytes
// Name: sub_476730
// Type: LPVOID *__thiscall(LPVOID *this, char)
// Source: IDA Hex-Rays decompilation

LPVOID *__thiscall sub_476730(LPVOID *this, char a2)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  if ( this[98] )
    sub_587BCF(this[98]);
  *this = &off_5A4550;
  v3 = this[60];
  while ( v3 )
  {
    v4 = v3;
    v5 = *((_BYTE *)v3 + 12) == 0;
    v3 = (_DWORD *)v3[1];
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_587BCF(v4);
  }
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  this[63] = 0;
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}

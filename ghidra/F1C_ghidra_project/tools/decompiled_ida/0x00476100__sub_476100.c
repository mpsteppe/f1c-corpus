// Address: 0x00476100
// Size: 154 bytes
// Name: sub_476100
// Type: LPVOID *__thiscall(LPVOID *this, char)
// Source: IDA Hex-Rays decompilation

LPVOID *__thiscall sub_476100(LPVOID *this, char a2)
{
  _DWORD *v3; // esi
  _DWORD *v4; // ebp
  bool v5; // zf

  *this = &off_5A4464;
  if ( this[20] )
    sub_587BCF(this[20]);
  v3 = this[15];
  while ( v3 )
  {
    v4 = v3;
    v5 = *((_BYTE *)v3 + 12) == 0;
    v3 = (_DWORD *)v3[1];
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_587BCF(v4);
  }
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  this[18] = 0;
  *this = &off_5A4450;
  if ( this[12] )
    sub_587BCF(this[12]);
  *this = &off_5A443C;
  if ( this[1] )
    sub_587BCF(this[1]);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}

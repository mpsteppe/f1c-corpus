// Address: 0x0048aaa0
// Size: 132 bytes
// Name: sub_48AAA0
// Type: _DWORD *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

_DWORD *__thiscall sub_48AAA0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[59];
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        if ( *v6 )
          sub_587BCF(*v6);
        sub_587BCF(v6);
      }
    }
    sub_587BCF(v4);
  }
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  sub_488B30(this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}

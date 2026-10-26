// Address: 0x00408800
// Size: 104 bytes
// Name: sub_408800
// Type: char *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

char *__thiscall sub_408800(_DWORD *this, char a2)
{
  int v3; // eax
  char *v4; // ebp
  char *v5; // esi
  int v6; // eax
  int v7; // edi

  if ( (a2 & 2) != 0 )
  {
    v3 = *(this - 1);
    v4 = (char *)(this - 1);
    v5 = (char *)&this[50 * v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 200;
        sub_4562A0(v5);
        --v7;
      }
      while ( v7 );
    }
    if ( (a2 & 1) != 0 )
      sub_587BCF(v4);
    return v4;
  }
  else
  {
    sub_4562A0(this);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this);
    return (char *)this;
  }
}

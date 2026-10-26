int __thiscall sub_49C520(LPVOID *this)
{
  _DWORD *v2; // edi
  void *v3; // ebx
  _DWORD *v4; // edi
  void *v5; // ebx
  _BYTE *v6; // edi
  _BYTE *v7; // ebx
  _BYTE *v8; // edi
  _BYTE *v9; // ebx

  *this = &off_5E9358;
  sub_49C780();
  if ( this[56] )
    sub_5BE8AE(this[56]);
  if ( this[53] )
    sub_5BE8AE(this[53]);
  if ( this[50] )
    sub_5BE8AE(this[50]);
  if ( this[48] )
    sub_5BE8AE(this[48]);
  if ( this[46] )
    sub_5BE8AE(this[46]);
  if ( this[44] )
    sub_5BE8AE(this[44]);
  if ( this[42] )
    sub_5BE8AE(this[42]);
  if ( this[40] )
    sub_5BE8AE(this[40]);
  v2 = this[28];
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[1];
    sub_4A82F0(v3);
    sub_5BE8AE(v3);
  }
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  v4 = this[21];
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[1];
    sub_4A8120(v5);
    sub_5BE8AE(v5);
  }
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  v6 = this[17];
  while ( v6 )
  {
    v7 = v6;
    v6 = (_BYTE *)*((_DWORD *)v6 + 1);
    sub_4145A0(v7);
    sub_5BE8AE(v7);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  v8 = this[13];
  while ( v8 )
  {
    v9 = v8;
    v8 = (_BYTE *)*((_DWORD *)v8 + 1);
    sub_4145A0(v9);
    sub_5BE8AE(v9);
  }
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  return sub_4B13D0(this);
}

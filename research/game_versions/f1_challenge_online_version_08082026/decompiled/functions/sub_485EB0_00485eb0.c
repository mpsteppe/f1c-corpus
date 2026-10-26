int __thiscall sub_485EB0(LPVOID *this)
{
  LPVOID *v2; // edi
  LPVOID *v3; // ebp
  char v4; // al
  LPVOID **v5; // edi
  LPVOID **v6; // ebp
  char v7; // al
  LPVOID *v8; // ebx
  LPVOID **v9; // edi
  LPVOID **v10; // ebx
  char v11; // al
  LPVOID *v12; // ebp

  *this = &off_5AB8C0;
  sub_486080();
  if ( this[48] )
    sub_587BCF(this[48]);
  if ( this[46] )
    sub_587BCF(this[46]);
  if ( this[44] )
    sub_587BCF(this[44]);
  if ( this[42] )
    sub_587BCF(this[42]);
  if ( this[40] )
    sub_587BCF(this[40]);
  v2 = (LPVOID *)this[28];
  while ( v2 )
  {
    v3 = v2;
    v4 = *((_BYTE *)v2 + 8);
    v2 = (LPVOID *)v2[1];
    if ( v4 )
      sub_587BCF(*v3);
    sub_587BCF(v3);
  }
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  v5 = (LPVOID **)this[21];
  while ( v5 )
  {
    v6 = v5;
    v7 = *((_BYTE *)v5 + 8);
    v5 = (LPVOID **)v5[1];
    if ( v7 )
    {
      v8 = *v6;
      if ( *v6 )
      {
        sub_414370(*v6);
        sub_587BCF(v8);
      }
    }
    sub_587BCF(v6);
  }
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  v9 = (LPVOID **)this[17];
  while ( v9 )
  {
    v10 = v9;
    v11 = *((_BYTE *)v9 + 8);
    v9 = (LPVOID **)v9[1];
    if ( v11 )
    {
      v12 = *v10;
      if ( *v10 )
      {
        if ( *v12 )
          sub_587BCF(*v12);
        sub_587BCF(v12);
      }
    }
    sub_587BCF(v10);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  return sub_49A990(this);
}

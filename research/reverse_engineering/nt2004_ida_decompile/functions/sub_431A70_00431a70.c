CHAR *__thiscall sub_431A70(int this)
{
  CHAR *v2; // eax
  CHAR v3; // cl
  CHAR *v4; // eax
  CHAR v5; // cl
  CHAR *v6; // eax
  CHAR v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // cl
  int v14; // eax
  char v15; // cl
  CHAR *result; // eax
  CHAR v17; // cl
  CHAR *v18; // eax
  CHAR v19; // cl
  char v20[64]; // [esp+8h] [ebp-C0h] BYREF
  char v21[64]; // [esp+48h] [ebp-80h] BYREF
  char v22[64]; // [esp+88h] [ebp-40h] BYREF

  if ( sub_41F230(dword_62A170, off_5FD854, Destination) )
  {
    strncpy(Destination, off_5FD854, 0x1FFu);
    byte_62A37B = 0;
  }
  v2 = Destination;
  do
  {
    v3 = *v2;
    v2[this - (_DWORD)Destination + 40] = *v2;
    ++v2;
  }
  while ( v3 );
  if ( *(_DWORD *)(this + 4) )
  {
    if ( sub_41F230(dword_62A170, off_5FD824, Destination) )
      sub_431E20(Destination, off_5FD824, 0x1FFu);
    v18 = Destination;
    do
    {
      v19 = *v18;
      v18[this - (_DWORD)Destination + 8] = *v18;
      ++v18;
    }
    while ( v19 );
    strcpy((char *)(this + 24), (const char *)sub_431E40(aIn));
    strcpy(v21, (const char *)sub_431E40(off_5FD79C));
    strcpy(v20, (const char *)sub_431E40(aIn));
    sprintf((char *const)(this + 56), "%s/%s", v21, v20);
    strcpy(v22, (const char *)sub_431E40(aS_1));
    sprintf((char *const)(this + 72), "%s/%s/%s", v21, v20, v22);
    strcpy((char *)(this + 88), (const char *)sub_431E40(off_5FD81C));
  }
  else
  {
    if ( sub_41F230(dword_62A170, off_5FD850, Destination) )
    {
      strncpy(Destination, off_5FD850, 0x1FFu);
      byte_62A37B = 0;
    }
    v4 = Destination;
    do
    {
      v5 = *v4;
      v4[this - (_DWORD)Destination + 8] = *v4;
      ++v4;
    }
    while ( v5 );
    if ( sub_41F230(dword_62A170, aCm, Destination) )
    {
      strncpy(Destination, aCm, 0x1FFu);
      byte_62A37B = 0;
    }
    v6 = Destination;
    do
    {
      v7 = *v6;
      v6[this - (_DWORD)Destination + 24] = *v6;
      ++v6;
    }
    while ( v7 );
    if ( sub_41F230(dword_62A170, aN, Destination) )
    {
      strncpy(Destination, aN, 0x1FFu);
      byte_62A37B = 0;
    }
    v8 = 0;
    do
    {
      v9 = Destination[v8];
      v21[v8++] = v9;
    }
    while ( v9 );
    if ( sub_41F230(dword_62A170, aMm, Destination) )
      sub_431E20(Destination, aMm, 0x1FFu);
    v10 = 0;
    do
    {
      v11 = Destination[v10];
      v20[v10++] = v11;
    }
    while ( v11 );
    sprintf((char *const)(this + 56), "%s/%s", v21, v20);
    if ( sub_41F230(dword_62A170, aM, Destination) )
      sub_431E20(Destination, aM, 0x1FFu);
    v12 = 0;
    do
    {
      v13 = Destination[v12];
      v20[v12++] = v13;
    }
    while ( v13 );
    if ( sub_41F230(dword_62A170, aS_1, Destination) )
      sub_431E20(Destination, aS_1, 0x1FFu);
    v14 = 0;
    do
    {
      v15 = Destination[v14];
      v22[v14++] = v15;
    }
    while ( v15 );
    sprintf((char *const)(this + 72), "%s/%s/%s", v21, v20, v22);
    if ( sub_41F230(dword_62A170, asc_5FD828, Destination) )
      sub_431E20(Destination, asc_5FD828, 0x1FFu);
    result = Destination;
    do
    {
      v17 = *result;
      result[this - (_DWORD)Destination + 88] = *result;
      ++result;
    }
    while ( v17 );
  }
  return result;
}

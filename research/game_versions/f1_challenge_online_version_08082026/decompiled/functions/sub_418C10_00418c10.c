LPVOID **__thiscall sub_418C10(LPVOID **this, char a2)
{
  LPVOID *v3; // edi
  LPVOID *v4; // esi
  int v5; // ebx
  void *v6; // eax
  LPVOID *v7; // esi
  int v8; // ebx
  void *v9; // eax
  LPVOID *v10; // esi
  int v11; // ebx
  void *v12; // eax
  LPVOID *v13; // esi
  int v14; // ebx
  void *v15; // eax

  if ( *((_BYTE *)this + 8) )
  {
    v3 = *this;
    if ( *this )
    {
      sub_414D70((int)v3);
      v4 = v3 + 43;
      v5 = 2;
      do
      {
        v6 = *(v4 - 5);
        v4 -= 5;
        if ( v6 )
          sub_587BCF(v6);
        --v5;
      }
      while ( v5 );
      v7 = v3 + 33;
      v8 = 2;
      do
      {
        v9 = *(v7 - 5);
        v7 -= 5;
        if ( v9 )
          sub_587BCF(v9);
        --v8;
      }
      while ( v8 );
      v10 = v3 + 23;
      v11 = 2;
      do
      {
        v12 = *(v10 - 5);
        v10 -= 5;
        if ( v12 )
          sub_587BCF(v12);
        --v11;
      }
      while ( v11 );
      v13 = v3 + 13;
      v14 = 2;
      do
      {
        v15 = *(v13 - 5);
        v13 -= 5;
        if ( v15 )
          sub_587BCF(v15);
        --v14;
      }
      while ( v14 );
      if ( *v3 )
        sub_587BCF(*v3);
      sub_587BCF(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}

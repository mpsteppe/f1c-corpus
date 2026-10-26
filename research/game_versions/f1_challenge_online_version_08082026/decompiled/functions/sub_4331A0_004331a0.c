int __thiscall sub_4331A0(int this)
{
  int v2; // ebp
  int result; // eax
  LPVOID **v4; // ebx
  char v5; // cl
  LPVOID *v6; // esi
  int v7; // esi
  LPVOID *v8; // ebp
  char v9; // al

  sub_566650(&byte_5EA438);
  sub_566650(&byte_5EA438);
  sub_566650(&byte_5EA438);
  *(_BYTE *)(this + 24) = 0;
  v2 = *(_DWORD *)(this + 28);
  for ( result = 0; v2; result = 0 )
  {
    v4 = (LPVOID **)v2;
    v5 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        sub_432CC0(*v4);
        if ( v6[5] )
          sub_587BCF(v6[5]);
        if ( v6[2] )
          sub_587BCF(v6[2]);
        if ( *v6 )
          sub_587BCF(*v6);
        sub_587BCF(v6);
      }
    }
    sub_587BCF(v4);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_BYTE *)(this + 44) = 0;
  v7 = *(_DWORD *)(this + 48);
  if ( v7 )
  {
    do
    {
      v8 = (LPVOID *)v7;
      v9 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v9 )
        sub_587BCF(*v8);
      sub_587BCF(v8);
    }
    while ( v7 );
    result = 0;
  }
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  return result;
}

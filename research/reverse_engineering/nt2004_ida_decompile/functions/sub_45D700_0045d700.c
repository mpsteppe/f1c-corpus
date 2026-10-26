const char *__thiscall sub_45D700(_BYTE *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // ebx
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax

  *this = rand() % 247 + 8;
  this[1] = rand();
  v2 = *((_DWORD *)this + 1);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        sub_40D5B0(*v3);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  v6 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v6 = &byte_629120;
  sub_45D570((int)this, aGdb, v6, 3);
  v7 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v7 = &byte_629120;
  sub_45D570((int)this, aHdv, v7, 1);
  v8 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v8 = &byte_629120;
  sub_45D570((int)this, aTbc, v8, 2);
  v9 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v9 = &byte_629120;
  return sub_45D570((int)this, aTerrainIni, v9, 0);
}

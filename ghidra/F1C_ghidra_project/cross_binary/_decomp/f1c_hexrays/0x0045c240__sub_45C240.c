// f1c  0x0045c240  size=216
const char *__thiscall sub_45C240(_BYTE *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax

  *this = sub_5884ED(this) % 247 + 8;
  this[1] = sub_5884ED(247);
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
        if ( *v5 )
          sub_587BCF(*v5);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  v6 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v6 = byte_5EA438;
  sub_45C0C0((int)this, aGdb, v6, 2);
  v7 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v7 = byte_5EA438;
  sub_45C0C0((int)this, aHdv_0, v7, 1);
  v8 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v8 = byte_5EA438;
  return sub_45C0C0((int)this, aTerrainIni, v8, 0);
}

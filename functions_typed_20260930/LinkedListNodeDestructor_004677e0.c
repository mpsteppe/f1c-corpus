_DWORD *__thiscall sub_4677E0(_DWORD *this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = this[62];
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
          FreeWrapper_7bcf(*v6);
        FreeWrapper_7bcf(v6);
      }
    }
    FreeWrapper_7bcf(v4);
  }
  this[62] = 0;
  this[63] = 0;
  this[64] = 0;
  this[65] = 0;
  VTableSetCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}


void __thiscall sub_581820(int *this)
{
  int v2; // esi
  int v3; // edi

  if ( *((_BYTE *)this + 24) && CloseHandle((HANDLE)this[4]) )
    this[4] = 0;
  v2 = *this;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
      FreeWrapper_7bcf(*(LPVOID *)v3);
    FreeWrapper_7bcf((LPVOID)v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}


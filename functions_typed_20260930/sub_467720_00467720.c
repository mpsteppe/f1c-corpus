_DWORD *__thiscall sub_467720(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ebx
  char v4; // al
  LPVOID *v5; // ebp

  InitWithVTableFlags((int)this, 0, 0);
  this[62] = 0;
  this[63] = 0;
  this[64] = 0;
  this[65] = 0;
  *this = &off_59F5B8;
  this[57] = 0;
  this[58] = 0;
  this[59] = 0;
  this[60] = 0;
  v2 = this[62];
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
          FreeWrapper_7bcf(*v5);
        FreeWrapper_7bcf(v5);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  this[62] = 0;
  this[63] = 0;
  this[64] = 0;
  this[65] = 0;
  this[66] = 0;
  *((_BYTE *)this + 244) = 0;
  *((_BYTE *)this + 245) = 0;
  return this;
}


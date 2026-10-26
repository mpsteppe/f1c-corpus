int __thiscall sub_4C62C0(_DWORD *this)
{
  int result; // eax
  int i; // esi
  _DWORD *v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  result = StringCopyWithBufferRealloc(byte_5EA438);
  for ( i = this[2]; i; result = FreeWrapper_7bcf(v4) )
  {
    v4 = (_DWORD *)i;
    v5 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v5 )
    {
      v6 = (LPVOID *)*v4;
      if ( *v4 )
      {
        if ( v6[1] )
          FreeWrapper_7bcf(v6[1]);
        FreeWrapper_7bcf(v6);
      }
    }
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  return result;
}

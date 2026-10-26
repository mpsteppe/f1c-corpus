int __thiscall sub_567A30(_DWORD *this)
{
  LPVOID **v2; // esi
  LPVOID **v3; // ebp
  LPVOID *v4; // edi
  int result; // eax

  F_9PointerArrayCleanup(this);
  v2 = (LPVOID **)this[9];
  while ( v2 )
  {
    v3 = v2;
    v2 = (LPVOID **)v2[1];
    if ( *((_BYTE *)v3 + 8) )
    {
      v4 = *v3;
      if ( *v3 )
      {
        if ( *v4 )
          FreeWrapper_7bcf(*v4);
        FreeWrapper_7bcf(v4);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  result = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  return result;
}

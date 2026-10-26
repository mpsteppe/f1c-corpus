char sub_57AA80()
{
  char result; // al
  int v1; // esi
  _BYTE *v2; // edi
  void *v3; // ebp

  result = 1;
  if ( (byte_8D3BFB & 1) == 0 )
  {
    v1 = dword_8D3BFC;
    for ( byte_8D3BFB |= 1u; v1; result = FreeWrapper_7bcf(v2) )
    {
      v2 = (_BYTE *)v1;
      v1 = *(_DWORD *)(v1 + 4);
      if ( v2[12] )
      {
        v3 = *(void **)v2;
        if ( *(_DWORD *)v2 )
        {
          VTableDestructorThenNullPointer(*(_DWORD **)v2);
          FreeWrapper_7bcf(v3);
        }
      }
    }
    dword_8D3BFC = 0;
    dword_8D3C00 = 0;
    dword_8D3C04 = 0;
    dword_8D3C08 = 0;
  }
  return result;
}


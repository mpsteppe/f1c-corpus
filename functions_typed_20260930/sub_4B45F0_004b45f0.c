char sub_4B45F0()
{
  char result; // al
  int v1; // esi
  LPVOID *v2; // edi
  bool v3; // zf
  int v4; // esi
  _DWORD *v5; // edi
  LPVOID *v6; // ebp

  result = 1;
  if ( (byte_8AB6E0 & 1) == 0 )
  {
    v1 = dword_8AB700;
    for ( byte_8AB6E0 |= 1u; v1; result = FreeWrapper_7bcf(v2) )
    {
      v2 = (LPVOID *)v1;
      v3 = *(_BYTE *)(v1 + 8) == 0;
      v1 = *(_DWORD *)(v1 + 4);
      if ( !v3 )
        FreeWrapper_7bcf(*v2);
    }
    v4 = dword_8AB6F0;
    dword_8AB700 = 0;
    dword_8AB704 = 0;
    dword_8AB708 = 0;
    for ( dword_8AB70C = 0; v4; result = FreeWrapper_7bcf(v5) )
    {
      v5 = (_DWORD *)v4;
      v3 = *(_BYTE *)(v4 + 8) == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v3 )
      {
        v6 = (LPVOID *)*v5;
        if ( *v5 )
        {
          FreeWrapper_7bcf(*v6);
          FreeWrapper_7bcf(v6);
        }
      }
    }
    dword_8AB6F0 = 0;
    dword_8AB6F4 = 0;
    dword_8AB6F8 = 0;
    dword_8AB6FC = 0;
  }
  return result;
}


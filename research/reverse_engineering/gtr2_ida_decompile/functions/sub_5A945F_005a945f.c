int __stdcall sub_5A945F(int a1, int a2, unsigned int a3)
{
  unsigned int i; // ebx
  unsigned __int16 v4; // dx
  int v5; // ecx
  int v6; // edi
  int j; // edx
  unsigned int v8; // ecx
  int v9; // edx

  for ( i = 0; i < a3; ++i )
  {
    v4 = *(_WORD *)(a2 + 2 * i);
    v5 = v4;
    if ( (v4 & 0x7C00) != 0 )
    {
      v9 = ((((v4 >> 10) & 0x1F) + 112) << 23) | ((v4 & 0x3FF | (8 * (v4 & 0x8000))) << 13);
    }
    else
    {
      if ( (v4 & 0x3FF) != 0 )
      {
        v6 = -14;
        for ( j = v4 & 0x3FF; (j & 0x400) == 0; j *= 2 )
          --v6;
        v8 = ((v6 + 127) << 23) | (((j | (8 * (v5 & 0xFFFF8080))) & 0xFFFFFBFF) << 13);
      }
      else
      {
        v8 = (v4 & 0x8000) << 16;
      }
      v9 = v8;
    }
    *(_DWORD *)(a1 + 4 * i) = v9;
  }
  return a1;
}

char __cdecl sub_58E000(int a1)
{
  int v1; // ecx
  unsigned int v2; // eax
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // ebp
  __int16 *v6; // esi
  int v8; // [esp+10h] [ebp-4h]

  v1 = a1;
  LOBYTE(v2) = 96 * a1;
  v3 = dword_7FFAA4[24 * a1];
  v4 = (unsigned __int16)word_7FFAA8[48 * a1];
  v5 = 0;
  v8 = (unsigned __int8)byte_7FFAAB[96 * a1];
  dword_7FFAA0 = 0;
  v6 = word_7FFAAC;
  do
  {
    if ( v5 != v1 )
    {
      LOBYTE(v2) = *((_BYTE *)v6 - 2);
      if ( (_BYTE)v2 )
      {
        v2 = *((unsigned __int8 *)v6 - 1);
        if ( v2 == v8 && !*v6 )
        {
          v2 = *((_DWORD *)v6 - 2);
          if ( v2 < v3 || v2 == v3 && (unsigned __int16)*(v6 - 2) < v4 )
          {
            if ( (*(_BYTE *)(*((_DWORD *)v6 + 1) + 10) & 4) == 0 )
            {
              LOBYTE(v2) = sub_58DB10(v5);
              v1 = a1;
            }
          }
          else
          {
            v2 = *((_DWORD *)v6 + 1);
            if ( *(_BYTE *)(v2 + 9) == 100 )
              dword_7FFAA0 = 1;
          }
        }
      }
    }
    v6 += 48;
    ++v5;
  }
  while ( (int)v6 < (int)word_8000AC );
  return v2;
}

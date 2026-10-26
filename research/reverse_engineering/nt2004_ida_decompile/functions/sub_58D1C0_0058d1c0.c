void __cdecl sub_58D1C0(int a1)
{
  int *v1; // edi
  int v2; // ecx
  int v3; // eax
  unsigned int v4; // esi

  v1 = &dword_8000C0;
  do
  {
    v2 = *v1;
    if ( *v1 )
    {
      if ( v1[1] == a1 )
      {
        v3 = 0;
        v4 = ((2 * *(unsigned __int16 *)(v2 + 16) + 3) & 0xFFFFFFFC) + v2 + 24;
        if ( *(_BYTE *)(v2 + 18) )
        {
          do
          {
            *(_BYTE *)(v3 + v4) = -1;
            ++v3;
          }
          while ( v3 < *(unsigned __int8 *)(v2 + 18) );
        }
      }
    }
    v1 += 2;
  }
  while ( (int)v1 < (int)&dword_800100 );
}

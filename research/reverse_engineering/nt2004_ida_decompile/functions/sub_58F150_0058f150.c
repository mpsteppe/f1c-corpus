int __cdecl sub_58F150(int a1, int a2)
{
  int v2; // edi
  int result; // eax
  int v4; // ecx
  int v5; // eax

  v2 = 0;
  result = 1;
  if ( *(char *)(a2 + 4) > 0 )
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(a2 + v2 + 8) == 0xFF )
      {
        v4 = *(unsigned __int8 *)(v2 + a2 + 16);
        if ( v4 != 255 && (v4 & 0x80u) != 0 )
        {
          v5 = (*(unsigned __int8 *)(a1 + 4) >> 2) + 3;
          LOBYTE(v5) = v5 & 0xFC;
          if ( ((4 * *(unsigned __int8 *)(a1 + 6) + 3) & 0xFFFFFFFC) + v5 + a1 != -8
            && !*(_DWORD *)(((4 * *(unsigned __int8 *)(a1 + 6) + 3) & 0xFFFFFFFC) + v5 + a1 + 8 + 4 * (v4 & 0x7F)) )
          {
            break;
          }
        }
      }
      if ( ++v2 >= *(char *)(a2 + 4) )
        return 1;
    }
    return 0;
  }
  return result;
}

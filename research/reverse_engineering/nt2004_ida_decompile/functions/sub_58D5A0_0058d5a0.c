int __cdecl sub_58D5A0(int a1, _DWORD *a2)
{
  int v2; // esi
  int *v3; // ecx
  int v4; // edx

  v2 = 0;
  v3 = dword_8000C0;
  while ( 1 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      if ( *(_BYTE *)(v4 + 9) == *(_BYTE *)(a1 + 2) && *(_BYTE *)(v4 + 8) == *(_BYTE *)(a1 + 3) )
        break;
    }
    v3 += 2;
    ++v2;
    if ( (int)v3 >= (int)&dword_800100 )
      return 0;
  }
  *a2 = 8 * v2 + 8388800;
  return 1;
}

void __stdcall sub_67B4EF(int a1, char *a2)
{
  int v3; // esi
  char v4; // dl

  if ( *(_BYTE *)(a1 + 9) == 16 && *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10) )
  {
    v3 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
    do
    {
      v4 = *a2;
      *a2 = a2[1];
      a2[1] = v4;
      a2 += 2;
      --v3;
    }
    while ( v3 );
  }
}

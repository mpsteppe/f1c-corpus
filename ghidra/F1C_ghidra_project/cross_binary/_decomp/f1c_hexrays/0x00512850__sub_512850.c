// f1c  0x00512850  size=68
int __cdecl sub_512850(int a1, _BYTE *a2)
{
  int result; // eax
  _BYTE *v3; // esi
  char *v4; // edx
  int v5; // edi
  char v6; // cl
  unsigned __int8 v7; // dl
  int v8; // ecx

  result = a1;
  if ( *(_BYTE *)(a1 + 9) == 16 )
  {
    v3 = a2;
    v4 = a2;
    if ( *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10) )
    {
      v5 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
      do
      {
        v6 = *v4;
        v4 += 2;
        *v3++ = v6;
        --v5;
      }
      while ( v5 );
    }
    v7 = *(_BYTE *)(a1 + 10);
    v8 = *(_DWORD *)a1 * v7;
    *(_BYTE *)(a1 + 9) = 8;
    *(_BYTE *)(a1 + 11) = 8 * v7;
    *(_DWORD *)(a1 + 4) = v8;
  }
  return result;
}

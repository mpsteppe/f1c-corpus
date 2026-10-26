int __cdecl sub_58EF90(int a1, int a2, int a3)
{
  int v3; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // [esp+10h] [ebp+Ch]

  v3 = *(__int16 *)(a1 + 2);
  if ( *(unsigned __int16 *)(a2 + 10) <= v3 )
    return 0;
  v5 = *(unsigned __int8 *)(a2 + 5);
  v8 = v3 * v5 + a3;
  v6 = 0;
  if ( *(char *)(a2 + 4) < 0 )
    v6 = (v5 + 7) / 8 + 1;
  v7 = v6 + ((v5 * ((*(_BYTE *)(a2 + 4) & 0xF) + 2) + 15) & 0xFFFFFFFC) + a2 + 4 * (*(_BYTE *)(a2 + 4) & 0xF);
  if ( *(_BYTE *)(a2 + 6) )
    v7 += *(unsigned __int8 *)(a2 + 6) + 1;
  return sub_58EF50(v7, v8);
}

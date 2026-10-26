int __cdecl sub_5BD820(int *a1, int *a2)
{
  int v2; // edi
  const char *v3; // esi
  int result; // eax

  v2 = *a1;
  v3 = (const char *)sub_5BA160(*a2, *(_DWORD *)(dword_7FEFE0 + 1160), (int)&byte_629120);
  result = strcmp((const char *)sub_5BA160(v2, *(_DWORD *)(dword_7FEFE0 + 1160), (int)&byte_629120), v3);
  if ( !*(_DWORD *)(dword_7FEFE0 + 1164) )
    return -result;
  return result;
}

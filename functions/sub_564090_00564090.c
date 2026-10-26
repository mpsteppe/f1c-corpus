int __cdecl sub_564090(struct in_addr **a1, struct in_addr **a2)
{
  struct in_addr *v2; // esi
  char *v3; // eax
  int result; // eax
  char *v5; // [esp-4h] [ebp-8h]

  v2 = *a1;
  v5 = sub_5644B0(*a2, *(const char **)(dword_8D46B4 + 128), (int)byte_5EA438);
  v3 = sub_5644B0(v2, *(const char **)(dword_8D46B4 + 128), (int)byte_5EA438);
  result = sub_588410(v3, v5);
  if ( !*(_DWORD *)(dword_8D46B4 + 132) )
    return -result;
  return result;
}

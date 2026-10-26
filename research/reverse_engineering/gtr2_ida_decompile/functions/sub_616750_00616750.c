int __stdcall sub_616750(const char *a1)
{
  int result; // eax
  int v2; // esi
  int v3; // ebx
  int v4; // ebx
  int v5; // ebx

  if ( !a1 )
    return -1;
  result = 0;
  v2 = strlen(a1);
  if ( v2 > 0 )
  {
    v3 = sub_633CD6(*a1);
    v4 = 11 * sub_633CD6(a1[v2 / 6]) + v3;
    v5 = 945 * sub_633CD6(a1[v2 / 2]) + v4;
    return (v5 + 10097 * sub_633CD6(a1[v2 - 1])) % 9;
  }
  return result;
}

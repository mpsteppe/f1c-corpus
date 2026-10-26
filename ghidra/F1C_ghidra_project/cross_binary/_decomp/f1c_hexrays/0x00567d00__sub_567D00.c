// f1c  0x00567d00  size=170
int __stdcall sub_567D00(const char *a1)
{
  int v2; // edx
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // eax

  if ( !a1 )
    return -1;
  v2 = 0;
  v3 = strlen(a1);
  if ( v3 > 0 )
  {
    v4 = sub_589A35(*a1);
    v5 = sub_589A35(a1[v3 / 6]);
    v6 = v4 + 10 * v5 + v5;
    v7 = sub_589A35(a1[v3 / 2]);
    return (189 * v7 + v6 + 756 * v7 + 10097 * sub_589A35(a1[v3 - 1])) % 9;
  }
  return v2;
}

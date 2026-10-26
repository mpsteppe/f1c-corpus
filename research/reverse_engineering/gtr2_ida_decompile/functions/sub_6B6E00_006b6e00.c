int __stdcall sub_6B6E00(int *a1)
{
  int v1; // edi
  int v2; // eax
  int result; // eax

  v1 = a1[89];
  sub_6B60A0(a1, 216);
  v2 = a1[52];
  *(_DWORD *)(v1 + 28) = 0;
  if ( v2 )
    sub_6B68E0((int)a1);
  result = a1[55];
  if ( result )
    return sub_6B6B30(a1);
  return result;
}

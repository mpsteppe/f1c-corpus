int __fastcall sub_5BBC00(_DWORD *a1, int a2)
{
  bool v2; // zf
  int v3; // eax
  int result; // eax

  *(_DWORD *)(a2 + 32) = *a1;
  v2 = a1[1] == 0;
  v3 = a1[2];
  *a1 = a2;
  if ( v2 )
    a1[1] = a2;
  result = v3 + 1;
  a1[2] = result;
  return result;
}

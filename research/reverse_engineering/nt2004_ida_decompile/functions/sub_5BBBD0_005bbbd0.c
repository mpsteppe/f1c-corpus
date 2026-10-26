int __fastcall sub_5BBBD0(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  v2 = a1[1];
  if ( v2 )
    *(_DWORD *)(v2 + 32) = a2;
  a1[1] = a2;
  *(_DWORD *)(a2 + 32) = 0;
  v3 = a1[2];
  if ( !*a1 )
    *a1 = a2;
  result = v3 + 1;
  a1[2] = result;
  return result;
}

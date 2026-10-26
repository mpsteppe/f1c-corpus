int __fastcall sub_5BBF60(int *a1, int a2)
{
  int v2; // eax
  int v3; // esi

  v2 = *a1;
  v3 = 0;
  if ( !*a1 )
    return 0;
  while ( v2 != a2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 32);
    if ( !v2 )
      return 0;
  }
  if ( v3 )
    *(_DWORD *)(v3 + 32) = *(_DWORD *)(v2 + 32);
  if ( *a1 == v2 )
    *a1 = *(_DWORD *)(v2 + 32);
  if ( a1[1] == v2 )
    a1[1] = v3;
  --a1[2];
  return 1;
}

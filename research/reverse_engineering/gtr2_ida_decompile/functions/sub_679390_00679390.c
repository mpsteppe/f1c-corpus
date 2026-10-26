_DWORD *__stdcall sub_679390(_DWORD *a1, int a2)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  _DWORD *result; // eax
  int v7; // esi
  int v8; // ecx

  v2 = a1[18];
  if ( v2 )
    *(_DWORD *)(v2 + 128) = a2;
  v3 = a1[19];
  if ( v3 )
    *(_DWORD *)(v3 + 128) = a2;
  v4 = a1[20];
  if ( v4 )
    *(_DWORD *)(v4 + 128) = a2;
  v5 = a1[21];
  if ( v5 )
    *(_DWORD *)(v5 + 128) = a2;
  result = a1 + 26;
  v7 = 4;
  do
  {
    v8 = *(result - 4);
    if ( v8 )
      *(_DWORD *)(v8 + 276) = a2;
    if ( *result )
      *(_DWORD *)(*result + 276) = a2;
    ++result;
    --v7;
  }
  while ( v7 );
  return result;
}

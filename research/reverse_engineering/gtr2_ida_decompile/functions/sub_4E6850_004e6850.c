int __stdcall sub_4E6850(int a1)
{
  int v1; // eax
  int v2; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // edi
  int v8; // eax

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return a1;
  v4 = v1 / 2 - 1;
  v5 = a1;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v4 );
  }
  v6 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 4) = 0;
  v7 = sub_4E6850(a1);
  v8 = sub_4E6850(v6);
  return sub_5245B0(v7, v8);
}

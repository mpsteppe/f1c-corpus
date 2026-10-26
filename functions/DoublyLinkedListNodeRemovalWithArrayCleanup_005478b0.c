int __thiscall sub_5478B0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int result; // eax

  v3 = *(_DWORD *)(a2 + 88);
  if ( v3 )
    *(_DWORD *)(v3 + 92) = *(_DWORD *)(a2 + 92);
  v4 = *(_DWORD *)(a2 + 92);
  if ( v4 )
    *(_DWORD *)(v4 + 88) = *(_DWORD *)(a2 + 88);
  if ( this[10] == a2 )
    this[10] = *(_DWORD *)(a2 + 92);
  v5 = *(_DWORD *)(a2 - 4);
  v6 = a2 + 96 * v5;
  v7 = v5 - 1;
  if ( v7 >= 0 )
  {
    v8 = v7 + 1;
    do
    {
      v6 -= 96;
      EmptyStub_7470(v6);
      --v8;
    }
    while ( v8 );
  }
  FreeWrapper_7bcf((LPVOID)(a2 - 4));
  result = this[3] - 1;
  this[3] = result;
  return result;
}

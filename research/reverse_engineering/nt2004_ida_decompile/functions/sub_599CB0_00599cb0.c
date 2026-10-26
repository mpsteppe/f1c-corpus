int __thiscall sub_599CB0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  char *v6; // esi
  int v7; // ecx
  int v8; // edi
  int result; // eax

  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 )
    *(_DWORD *)(v3 + 12) = *(_DWORD *)(a2 + 12);
  v4 = *(_DWORD *)(a2 + 12);
  if ( v4 )
    *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 8);
  if ( this[10] == a2 )
    this[10] = *(_DWORD *)(a2 + 12);
  v5 = *(_DWORD *)(a2 - 4);
  v6 = (char *)(a2 + 96 * v5);
  v7 = v5 - 1;
  if ( v7 >= 0 )
  {
    v8 = v7 + 1;
    do
    {
      v6 -= 96;
      j_nullsub_6(v6);
      --v8;
    }
    while ( v8 );
  }
  sub_5BE8AE();
  result = this[3] - 1;
  this[3] = result;
  return result;
}

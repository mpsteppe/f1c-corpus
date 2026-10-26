int __stdcall sub_6B731E(int a1, _BYTE *a2, unsigned int a3)
{
  _BYTE *v3; // edx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // esi
  _BYTE *v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // esi
  unsigned int v13; // esi
  unsigned int v14; // esi
  unsigned int v15; // esi

  v3 = a2;
  if ( !a2 )
    return 0;
  v5 = a3;
  v6 = ~a1;
  if ( a3 >= 8 )
  {
    v7 = a3 >> 3;
    do
    {
      v5 -= 8;
      v8 = dword_744BC0[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
      v9 = v3 + 1;
      v10 = dword_744BC0[(unsigned __int8)(v8 ^ *v9++)] ^ (v8 >> 8);
      v11 = dword_744BC0[(unsigned __int8)(v10 ^ *v9++)] ^ (v10 >> 8);
      v12 = dword_744BC0[(unsigned __int8)(v11 ^ *v9++)] ^ (v11 >> 8);
      v13 = dword_744BC0[(unsigned __int8)(v12 ^ *v9++)] ^ (v12 >> 8);
      v14 = dword_744BC0[(unsigned __int8)(v13 ^ *v9++)] ^ (v13 >> 8);
      v15 = dword_744BC0[(unsigned __int8)(v14 ^ *v9++)] ^ (v14 >> 8);
      v6 = dword_744BC0[(unsigned __int8)(v15 ^ *v9)] ^ (v15 >> 8);
      v3 = v9 + 1;
      --v7;
    }
    while ( v7 );
  }
  for ( ; v5; --v5 )
    v6 = dword_744BC0[(unsigned __int8)(v6 ^ *v3++)] ^ (v6 >> 8);
  return ~v6;
}

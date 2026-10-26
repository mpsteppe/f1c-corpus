// f1c  0x0051923d  size=265
int __cdecl sub_51923D(int a1, _BYTE *a2, unsigned int a3)
{
  _BYTE *v3; // edx
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // esi
  _BYTE *v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // esi

  v3 = a2;
  if ( !a2 )
    return 0;
  v5 = ~a1;
  if ( a3 >= 8 )
  {
    v6 = a3 >> 3;
    do
    {
      a3 -= 8;
      v7 = (v5 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v5 ^ *v3)];
      v8 = v3 + 1;
      v9 = (v7 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v7 ^ *v8++)];
      v10 = (v9 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v9 ^ *v8++)];
      v11 = (v10 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v10 ^ *v8++)];
      v12 = (v11 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v11 ^ *v8++)];
      v13 = (v12 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v12 ^ *v8++)];
      v14 = (v13 >> 8) ^ dword_5AFFA0[(unsigned __int8)(v13 ^ *v8++)];
      v5 = dword_5AFFA0[(unsigned __int8)(v14 ^ *v8)] ^ (v14 >> 8);
      v3 = v8 + 1;
      --v6;
    }
    while ( v6 );
  }
  for ( ; a3; --a3 )
    v5 = dword_5AFFA0[(unsigned __int8)(v5 ^ *v3++)] ^ (v5 >> 8);
  return ~v5;
}

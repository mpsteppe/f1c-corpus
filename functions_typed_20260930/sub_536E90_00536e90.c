int __fastcall sub_536E90(int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned __int8 *v8; // edx
  int v9; // ebx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // ebx
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // ebx
  unsigned int v16; // ecx
  int v17; // eax
  int v18; // ebx
  unsigned int v19; // eax
  int v20; // ecx
  int v21; // ebx
  unsigned int v22; // ecx
  unsigned int v23; // eax

  if ( !a2 )
    return 0;
  v4 = a3;
  v5 = ~a1;
  if ( a3 >= 8 )
  {
    v6 = a3 >> 3;
    do
    {
      v4 -= 8;
      v7 = (v5 >> 8) ^ dword_5B7860[*a2 ^ (unsigned __int8)v5];
      v8 = a2 + 1;
      v9 = v8[1];
      v10 = (v7 >> 8) ^ dword_5B7860[*v8++ ^ (unsigned __int8)v7];
      v11 = v9 ^ (unsigned __int8)v10;
      v12 = v8[1];
      v13 = (v10 >> 8) ^ dword_5B7860[v11];
      ++v8;
      v14 = v12 ^ (unsigned __int8)v13;
      v15 = v8[1];
      v16 = (v13 >> 8) ^ dword_5B7860[v14];
      ++v8;
      v17 = v15 ^ (unsigned __int8)v16;
      v18 = v8[1];
      v19 = (v16 >> 8) ^ dword_5B7860[v17];
      ++v8;
      v20 = v18 ^ (unsigned __int8)v19;
      v21 = v8[1];
      v22 = (v19 >> 8) ^ dword_5B7860[v20];
      ++v8;
      v23 = (v22 >> 8) ^ dword_5B7860[v21 ^ (unsigned __int8)v22];
      v5 = dword_5B7860[v8[1] ^ (unsigned __int8)v23] ^ (v23 >> 8);
      a2 = v8 + 2;
      --v6;
    }
    while ( v6 );
  }
  for ( ; v4; --v4 )
    v5 = dword_5B7860[*a2++ ^ (unsigned __int8)v5] ^ (v5 >> 8);
  return ~v5;
}


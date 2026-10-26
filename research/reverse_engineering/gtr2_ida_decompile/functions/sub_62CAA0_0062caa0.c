int __fastcall sub_62CAA0(int a1, _BYTE *a2, unsigned int a3)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // ebp
  char v7; // cl
  unsigned int v8; // eax
  _BYTE *v9; // edx
  int v10; // esi
  char v11; // cl
  unsigned int v12; // eax
  int v13; // esi
  char v14; // cl
  unsigned int v15; // eax
  int v16; // esi
  char v17; // cl
  unsigned int v18; // eax
  char v19; // cl
  unsigned int v20; // eax
  char v21; // cl
  unsigned int v22; // eax
  int v23; // eax

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
      v7 = a2[1];
      v8 = dword_72EE98[(unsigned __int8)(v5 ^ *a2)] ^ (v5 >> 8);
      v9 = a2 + 1;
      v10 = dword_72EE98[(unsigned __int8)(v8 ^ v7)];
      v11 = v9[1];
      v12 = v10 ^ (v8 >> 8);
      ++v9;
      v13 = dword_72EE98[(unsigned __int8)(v12 ^ v11)];
      v14 = v9[1];
      v15 = v13 ^ (v12 >> 8);
      ++v9;
      v16 = dword_72EE98[(unsigned __int8)(v15 ^ v14)];
      v17 = *++v9;
      v18 = dword_72EE98[(unsigned __int8)(v16 ^ BYTE1(v15) ^ v17)] ^ ((v16 ^ (v15 >> 8)) >> 8);
      v19 = *++v9;
      v20 = dword_72EE98[(unsigned __int8)(v18 ^ v19)] ^ (v18 >> 8);
      v21 = *++v9;
      v22 = dword_72EE98[(unsigned __int8)(v20 ^ v21)] ^ (v20 >> 8);
      v23 = dword_72EE98[(unsigned __int8)(v22 ^ v9[1])] ^ (v22 >> 8);
      a2 = v9 + 2;
      --v6;
      v5 = v23;
    }
    while ( v6 );
  }
  for ( ; v4; --v4 )
    v5 = dword_72EE98[(unsigned __int8)(v5 ^ *a2++)] ^ (v5 >> 8);
  return ~v5;
}

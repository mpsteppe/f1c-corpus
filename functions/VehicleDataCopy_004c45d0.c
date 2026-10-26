_DWORD *__thiscall sub_4C45D0(_DWORD *this, int a2)
{
  char *v2; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // edi
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  _BYTE *v11; // eax
  _BYTE *v12; // eax
  _BYTE *v13; // eax
  _BYTE *v14; // eax
  _BYTE *v15; // eax
  _BYTE *v16; // eax
  _BYTE *v17; // eax
  _BYTE *v18; // eax
  _BYTE *v19; // eax
  _BYTE *v20; // eax
  _BYTE *v21; // eax
  _BYTE *v22; // eax
  _BYTE *v23; // eax
  char *v24; // eax
  char *v25; // eax
  _BYTE *v26; // eax

  v2 = *(char **)a2;
  if ( !*(_DWORD *)a2 )
    v2 = byte_5EA438;
  StringCopyWithBufferRealloc(v2);
  v4 = *(char **)(a2 + 8);
  if ( !v4 )
    v4 = byte_5EA438;
  StringCopyWithBufferRealloc(v4);
  v5 = *(char **)(a2 + 16);
  if ( !v5 )
    v5 = byte_5EA438;
  StringCopyWithBufferRealloc(v5);
  v6 = *(char **)(a2 + 24);
  if ( !v6 )
    v6 = byte_5EA438;
  StringCopyWithBufferRealloc(v6);
  v7 = *(char **)(a2 + 32);
  if ( !v7 )
    v7 = byte_5EA438;
  StringCopyWithBufferRealloc(v7);
  v8 = a2 - (_DWORD)this;
  v9 = this + 10;
  do
  {
    *v9 = v9[v8];
    ++v9;
  }
  while ( (unsigned int)&v9[-40 - (_DWORD)this] < 0x10 );
  this[14] = *(_DWORD *)(a2 + 56);
  this[15] = *(_DWORD *)(a2 + 60);
  this[16] = *(_DWORD *)(a2 + 64);
  this[17] = *(_DWORD *)(a2 + 68);
  this[18] = *(_DWORD *)(a2 + 72);
  this[19] = *(_DWORD *)(a2 + 76);
  this[20] = *(_DWORD *)(a2 + 80);
  this[21] = *(_DWORD *)(a2 + 84);
  this[22] = *(_DWORD *)(a2 + 88);
  this[23] = *(_DWORD *)(a2 + 92);
  this[24] = *(_DWORD *)(a2 + 96);
  this[25] = *(_DWORD *)(a2 + 100);
  this[26] = *(_DWORD *)(a2 + 104);
  this[27] = *(_DWORD *)(a2 + 108);
  this[28] = *(_DWORD *)(a2 + 112);
  v10 = this + 29;
  do
  {
    *v10 = v10[v8];
    ++v10;
  }
  while ( (unsigned int)&v10[-116 - (_DWORD)this] < 8 );
  v11 = this + 31;
  do
  {
    *v11 = v11[v8];
    ++v11;
  }
  while ( (unsigned int)&v11[-124 - (_DWORD)this] < 0x40 );
  v12 = this + 47;
  do
  {
    *v12 = v12[v8];
    ++v12;
  }
  while ( (unsigned int)&v12[-188 - (_DWORD)this] < 0x40 );
  v13 = this + 63;
  do
  {
    *v13 = v13[v8];
    ++v13;
  }
  while ( (unsigned int)&v13[-252 - (_DWORD)this] < 0x40 );
  v14 = this + 79;
  do
  {
    *v14 = v14[v8];
    ++v14;
  }
  while ( (unsigned int)&v14[-316 - (_DWORD)this] < 0x40 );
  v15 = this + 95;
  do
  {
    *v15 = v15[v8];
    ++v15;
  }
  while ( (unsigned int)&v15[-380 - (_DWORD)this] < 0x40 );
  v16 = this + 111;
  do
  {
    *v16 = v16[v8];
    ++v16;
  }
  while ( (unsigned int)&v16[-444 - (_DWORD)this] < 0x100 );
  v17 = this + 175;
  do
  {
    *v17 = v17[v8];
    ++v17;
  }
  while ( (unsigned int)&v17[-700 - (_DWORD)this] < 0x80 );
  v18 = this + 207;
  do
  {
    *v18 = v18[v8];
    ++v18;
  }
  while ( (unsigned int)&v18[-828 - (_DWORD)this] < 0x10 );
  v19 = this + 211;
  do
  {
    *v19 = v19[v8];
    ++v19;
  }
  while ( (unsigned int)&v19[-844 - (_DWORD)this] < 0x40 );
  v20 = this + 227;
  do
  {
    *v20 = v20[v8];
    ++v20;
  }
  while ( (unsigned int)&v20[-908 - (_DWORD)this] < 0x10 );
  v21 = this + 231;
  do
  {
    *v21 = v21[v8];
    ++v21;
  }
  while ( (unsigned int)&v21[-924 - (_DWORD)this] < 0x10 );
  v22 = this + 235;
  do
  {
    *v22 = v22[v8];
    ++v22;
  }
  while ( (unsigned int)&v22[-940 - (_DWORD)this] < 0x10 );
  v23 = this + 239;
  do
  {
    *v23 = v23[v8];
    ++v23;
  }
  while ( (unsigned int)&v23[-956 - (_DWORD)this] < 0x10 );
  v24 = *(char **)(a2 + 972);
  if ( !v24 )
    v24 = byte_5EA438;
  StringCopyWithBufferRealloc(v24);
  this[245] = *(_DWORD *)(a2 + 980);
  v25 = *(char **)(a2 + 984);
  if ( !v25 )
    v25 = byte_5EA438;
  StringCopyWithBufferRealloc(v25);
  v26 = this + 248;
  do
  {
    *v26 = v26[v8];
    ++v26;
  }
  while ( (unsigned int)&v26[-992 - (_DWORD)this] < 0x40 );
  this[264] = *(_DWORD *)(a2 + 1056);
  return this;
}

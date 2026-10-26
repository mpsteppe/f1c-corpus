int __thiscall sub_524990(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  char *v4; // esi
  int v5; // ebx
  int i; // eax
  const char *v7; // ecx
  const char *v8; // eax
  int j; // esi
  CHAR *v10; // eax
  int v11; // edx
  char v12; // cl
  CHAR *v13; // eax
  int v14; // eax
  char v15; // cl
  int v16; // eax
  char *v17; // eax
  CHAR *v18; // eax
  int v19; // ebx
  int k; // ebp
  int v21; // esi
  float *v22; // ecx
  double v23; // st7
  double v25; // st6
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c3
  float *v28; // esi
  double v29; // st7
  double v31; // st6
  unsigned __int8 v32; // c0
  unsigned __int8 v33; // c3
  int v34; // ebx
  char *v35; // esi
  int v36; // edi
  int v37; // eax
  char *v38; // esi
  int v39; // edi
  int v40; // eax
  float v42; // [esp+10h] [ebp-928h] BYREF
  int v43; // [esp+14h] [ebp-924h] BYREF
  float v44; // [esp+18h] [ebp-920h] BYREF
  int v45; // [esp+1Ch] [ebp-91Ch] BYREF
  float v46; // [esp+20h] [ebp-918h] BYREF
  float v47; // [esp+24h] [ebp-914h]
  int v48; // [esp+28h] [ebp-910h]
  float v49; // [esp+2Ch] [ebp-90Ch]
  _BYTE v50[900]; // [esp+30h] [ebp-908h] BYREF
  char v51[900]; // [esp+3B4h] [ebp-584h] BYREF
  char Buffer[512]; // [esp+738h] [ebp-200h] BYREF

  v48 = 0;
  v2 = v50;
  v3 = 45;
  do
  {
    *v2 = 0;
    v2[1] = -1;
    sub_524D10(v2);
    v2 += 5;
    --v3;
  }
  while ( v3 );
  v4 = v51;
  v5 = 45;
  do
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = -1;
    sub_524D10(v4);
    v4 += 20;
    --v5;
  }
  while ( v5 );
  if ( this[432] || this[449] )
  {
    v34 = 1;
  }
  else
  {
    this[432] = operator new(0xB4u);
    this[449] = operator new(0xB4u);
    for ( i = 0; i < 180; i += 4 )
    {
      *(_DWORD *)(i + this[432]) = 0;
      *(_DWORD *)(i + this[449]) = 0;
    }
    if ( !byte_7DA744 )
    {
      v7 = (const char *)dword_62A0B8;
      if ( !dword_62A0B8 )
        v7 = &byte_629120;
      v8 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v8 = &byte_629120;
      sprintf(Buffer, "%s%s%s", v8, v7, aNascarSoundsSf);
      if ( !sub_524D30(Buffer, dword_7DA3C0, dword_7DA038) )
        byte_7DA744 = 1;
    }
    for ( j = 0; j < 225; j += 5 )
    {
      v10 = (CHAR *)dword_7DA3C0[j];
      if ( !v10 )
        v10 = &byte_629120;
      sub_578600(v10);
      v11 = dword_7DA3C8[j];
      v12 = byte_7DA3D0[j * 4];
      *(_DWORD *)&v50[j * 4 + 12] = dword_7DA3CC[j];
      v13 = (CHAR *)dword_7DA038[j];
      *(_DWORD *)&v50[j * 4 + 8] = v11;
      v50[j * 4 + 16] = v12;
      if ( !v13 )
        v13 = &byte_629120;
      sub_578600(v13);
      v14 = dword_7DA044[j];
      v15 = byte_7DA048[j * 4];
      *(_DWORD *)&v51[j * 4 + 8] = dword_7DA040[j];
      *(_DWORD *)&v51[j * 4 + 12] = v14;
      v51[j * 4 + 16] = v15;
    }
    v16 = sub_4E7790((char *)(*this + 24992));
    if ( v16 )
    {
      v17 = *(char **)(v16 + 24);
      if ( !v17 )
        v17 = &byte_629120;
      sub_524D30(v17, v50, v51);
    }
    if ( dword_7D6BB0 )
    {
      v18 = (CHAR *)dword_62A078;
      if ( !dword_62A078 )
        v18 = &byte_629120;
      (*(void (__stdcall **)(CHAR *))(*(_DWORD *)dword_7D6BB0 + 72))(v18);
    }
    v19 = 0;
    for ( k = 0; k < 900; k += 20 )
    {
      sub_525900(v19, &v43, &v45);
      sub_525B60(v19, &v42, &v46, &v44);
      v21 = 4 * v19;
      sub_525AB0(4 * v19 + this[432], &v50[k], v43, v45);
      v22 = *(float **)(4 * v19 + this[432]);
      if ( v22 )
      {
        v23 = v46;
        v47 = v44;
        v25 = 1.0;
        if ( !(v26 | v27) )
          v25 = 1.0 / v42;
        v22[7] = v25;
        v22[8] = 1.0 - v25 * v47;
        v22[9] = v23;
      }
      sub_525AB0(v21 + this[449], &v51[k], v43, v45);
      v28 = *(float **)(v21 + this[449]);
      if ( v28 )
      {
        v29 = v46;
        v49 = v44;
        v31 = 1.0;
        if ( !(v32 | v33) )
          v31 = 1.0 / v42;
        v28[7] = v31;
        v28[8] = 1.0 - v31 * v49;
        v28[9] = v29;
      }
      ++v19;
    }
    v34 = v48;
  }
  v35 = Buffer;
  v36 = 45;
  do
  {
    v37 = *((_DWORD *)v35 - 5);
    v35 -= 20;
    if ( v37 )
      sub_5BE8AE();
    --v36;
  }
  while ( v36 );
  v38 = v51;
  v39 = 45;
  do
  {
    v40 = *((_DWORD *)v38 - 5);
    v38 -= 20;
    if ( v40 )
      sub_5BE8AE();
    --v39;
  }
  while ( v39 );
  return v34;
}

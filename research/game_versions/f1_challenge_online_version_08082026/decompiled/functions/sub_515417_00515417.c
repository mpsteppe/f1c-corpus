int __cdecl sub_515417(float a1, int a2)
{
  float *v2; // ebx
  unsigned int v3; // edx
  float *v4; // edi
  double v5; // st7
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  double v10; // st7
  int v11; // esi
  float v12; // esi
  int result; // eax
  unsigned int v14; // edi
  char v15; // cl
  double v16; // st7
  double v17; // st6
  unsigned int j; // eax
  double v19; // st7
  double v20; // st6
  unsigned int i; // eax
  double v22; // st7
  double v23; // st6
  double v24; // st7
  unsigned int v25; // eax
  int v26; // ecx
  unsigned int v27; // edx
  unsigned int v28; // ebx
  double v29; // st7
  double v30; // st7
  int v31; // eax
  double v32; // st7
  int v33; // edi
  int v34; // [esp-4h] [ebp-40h]
  float v35[16]; // [esp+Ch] [ebp-30h] BYREF
  float v36[8]; // [esp+4Ch] [ebp+10h] BYREF
  float v37; // [esp+6Ch] [ebp+30h]
  float v38; // [esp+70h] [ebp+34h]
  float v39; // [esp+84h] [ebp+48h]
  float v40; // [esp+88h] [ebp+4Ch]
  int v41; // [esp+8Ch] [ebp+50h]
  float v42; // [esp+90h] [ebp+54h]
  float v43; // [esp+94h] [ebp+58h]
  float v44; // [esp+98h] [ebp+5Ch]
  float v45; // [esp+9Ch] [ebp+60h]
  float v46; // [esp+A0h] [ebp+64h]
  float v47; // [esp+A4h] [ebp+68h]
  int v48; // [esp+A8h] [ebp+6Ch] BYREF

  v2 = (float *)(a2 + 12);
  v47 = *(float *)(a2 + 12);
  v46 = v47;
  memset(v35, 0, sizeof(v35));
  sub_513E5D();
  v3 = 0;
  v4 = v2;
  do
  {
    v5 = v35[v3] + *v4;
    v44 = v5;
    *(float *)&v48 = v5 * 255.0 + 0.5;
    LODWORD(v45) = (int)*(float *)&v48;
    *(float *)&v48 = v45;
    v6 = (double)SLODWORD(v45) * 0.0039215689;
    v36[v3] = v6;
    if ( v8 | v9 )
    {
      v47 = v6;
    }
    else if ( v6 > v46 )
    {
      v46 = v6;
    }
    v10 = v44 - v6;
    v11 = v3 & 3;
    if ( v11 != 3 )
      v35[v3 + 1] = 0.4375 * v10 + v35[v3 + 1];
    if ( v3 < 0xC )
    {
      if ( (v3 & 3) != 0 )
        v35[v3 + 3] = 0.1875 * v10 + v35[v3 + 3];
      v35[v3 + 4] = 0.3125 * v10 + v35[v3 + 4];
      if ( v11 != 3 )
        v35[v3 + 5] = v10 * 0.0625 + v35[v3 + 5];
    }
    ++v3;
    v4 += 4;
  }
  while ( v3 < 0x10 );
  v48 = dword_8B00A0;
  v12 = a1;
  result = sub_5147EA((float *)a2, LODWORD(a1) + 8, 0);
  if ( result < 0 )
    return result;
  if ( 1.0 == v47 )
  {
    *(_BYTE *)LODWORD(v12) = -1;
    *(_BYTE *)(LODWORD(v12) + 1) = -1;
LABEL_24:
    *(_DWORD *)(LODWORD(v12) + 2) = 0;
    *(_WORD *)(LODWORD(v12) + 6) = 0;
    return 0;
  }
  if ( 0.0 == v47 || 1.0 == v46 )
  {
    a2 = 6;
    v14 = 6;
  }
  else
  {
    v14 = 8;
    a2 = 8;
  }
  sub_513F7A((float *)&v48, &a1, (int)v36, v14);
  sub_513E5D();
  *(float *)&v48 = *(float *)&v48 * 255.0 + 0.5;
  LODWORD(v45) = (int)*(float *)&v48;
  a1 = a1 * 255.0 + 0.5;
  v48 = (int)a1;
  v15 = v48;
  v16 = (double)LOBYTE(v45) * 0.0039215689;
  v17 = (double)(unsigned __int8)v48 * 0.0039215689;
  a1 = v17;
  if ( v14 == 8 )
  {
    if ( LOBYTE(v45) == (_BYTE)v48 )
    {
      *(_BYTE *)LODWORD(v12) = LOBYTE(v45);
      *(_BYTE *)(LODWORD(v12) + 1) = v15;
      goto LABEL_24;
    }
    *(_BYTE *)(LODWORD(v12) + 1) = LOBYTE(v45);
    v37 = v17;
    v38 = v16;
    *(_BYTE *)LODWORD(v12) = v15;
    for ( i = 1; i < 7; *(&v37 + i) = (v22 + v23) * 0.14285715 )
    {
      v22 = (double)(7 - i) * v37;
      a1 = *(float *)&i;
      v23 = (double)i++ * v38;
    }
    v45 = COERCE_FLOAT(&unk_5AF640);
  }
  else
  {
    *(_BYTE *)LODWORD(v12) = LOBYTE(v45);
    v37 = v16;
    v38 = a1;
    *(_BYTE *)(LODWORD(v12) + 1) = v15;
    for ( j = 1; j < 5; *(&v37 + j) = (v19 + v20) * 0.2 )
    {
      v19 = (double)(5 - j) * v37;
      a1 = *(float *)&j;
      v20 = (double)j++ * v38;
    }
    v45 = COERCE_FLOAT(&unk_5AF660);
    v39 = 0.0;
    v40 = 1.0;
  }
  LODWORD(a1) = v14 - 1;
  v43 = (float)(v14 - 1);
  if ( v37 == v38 )
    v24 = 0.0;
  else
    v24 = v43 / (v38 - v37);
  v44 = v24;
  memset(v35, 0, sizeof(v35));
  sub_513E5D();
  v25 = 0;
  v26 = LODWORD(v12) + 3;
  v47 = *(float *)&v2;
  do
  {
    *(float *)&v27 = 0.0;
    a1 = 0.0;
    v48 = v25 + 8;
    v28 = v25;
    if ( v25 >= v25 + 8 )
      goto LABEL_58;
    v46 = v47;
    do
    {
      v29 = v35[v28] + *(float *)LODWORD(v46);
      a1 = v29;
      v30 = (v29 - v37) * v44;
      if ( v30 <= 0.0 )
      {
        if ( a2 != 6 || v37 * 0.5 < a1 )
        {
          v31 = 0;
          goto LABEL_49;
        }
        v34 = 6;
        goto LABEL_46;
      }
      if ( v30 < v43 )
      {
        v42 = v30 + 0.5;
        v41 = (int)v42;
        v31 = *(_DWORD *)(LODWORD(v45) + 4 * v41);
      }
      else
      {
        if ( a2 == 6 && (v38 + 1.0) * 0.5 <= a1 )
        {
          v34 = 7;
LABEL_46:
          v31 = v34;
          goto LABEL_49;
        }
        v31 = 1;
      }
LABEL_49:
      v32 = a1 - *(&v37 + v31);
      v27 = (v31 << 21) | (v27 >> 3);
      v33 = v28 & 3;
      if ( v33 != 3 )
        v35[v28 + 1] = 0.4375 * v32 + v35[v28 + 1];
      if ( v28 < 0xC )
      {
        if ( (v28 & 3) != 0 )
          v35[v28 + 3] = 0.1875 * v32 + v35[v28 + 3];
        v35[v28 + 4] = 0.3125 * v32 + v35[v28 + 4];
        if ( v33 != 3 )
          v35[v28 + 5] = v32 * 0.0625 + v35[v28 + 5];
      }
      LODWORD(v46) += 16;
      ++v28;
    }
    while ( v28 < v48 );
    a1 = *(float *)&v27;
LABEL_58:
    LODWORD(v47) += 128;
    *(_BYTE *)(v26 + 1) = BYTE2(a1);
    v25 = v48;
    *(_WORD *)(v26 - 1) = v27;
    v26 += 3;
  }
  while ( v25 < 0x10 );
  a2 = dword_8B00A0;
  return 0;
}

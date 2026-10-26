int __stdcall sub_67E572(int a1, float a2, int a3)
{
  float *v3; // ebx
  float v4; // eax
  unsigned int v5; // esi
  float *v6; // edi
  double v7; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  double v11; // st7
  int v12; // edx
  int result; // eax
  unsigned int v15; // edi
  char v16; // cl
  double v17; // st7
  double v18; // st6
  unsigned int j; // eax
  double v20; // st7
  double v21; // st6
  unsigned int i; // eax
  double v23; // st7
  double v24; // st6
  double v25; // st7
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int v28; // ebx
  unsigned int v29; // edi
  unsigned int v30; // esi
  double v31; // st7
  int v32; // eax
  double v33; // st7
  int v34; // edx
  int v35; // [esp-4h] [ebp-B0h]
  float v36[16]; // [esp+Ch] [ebp-A0h] BYREF
  float v37[8]; // [esp+4Ch] [ebp-60h] BYREF
  float v38; // [esp+6Ch] [ebp-40h]
  float v39; // [esp+70h] [ebp-3Ch]
  float v40; // [esp+84h] [ebp-28h]
  float v41; // [esp+88h] [ebp-24h]
  int v42; // [esp+8Ch] [ebp-20h]
  float v43; // [esp+90h] [ebp-1Ch]
  float v44; // [esp+94h] [ebp-18h]
  float v45; // [esp+98h] [ebp-14h]
  float v46; // [esp+9Ch] [ebp-10h]
  float v47; // [esp+A0h] [ebp-Ch] BYREF
  float v48; // [esp+A4h] [ebp-8h]
  float v49; // [esp+A8h] [ebp-4h]
  int v50; // [esp+B4h] [ebp+8h]

  v3 = (float *)LODWORD(a2);
  v4 = *(float *)(LODWORD(a2) + 12);
  v5 = 0;
  LODWORD(v44) = LODWORD(a2) + 12;
  v46 = v4;
  v49 = v4;
  if ( a3 )
    memset(v36, 0, sizeof(v36));
  LODWORD(v48) = LODWORD(a2) | 0xC00;
  v45 = a2;
  v6 = (float *)(LODWORD(a2) + 12);
  do
  {
    a2 = *v6;
    if ( a3 )
      a2 = a2 + v36[v5];
    v48 = a2 * 255.0 + 0.5;
    LODWORD(v47) = (int)v48;
    v48 = v47;
    v7 = (double)SLODWORD(v47) * 0.0039215689;
    v37[v5] = v7;
    if ( v9 | v10 )
    {
      v46 = v7;
    }
    else if ( v7 > v49 )
    {
      v49 = v7;
    }
    if ( a3 )
    {
      v11 = a2 - v7;
      v12 = v5 & 3;
      if ( v12 != 3 )
        v36[v5 + 1] = 0.4375 * v11 + v36[v5 + 1];
      if ( v5 < 0xC )
      {
        if ( (v5 & 3) != 0 )
          v36[v5 + 3] = 0.1875 * v11 + v36[v5 + 3];
        v36[v5 + 4] = 0.3125 * v11 + v36[v5 + 4];
        if ( v12 != 3 )
          v36[v5 + 5] = v11 * 0.0625 + v36[v5 + 5];
      }
    }
    ++v5;
    v6 += 4;
  }
  while ( v5 < 0x10 );
  result = sub_67D6C7(v3, a1 + 8, 0, a3);
  if ( result >= 0 )
  {
    if ( 1.0 == v46 )
    {
      *(_BYTE *)a1 = -1;
      *(_BYTE *)(a1 + 1) = -1;
LABEL_29:
      *(_DWORD *)(a1 + 2) = 0;
      *(_WORD *)(a1 + 6) = 0;
      return 0;
    }
    if ( 0.0 == v46 || 1.0 == v49 )
    {
      v50 = 6;
      v15 = 6;
    }
    else
    {
      v15 = 8;
      v50 = 8;
    }
    sub_67CE20(&v47, &a2, (int)v37, v15);
    v45 = v49;
    v48 = v47 * 255.0 + 0.5;
    LODWORD(v47) = (int)v48;
    a2 = a2 * 255.0 + 0.5;
    LODWORD(v48) = (int)a2;
    v16 = LOBYTE(v48);
    v17 = (double)LOBYTE(v47) * 0.0039215689;
    v18 = (double)LOBYTE(v48) * 0.0039215689;
    a2 = v18;
    if ( v15 == 8 )
    {
      if ( LOBYTE(v47) == LOBYTE(v48) )
      {
        *(_BYTE *)a1 = LOBYTE(v47);
        *(_BYTE *)(a1 + 1) = v16;
        goto LABEL_29;
      }
      *(_BYTE *)(a1 + 1) = LOBYTE(v47);
      v38 = v18;
      v39 = v17;
      *(_BYTE *)a1 = v16;
      for ( i = 1; i < 7; *(&v38 + i) = (v23 + v24) * 0.14285715 )
      {
        v23 = (double)(7 - i) * v38;
        a2 = *(float *)&i;
        v24 = (double)i++ * v39;
      }
      v48 = COERCE_FLOAT(&unk_73CD9C);
    }
    else
    {
      *(_BYTE *)a1 = LOBYTE(v47);
      v38 = v17;
      v39 = a2;
      *(_BYTE *)(a1 + 1) = v16;
      for ( j = 1; j < 5; *(&v38 + j) = (v20 + v21) * 0.2 )
      {
        v20 = (double)(5 - j) * v38;
        a2 = *(float *)&j;
        v21 = (double)j++ * v39;
      }
      v48 = COERCE_FLOAT(&unk_73CDBC);
      v40 = 0.0;
      v41 = 1.0;
    }
    LODWORD(a2) = v15 - 1;
    v47 = (float)(v15 - 1);
    if ( v38 == v39 )
      v25 = 0.0;
    else
      v25 = v47 / (v39 - v38);
    v43 = v25;
    if ( a3 )
      memset(v36, 0, sizeof(v36));
    LODWORD(v49) = LODWORD(a2) | 0xC00;
    v45 = a2;
    v26 = 0;
    v27 = a1 + 3;
    v46 = v44;
LABEL_42:
    *(float *)&v28 = 0.0;
    v29 = v26 + 8;
    v49 = 0.0;
    v30 = v26;
    if ( v26 >= v26 + 8 )
      goto LABEL_68;
    v49 = v46;
    while ( 1 )
    {
      a2 = *(float *)LODWORD(v49);
      if ( a3 )
        a2 = a2 + v36[v30];
      v31 = (a2 - v38) * v43;
      if ( v31 > 0.0 )
        break;
      if ( v50 == 6 && v38 * 0.5 >= a2 )
      {
        v35 = 6;
LABEL_55:
        v32 = v35;
        goto LABEL_58;
      }
      v32 = 0;
LABEL_58:
      v28 = (v32 << 21) | (v28 >> 3);
      if ( a3 )
      {
        v33 = a2 - *(&v38 + v32);
        v34 = v30 & 3;
        if ( v34 != 3 )
          v36[v30 + 1] = 0.4375 * v33 + v36[v30 + 1];
        if ( v30 < 0xC )
        {
          if ( (v30 & 3) != 0 )
            v36[v30 + 3] = 0.1875 * v33 + v36[v30 + 3];
          v36[v30 + 4] = 0.3125 * v33 + v36[v30 + 4];
          if ( v34 != 3 )
            v36[v30 + 5] = v33 * 0.0625 + v36[v30 + 5];
        }
      }
      LODWORD(v49) += 16;
      if ( ++v30 >= v29 )
      {
        v49 = *(float *)&v28;
LABEL_68:
        LODWORD(v46) += 128;
        *(_BYTE *)(v27 + 1) = BYTE2(v49);
        *(_WORD *)(v27 - 1) = v28;
        v26 = v29;
        v27 += 3;
        if ( v29 >= 0x10 )
          return 0;
        goto LABEL_42;
      }
    }
    if ( v31 < v47 )
    {
      v44 = v31 + 0.5;
      v42 = (int)v44;
      v32 = *(_DWORD *)(LODWORD(v48) + 4 * v42);
      goto LABEL_58;
    }
    if ( v50 != 6 || (v39 + 1.0) * 0.5 > a2 )
    {
      v32 = 1;
      goto LABEL_58;
    }
    v35 = 7;
    goto LABEL_55;
  }
  return result;
}

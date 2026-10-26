// f1c  0x0053a7b0  size=870
int __fastcall sub_53A7B0(int a1, int a2, int a3, int a4, _DWORD *a5, unsigned __int8 **a6)
{
  unsigned __int8 *v6; // ebx
  _BYTE *v7; // ebp
  unsigned int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // eax
  int v11; // edx
  unsigned __int8 *v12; // edi
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // edx
  int v17; // edx
  int i; // edx
  int v19; // ecx
  unsigned int j; // edx
  char v21; // cl
  unsigned int v22; // edi
  int v23; // ecx
  char *v24; // ecx
  _BYTE *v25; // ebp
  char v26; // dl
  char v27; // dl
  _BYTE *v28; // ecx
  unsigned int v29; // edi
  unsigned __int8 **v30; // ecx
  unsigned int v31; // edi
  unsigned int v32; // ecx
  unsigned __int8 *v33; // ebx
  unsigned __int8 *v34; // esi
  unsigned __int8 *v35; // eax
  unsigned int v37; // ecx
  unsigned __int8 *v38; // ebx
  unsigned __int8 *v39; // esi
  unsigned __int8 *v40; // eax
  unsigned int v41; // edx
  unsigned __int8 *v42; // ebx
  unsigned __int8 *v43; // esi
  unsigned __int8 *v44; // eax
  unsigned int v45; // [esp+10h] [ebp-18h]
  unsigned int v46; // [esp+14h] [ebp-14h]
  unsigned int v47; // [esp+18h] [ebp-10h]
  unsigned __int8 *v49; // [esp+1Ch] [ebp-Ch]
  int v50; // [esp+20h] [ebp-8h]
  int v51; // [esp+24h] [ebp-4h]

  v6 = *a6;
  v45 = (unsigned int)a6[1];
  v7 = (_BYTE *)a5[13];
  v8 = a5[12];
  v9 = a5[8];
  v10 = a5[7];
  if ( (unsigned int)v7 >= v8 )
    v47 = a5[11] - (_DWORD)v7;
  else
    v47 = v8 - (_DWORD)v7 - 1;
  v51 = dword_5DBB90[a2];
  v50 = dword_5DBB90[a1];
  do
  {
    for ( ; v10 < 0x14; ++v6 )
    {
      --v45;
      v11 = *v6 << v10;
      v10 += 8;
      v9 |= v11;
    }
    v12 = (unsigned __int8 *)(a3 + 8 * (v9 & v50));
    v13 = *v12;
    if ( *v12 )
    {
      while ( 1 )
      {
        v14 = v12[1];
        v9 >>= v14;
        v10 -= v14;
        if ( (v13 & 0x10) != 0 )
          break;
        if ( (v13 & 0x40) != 0 )
        {
          v31 = v45;
          if ( (v13 & 0x20) != 0 )
          {
            v37 = (unsigned int)&a6[1][-v45];
            if ( v10 >> 3 < v37 )
              v37 = v10 >> 3;
            v38 = &v6[-v37];
            a5[8] = v9;
            a5[7] = v10 - 8 * v37;
            v39 = *a6;
            v40 = a6[2];
            a6[1] = (unsigned __int8 *)(v45 + v37);
            *a6 = v38;
            a6[2] = &v40[v38 - v39];
            a5[13] = v7;
            return 1;
          }
          else
          {
            v30 = a6;
            a6[6] = (unsigned __int8 *)aInvalidLiteral_0;
LABEL_40:
            v41 = v10 >> 3;
            if ( v10 >> 3 >= (unsigned int)&v30[1][-v31] )
              v41 = (unsigned int)&v30[1][-v31];
            v42 = &v6[-v41];
            a5[8] = v9;
            a5[7] = v10 - 8 * v41;
            v43 = *v30;
            v44 = v30[2];
            v30[1] = (unsigned __int8 *)(v45 + v41);
            *v30 = v42;
            v30[2] = &v44[v42 - v43];
            a5[13] = v7;
            return -3;
          }
        }
        v12 += 8 * *((_DWORD *)v12 + 1) + 8 * (v9 & dword_5DBB90[v13]);
        v13 = *v12;
        if ( !*v12 )
          goto LABEL_11;
      }
      v16 = v13 & 0xF;
      v10 -= v16;
      v46 = *((_DWORD *)v12 + 1) + (v9 & dword_5DBB90[v16]);
      for ( v9 >>= v16; v10 < 0xF; ++v6 )
      {
        --v45;
        v17 = *v6 << v10;
        v10 += 8;
        v9 |= v17;
      }
      v49 = (unsigned __int8 *)(a4 + 8 * (v9 & v51));
      for ( i = *v49; ; i = *v49 )
      {
        v19 = v49[1];
        v9 >>= v19;
        v10 -= v19;
        if ( (i & 0x10) != 0 )
          break;
        if ( (i & 0x40) != 0 )
        {
          v30 = a6;
          v31 = v45;
          a6[6] = (unsigned __int8 *)aInvalidDistanc_0;
          goto LABEL_40;
        }
        v49 += 8 * *((_DWORD *)v49 + 1) + 8 * (v9 & dword_5DBB90[i]);
      }
      for ( j = i & 0xF; v10 < j; ++v6 )
      {
        --v45;
        v21 = v10;
        v10 += 8;
        v9 |= *v6 << v21;
      }
      v10 -= j;
      v22 = *((_DWORD *)v49 + 1) + (v9 & dword_5DBB90[j]);
      v9 >>= j;
      v47 -= v46;
      v23 = a5[10];
      if ( (unsigned int)&v7[-v23] < v22 )
      {
        v29 = v22 + v23 - (_DWORD)v7;
        v28 = (_BYTE *)(a5[11] - v29);
        if ( v46 > v29 )
        {
          v46 -= v29;
          do
          {
            *v7++ = *v28++;
            --v29;
          }
          while ( v29 );
          v28 = (_BYTE *)a5[10];
        }
      }
      else
      {
        v24 = &v7[-v22];
        v25 = v7 + 1;
        v26 = *v24++;
        *(v25 - 1) = v26;
        v7 = v25 + 1;
        v27 = *v24;
        v28 = v24 + 1;
        *(v7 - 1) = v27;
        v46 -= 2;
      }
      do
      {
        *v7++ = *v28++;
        --v46;
      }
      while ( v46 );
    }
    else
    {
LABEL_11:
      v15 = v12[1];
      v10 -= v15;
      v9 >>= v15;
      *v7++ = v12[4];
      --v47;
    }
  }
  while ( v47 >= 0x102 && v45 >= 0xA );
  v32 = (unsigned int)&a6[1][-v45];
  if ( v10 >> 3 < v32 )
    v32 = v10 >> 3;
  v33 = &v6[-v32];
  a5[8] = v9;
  a5[7] = v10 - 8 * v32;
  v34 = *a6;
  v35 = a6[2];
  a6[1] = (unsigned __int8 *)(v45 + v32);
  *a6 = v33;
  a6[2] = &v35[v33 - v34];
  a5[13] = v7;
  return 0;
}

int __stdcall sub_6DF93A(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *v6; // esi
  _BYTE *v7; // ecx
  unsigned int j; // edx
  unsigned int v10; // eax
  int v11; // eax
  unsigned __int8 *v12; // eax
  bool i; // zf
  unsigned __int8 v14; // cl
  int v15; // esi
  unsigned int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  int v19; // ebx
  unsigned int v20; // ebx
  int v21; // esi
  _BYTE *v22; // ecx
  _BYTE *v23; // eax
  unsigned int v24; // esi
  int v25; // esi
  _BYTE *v26; // esi
  _BYTE *v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  _BYTE *v30; // eax
  _BYTE *v31; // ecx
  unsigned int v32; // ecx
  int result; // eax
  unsigned int v34; // eax
  int v35; // ecx
  unsigned __int8 *v36; // edx
  int v37; // [esp+Ch] [ebp-18h]
  int v38; // [esp+10h] [ebp-14h]
  unsigned int v39; // [esp+14h] [ebp-10h]
  _BYTE *v40; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v41; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v42; // [esp+1Ch] [ebp-8h]
  unsigned int v43; // [esp+20h] [ebp-4h]
  int v44; // [esp+2Ch] [ebp+8h]
  unsigned int v45; // [esp+2Ch] [ebp+8h]
  int v46; // [esp+2Ch] [ebp+8h]
  unsigned int v47; // [esp+2Ch] [ebp+8h]
  unsigned int v48; // [esp+2Ch] [ebp+8h]
  int v49; // [esp+30h] [ebp+Ch]
  unsigned int v50; // [esp+40h] [ebp+1Ch]
  unsigned int v51; // [esp+40h] [ebp+1Ch]

  v6 = a5;
  v7 = (_BYTE *)a5[13];
  j = a5[7];
  v41 = (unsigned __int8 *)*a6;
  v43 = a6[1];
  v50 = a5[8];
  v10 = a5[12];
  v40 = v7;
  if ( (unsigned int)v7 >= v10 )
    v11 = a5[11] - (_DWORD)v7;
  else
    v11 = v10 - (_DWORD)v7 - 1;
  v39 = v11;
  v38 = dword_91BBC0[a1];
  v49 = dword_91BBC0[a2];
LABEL_6:
  while ( j < 0x14 )
  {
    --v43;
    v50 |= *v41++ << j;
    j += 8;
  }
  v12 = (unsigned __int8 *)(a3 + 8 * (v50 & v38));
  v44 = *v12;
  for ( i = v44 == 0; ; i = v44 == 0 )
  {
    v14 = v12[1];
    if ( i )
    {
      v50 >>= v14;
      j -= v12[1];
      v31 = v40++;
      --v39;
      *v31 = v12[4];
LABEL_38:
      if ( v39 < 0x102 || v43 < 0xA )
      {
        v32 = a6[1] - v43;
        if ( j >> 3 < v32 )
          v32 = j >> 3;
        result = 0;
        goto LABEL_53;
      }
      goto LABEL_6;
    }
    v50 >>= v14;
    j -= v12[1];
    if ( (v44 & 0x10) != 0 )
    {
      v15 = v50 & dword_91BBC0[v44 & 0xF];
      v51 = v50 >> (v44 & 0xF);
      v16 = j - (v44 & 0xF);
      v45 = *((_DWORD *)v12 + 1) + v15;
      while ( v16 < 0xF )
      {
        --v43;
        v51 |= *v41++ << v16;
        v16 += 8;
      }
      v17 = (unsigned __int8 *)(a4 + 8 * (v51 & v49));
      v50 = v51 >> v17[1];
      for ( j = v16 - v17[1]; ; j -= v18 )
      {
        v19 = *v17;
        if ( (v19 & 0x10) != 0 )
        {
          v20 = v19 & 0xF;
          while ( j < v20 )
          {
            --v43;
            v50 |= *v41++ << j;
            j += 8;
          }
          v21 = *((_DWORD *)v17 + 1) + (v50 & dword_91BBC0[v20]);
          v50 >>= v20;
          v39 -= v45;
          v22 = v40;
          j -= v20;
          v23 = &v40[-v21];
          v24 = a5[10];
          if ( (unsigned int)v23 >= v24 )
          {
            *v40 = *v23;
            v29 = v23 + 1;
            v40[1] = *v29;
            v22 = v40 + 2;
            v30 = v29 + 1;
            v48 = v45 - 2;
            do
            {
              *v22++ = *v30++;
              --v48;
            }
            while ( v48 );
          }
          else
          {
            v37 = a5[11];
            do
              v23 += v37 - v24;
            while ( (unsigned int)v23 < v24 );
            v25 = v37 - (_DWORD)v23;
            if ( v45 <= v37 - (int)v23 )
            {
              *v40 = *v23;
              v27 = v23 + 1;
              v40[1] = *v27;
              v22 = v40 + 2;
              v28 = v27 + 1;
              v47 = v45 - 2;
              do
              {
                *v22++ = *v28++;
                --v47;
              }
              while ( v47 );
            }
            else
            {
              v46 = v45 - v25;
              do
              {
                *v22++ = *v23++;
                --v25;
              }
              while ( v25 );
              v26 = (_BYTE *)a5[10];
              do
              {
                *v22++ = *v26++;
                --v46;
              }
              while ( v46 );
            }
          }
          v6 = a5;
          v40 = v22;
          goto LABEL_38;
        }
        if ( (v19 & 0x40) != 0 )
          break;
        v17 += 8 * *((_DWORD *)v17 + 1) + 8 * (v50 & dword_91BBC0[v19]);
        v18 = v17[1];
        v50 >>= v18;
      }
      v32 = a6[1] - v43;
      a6[6] = "invalid distance code";
      if ( j >> 3 < v32 )
        v32 = j >> 3;
      v6 = a5;
      goto LABEL_52;
    }
    if ( (v44 & 0x40) != 0 )
      break;
    v12 += 8 * *((_DWORD *)v12 + 1) + 8 * (v50 & dword_91BBC0[v44]);
    v44 = *v12;
  }
  v34 = j >> 3;
  v35 = a6[1];
  if ( (v44 & 0x20) == 0 )
  {
    v32 = v35 - v43;
    a6[6] = "invalid literal/length code";
    if ( v34 < v32 )
      v32 = j >> 3;
LABEL_52:
    result = -3;
    goto LABEL_53;
  }
  v32 = v35 - v43;
  if ( v34 < v32 )
    v32 = j >> 3;
  result = 1;
LABEL_53:
  v42 = &v41[-v32];
  v6[8] = v50;
  v6[7] = j - 8 * v32;
  a6[1] = v43 + v32;
  v36 = &v42[-*a6];
  *a6 = v42;
  a6[2] += v36;
  v6[13] = v40;
  return result;
}

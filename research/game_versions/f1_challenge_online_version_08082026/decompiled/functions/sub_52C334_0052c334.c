int __cdecl sub_52C334(int a1, int a2, int a3, int a4, _DWORD *a5, unsigned __int8 **a6)
{
  _DWORD *v7; // edi
  _BYTE *v8; // ecx
  unsigned int v9; // ebx
  unsigned int j; // edx
  unsigned int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // eax
  bool i; // zf
  unsigned __int8 v15; // cl
  int v16; // ecx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  int v19; // eax
  unsigned __int8 *v20; // eax
  int v21; // ecx
  int v22; // ebx
  unsigned int v23; // ebx
  unsigned int v24; // ecx
  int v25; // eax
  _BYTE *v26; // ecx
  char *v27; // eax
  unsigned int v28; // ecx
  _BYTE *v29; // ebx
  char v30; // cl
  _BYTE *v31; // ecx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned __int8 *v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // ecx
  int v38; // [esp+Ch] [ebp-18h]
  int v39; // [esp+10h] [ebp-14h]
  unsigned int v40; // [esp+14h] [ebp-10h]
  unsigned int v41; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v42; // [esp+1Ch] [ebp-8h]
  unsigned int v43; // [esp+20h] [ebp-4h]
  unsigned int v44; // [esp+2Ch] [ebp+8h]
  unsigned int v45; // [esp+2Ch] [ebp+8h]
  unsigned int v46; // [esp+2Ch] [ebp+8h]
  int v47; // [esp+30h] [ebp+Ch]
  unsigned int v48; // [esp+30h] [ebp+Ch]
  unsigned int v49; // [esp+30h] [ebp+Ch]
  int v50; // [esp+30h] [ebp+Ch]
  _BYTE *v51; // [esp+40h] [ebp+1Ch]

  v42 = *a6;
  v7 = a5;
  v8 = (_BYTE *)a5[13];
  v9 = a5[8];
  j = a5[7];
  v43 = (unsigned int)a6[1];
  v11 = a5[12];
  v51 = v8;
  if ( (unsigned int)v8 >= v11 )
    v12 = a5[11] - (_DWORD)v8;
  else
    v12 = v11 - (_DWORD)v8 - 1;
  v40 = v12;
  v39 = dword_5DA520[a1];
  v38 = dword_5DA520[a2];
LABEL_6:
  while ( j < 0x14 )
  {
    --v43;
    v9 |= *v42++ << j;
    j += 8;
  }
  v13 = (unsigned __int8 *)(a3 + 8 * (v9 & v39));
  v47 = *v13;
  for ( i = v47 == 0; ; i = v47 == 0 )
  {
    v15 = v13[1];
    if ( i )
    {
      v9 >>= v15;
      j -= v13[1];
      v31 = v51++;
      --v40;
      *v31 = v13[4];
LABEL_32:
      if ( v40 < 0x102 || v43 < 0xA )
      {
        v32 = (unsigned int)&a6[1][-v43];
        if ( j >> 3 < v32 )
          v32 = j >> 3;
        v50 = 0;
        goto LABEL_47;
      }
      goto LABEL_6;
    }
    v9 >>= v15;
    j -= v13[1];
    if ( (v47 & 0x10) != 0 )
    {
      v41 = *((_DWORD *)v13 + 1) + (v9 & dword_5DA520[v47 & 0xF]);
      v16 = v47 & 0xF;
      v17 = v9 >> v16;
      v18 = j - v16;
      v44 = v17;
      if ( v18 < 0xF )
      {
        do
        {
          --v43;
          v19 = *v42 << v18;
          v18 += 8;
          v17 |= v19;
          ++v42;
        }
        while ( v18 < 0xF );
        v44 = v17;
      }
      v20 = (unsigned __int8 *)(a4 + 8 * (v17 & v38));
      v45 = v44 >> v20[1];
      for ( j = v18 - v20[1]; ; j -= v21 )
      {
        v22 = *v20;
        if ( (v22 & 0x10) != 0 )
        {
          v23 = v22 & 0xF;
          while ( j < v23 )
          {
            --v43;
            v45 |= *v42++ << j;
            j += 8;
          }
          v7 = a5;
          v24 = *((_DWORD *)v20 + 1) + (v45 & dword_5DA520[v23]);
          v40 -= v41;
          v25 = a5[10];
          v48 = v24;
          v46 = v45 >> v23;
          j -= v23;
          if ( (unsigned int)&v51[-v25] < v24 )
          {
            v28 = v24 + v25 - (_DWORD)v51;
            v27 = (char *)(a5[11] - v28);
            v49 = v28;
            if ( v41 > v28 )
            {
              v41 -= v28;
              do
              {
                v29 = v51;
                v30 = *v27;
                ++v51;
                ++v27;
                i = v49-- == 1;
                *v29 = v30;
              }
              while ( !i );
              v27 = (char *)a5[10];
            }
            v26 = v51;
          }
          else
          {
            *v51 = v51[-v24];
            v51[1] = v51[-v24 + 1];
            v26 = v51 + 2;
            v27 = &v51[-v48 + 2];
            v41 -= 2;
          }
          do
          {
            *v26++ = *v27++;
            --v41;
          }
          while ( v41 );
          v9 = v46;
          v51 = v26;
          goto LABEL_32;
        }
        if ( (v22 & 0x40) != 0 )
          break;
        v20 += 8 * *((_DWORD *)v20 + 1) + 8 * (v45 & dword_5DA520[v22]);
        v21 = v20[1];
        v45 >>= v21;
      }
      v32 = (unsigned int)&a6[1][-v43];
      a6[6] = "invalid distance code";
      if ( j >> 3 < v32 )
        v32 = j >> 3;
      v7 = a5;
      v9 = v45;
      goto LABEL_46;
    }
    if ( (v47 & 0x40) != 0 )
      break;
    v13 += 8 * *((_DWORD *)v13 + 1) + 8 * (v9 & dword_5DA520[v47]);
    v47 = *v13;
  }
  v33 = j >> 3;
  v34 = a6[1];
  if ( (v47 & 0x20) == 0 )
  {
    v32 = (unsigned int)&v34[-v43];
    a6[6] = "invalid literal/length code";
    if ( v33 < v32 )
      v32 = j >> 3;
LABEL_46:
    v50 = -3;
    goto LABEL_47;
  }
  v32 = (unsigned int)&v34[-v43];
  if ( v33 < v32 )
    v32 = j >> 3;
  v50 = 1;
LABEL_47:
  v7[8] = v9;
  v7[7] = j - 8 * v32;
  v35 = &v42[-v32];
  a6[1] = (unsigned __int8 *)(v43 + v32);
  v36 = &v42[-v32] - *a6;
  *a6 = v35;
  a6[2] += v36;
  v7[13] = v51;
  return v50;
}

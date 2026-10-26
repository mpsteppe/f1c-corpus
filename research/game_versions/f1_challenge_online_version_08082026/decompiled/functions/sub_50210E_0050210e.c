int __thiscall sub_50210E(int *this, int a2, int a3)
{
  int v3; // eax
  int *v4; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned __int8 v13; // al
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  unsigned int i; // eax
  double v22; // st7
  double v23; // st7
  char v24; // al
  int v25; // ecx
  bool v26; // cc
  int j; // eax
  int v28; // eax
  int v29; // eax
  int v30; // edi
  int v31; // ecx
  char v32; // bl
  int v33; // edi
  int v34; // ecx
  int v35; // eax
  int v36; // [esp+8h] [ebp-168h]
  int v37; // [esp+Ch] [ebp-164h]
  int v38; // [esp+Ch] [ebp-164h]
  int v39; // [esp+10h] [ebp-160h]
  _BYTE v40[256]; // [esp+1Ch] [ebp-154h]
  double v41[2]; // [esp+11Ch] [ebp-54h] BYREF
  _DWORD v42[2]; // [esp+12Ch] [ebp-44h] BYREF
  int v43; // [esp+134h] [ebp-3Ch] BYREF
  int v44; // [esp+138h] [ebp-38h] BYREF
  int *v45; // [esp+13Ch] [ebp-34h]
  int v46; // [esp+140h] [ebp-30h] BYREF
  int v47; // [esp+144h] [ebp-2Ch] BYREF
  int v48; // [esp+148h] [ebp-28h] BYREF
  int v49; // [esp+14Ch] [ebp-24h] BYREF
  int v50; // [esp+150h] [ebp-20h] BYREF
  _DWORD *v51; // [esp+154h] [ebp-1Ch]
  unsigned int v52; // [esp+158h] [ebp-18h] BYREF
  int v53; // [esp+15Ch] [ebp-14h]
  int v54; // [esp+160h] [ebp-10h] BYREF
  int v55; // [esp+164h] [ebp-Ch]
  int v56; // [esp+168h] [ebp-8h] BYREF
  int v57; // [esp+16Ch] [ebp-4h] BYREF

  v45 = this;
  v57 = 0;
  v56 = 0;
  v51 = 0;
  if ( sub_513C38(a2, 0, a3) )
    return -2147467259;
  v3 = sub_5118E6("1.0.5", 0, sub_502102, nullsub_4);
  v57 = v3;
  if ( !v3 )
    goto LABEL_86;
  v56 = sub_513D3D(v3);
  if ( !v56 )
    goto LABEL_86;
  if ( !sub_58A7EC(v57, 0, v39) )
  {
    v42[0] = a2;
    v42[1] = a3;
    sub_513BF9(v57, v42, sub_5020BF);
    sub_5119E9(v57, v56);
    sub_5121AE(v57, v56, &v46, &v52, &v49, &v47, 0, 0, 0);
    v4 = v45;
    if ( v47 )
    {
      switch ( v47 )
      {
        case 2:
          *v45 = 20;
          break;
        case 3:
          *v45 = 41;
          break;
        case 4:
          *v45 = 51;
          break;
        case 6:
          *v45 = 21;
          break;
      }
    }
    else
    {
      *v45 = 50;
    }
    if ( v49 == 16 )
    {
      sub_512322(v57);
      switch ( *v4 )
      {
        case 20:
          *v4 = 909201952;
          break;
        case 21:
          *v4 = 909201985;
          break;
        case 50:
          *v4 = 909200416;
          break;
        case 51:
          *v4 = 909200449;
          break;
        default:
          return -2147467259;
      }
    }
    if ( v49 < 8 )
      sub_512334(v57);
    if ( !v47 && v49 < 8 )
      sub_5124D5(v57);
    if ( sub_512183(v57, v56, &v44) )
    {
      sub_513B36(v57, v56, v44);
    }
    else if ( sub_51215A(v57, v56, v41) )
    {
      sub_51249F(v57, 2.2, v41[0]);
    }
    if ( *v4 != 41 && sub_512114(v57, v56, 16) )
    {
      sub_5124D5(v57);
      v6 = *v4;
      if ( *v4 == 20 )
      {
        *v4 = 21;
      }
      else
      {
        switch ( v6 )
        {
          case 50:
            *v4 = 51;
            break;
          case 909200416:
            *v4 = 909200449;
            break;
          case 909201952:
            *v4 = 909201985;
            break;
        }
      }
    }
    v7 = *v4;
    if ( *v4 == 20 || v7 == 909201952 || v7 == 21 || v7 == 909201985 )
      sub_512319(v57);
    if ( *v4 == 20 )
    {
      sub_512366(v57, 255, 1);
      *v4 = 22;
    }
    sub_511B5C(v57, v56);
    v8 = *v4;
    if ( *v4 > 51 )
    {
      v15 = v8 - 909200416;
      if ( !v15 )
      {
LABEL_58:
        v55 = 1;
        goto LABEL_59;
      }
      v16 = v15 - 33;
      if ( v16 )
      {
        v17 = v16 - 1503;
        if ( v17 )
        {
          if ( v17 != 33 )
            goto LABEL_59;
          goto LABEL_65;
        }
LABEL_66:
        v55 = 3;
        goto LABEL_59;
      }
    }
    else if ( *v4 != 51 )
    {
      v9 = v8 - 20;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            v12 = v11 - 19;
            if ( !v12 || v12 == 9 )
              goto LABEL_58;
LABEL_59:
            v13 = sub_512144(v57, v56);
            if ( v55 != v13 )
              goto LABEL_60;
            v37 = v56;
            v4[3] = v46;
            v36 = v57;
            v4[4] = v52;
            v4[5] = 1;
            v18 = sub_51212E(v36, v37);
            v19 = v4[16] == 0;
            v4[12] = v18;
            v4[13] = 0;
            if ( !v19 )
            {
              v20 = sub_587C03(v52 * v18);
              v4[1] = v20;
              if ( !v20 || (v38 = 4 * v52, v4[14] = 1, (v51 = (_DWORD *)sub_587C03(v38)) == 0) )
              {
LABEL_86:
                v14 = -2147024882;
                goto LABEL_97;
              }
              for ( i = 0; i < v52; ++i )
                v51[i] = v4[1] + i * v4[12];
              sub_511F23(v57, v51);
              if ( *v4 == 41 )
              {
                v48 = 0;
                v50 = 0;
                if ( sub_512114(v57, v56, 8) )
                  sub_51227F(v57, v56, &v54, &v50);
                if ( sub_512114(v57, v56, 16) )
                  sub_5122B2(v57, v56, &v43, &v48, 0);
                if ( *(float *)(v57 + 304) <= 0.000001 || *(float *)(v57 + 308) <= 0.000001 )
                {
                  for ( j = 0; j < 256; ++j )
                    v40[j] = j;
                }
                else
                {
                  v22 = *(float *)(v57 + 308);
                  v53 = 0;
                  v41[1] = 1.0 / (v22 * *(float *)(v57 + 304));
                  do
                  {
                    v23 = (double)v53 * 0.00392156862745098;
                    sub_5881F0(v23);
                    v24 = sub_587BDC(v23 * 255.0 + 0.5);
                    v25 = v53++;
                    v26 = v53 < 256;
                    v40[v25] = v24;
                  }
                  while ( v26 );
                }
                v28 = sub_587C03(1024);
                v4[2] = v28;
                if ( !v28 )
                  goto LABEL_86;
                v29 = 0;
                v26 = v48 <= 0;
                v4[15] = 1;
                if ( !v26 )
                {
                  v30 = 0;
                  do
                  {
                    v31 = 4 * v29;
                    *(_BYTE *)(v31 + v4[2]) = v40[*(unsigned __int8 *)(v30 + v54)];
                    *(_BYTE *)(v4[2] + v31 + 1) = v40[*(unsigned __int8 *)(v30 + v54 + 1)];
                    *(_BYTE *)(v4[2] + v31 + 2) = v40[*(unsigned __int8 *)(v30 + v54 + 2)];
                    v32 = *(_BYTE *)(v29 + v43);
                    ++v29;
                    *(_BYTE *)(v4[2] + v31 + 3) = v32;
                    v30 += 3;
                  }
                  while ( v29 < v48 );
                }
                if ( v29 < v50 )
                {
                  v33 = 3 * v29;
                  do
                  {
                    v34 = 4 * v29;
                    *(_BYTE *)(v34 + v4[2]) = v40[*(unsigned __int8 *)(v33 + v54)];
                    *(_BYTE *)(v4[2] + v34 + 1) = v40[*(unsigned __int8 *)(v33 + v54 + 1)];
                    *(_BYTE *)(v4[2] + v34 + 2) = v40[*(unsigned __int8 *)(v33 + v54 + 2)];
                    *(_BYTE *)(v4[2] + v34 + 3) = -1;
                    ++v29;
                    v33 += 3;
                  }
                  while ( v29 < v50 );
                }
                if ( v29 < 256 )
                {
                  v35 = 4 * v29;
                  do
                  {
                    *(_BYTE *)(v35 + v4[2]) = -1;
                    *(_BYTE *)(v35 + v4[2] + 1) = -1;
                    *(_BYTE *)(v35 + v4[2] + 2) = -1;
                    *(_BYTE *)(v35 + v4[2] + 3) = -1;
                    v35 += 4;
                  }
                  while ( v35 < 1024 );
                }
              }
            }
            v14 = 0;
            goto LABEL_97;
          }
        }
LABEL_65:
        v55 = 4;
        goto LABEL_59;
      }
      goto LABEL_66;
    }
    v55 = 2;
    goto LABEL_59;
  }
LABEL_60:
  v14 = -2147467259;
LABEL_97:
  if ( v57 )
    sub_512093(&v57, &v56, 0);
  if ( v51 )
    sub_587BCF(v51);
  return v14;
}

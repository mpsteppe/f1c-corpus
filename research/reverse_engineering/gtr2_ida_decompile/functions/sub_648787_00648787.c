int __thiscall sub_648787(int *this, int a2, int a3)
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
  bool v16; // zf
  void *v17; // eax
  unsigned int i; // eax
  double v19; // st7
  __int64 v20; // rax
  int v21; // ecx
  bool v22; // cc
  int j; // eax
  void *v24; // eax
  int v25; // eax
  int v26; // edi
  int v27; // ecx
  char v28; // bl
  int v29; // edi
  int v30; // ecx
  int v31; // eax
  int v32; // [esp+10h] [ebp-168h]
  int v33; // [esp+14h] [ebp-164h]
  size_t v34; // [esp+14h] [ebp-164h]
  _BYTE v35[256]; // [esp+24h] [ebp-154h]
  double v36; // [esp+124h] [ebp-54h] BYREF
  long double v37; // [esp+12Ch] [ebp-4Ch]
  _DWORD v38[2]; // [esp+134h] [ebp-44h] BYREF
  int v39; // [esp+13Ch] [ebp-3Ch] BYREF
  int v40; // [esp+140h] [ebp-38h] BYREF
  int *v41; // [esp+144h] [ebp-34h]
  int v42; // [esp+148h] [ebp-30h] BYREF
  int v43; // [esp+14Ch] [ebp-2Ch] BYREF
  int v44; // [esp+150h] [ebp-28h] BYREF
  int v45; // [esp+154h] [ebp-24h] BYREF
  int v46; // [esp+158h] [ebp-20h] BYREF
  void *Block; // [esp+15Ch] [ebp-1Ch]
  unsigned int v48; // [esp+160h] [ebp-18h] BYREF
  int v49; // [esp+164h] [ebp-14h]
  int v50; // [esp+168h] [ebp-10h] BYREF
  int v51; // [esp+16Ch] [ebp-Ch]
  int v52; // [esp+170h] [ebp-8h] BYREF
  int v53; // [esp+174h] [ebp-4h] BYREF

  v41 = this;
  v53 = 0;
  v52 = 0;
  Block = 0;
  if ( sub_679F8A(a2, 0, a3) )
    return -2147467259;
  v3 = sub_67AA12("1.0.5", 0, sub_648550, nullsub_9);
  v53 = v3;
  if ( !v3 )
    goto LABEL_85;
  v52 = sub_67A0BB(v3);
  if ( !v52 )
    goto LABEL_85;
  if ( !_setjmp3(v53, 0) )
  {
    v38[0] = a2;
    v38[1] = a3;
    sub_67CBDA(v53, v38, sub_64850D);
    sub_67AB08(v53, v52);
    sub_67B2BD(v53, v52, &v42, &v48, &v45, &v43, 0, 0, 0);
    v4 = v41;
    if ( v43 )
    {
      switch ( v43 )
      {
        case 2:
          *v41 = 20;
          break;
        case 3:
          *v41 = 41;
          break;
        case 4:
          *v41 = 51;
          break;
        case 6:
          *v41 = 21;
          break;
      }
    }
    else
    {
      *v41 = 50;
    }
    if ( v45 == 16 )
    {
      sub_67B443(v53);
      switch ( *v4 )
      {
        case 20:
          *v4 = 909201952;
          break;
        case 21:
          *v4 = 36;
          break;
        case 50:
          *v4 = 81;
          break;
        case 51:
          *v4 = 909200449;
          break;
        default:
          return -2147467259;
      }
    }
    if ( v45 < 8 )
      sub_67B45C(v53);
    if ( !v43 && v45 < 8 )
      sub_67B620(v53);
    if ( sub_67B28C(v53, v52, &v40) )
    {
      sub_67A96E(v53, v52, v40);
    }
    else if ( sub_67B25D(v53, v52, &v36) )
    {
      sub_67B5E5(v53, 2.2, v36);
    }
    if ( *v4 != 41 && sub_67B203(v53, v52, 16) )
    {
      sub_67B620(v53);
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
          case 81:
            *v4 = 909200449;
            break;
          case 909201952:
            *v4 = 36;
            break;
        }
      }
    }
    v7 = *v4;
    if ( *v4 == 20 || v7 == 909201952 || v7 == 21 )
      sub_67B433(v53);
    if ( *v4 == 20 )
    {
      sub_67B49D(v53, 255, 1);
      *v4 = 22;
    }
    sub_67AC78(v53, v52);
    v8 = *v4;
    if ( *v4 <= 50 )
    {
      if ( *v4 != 50 )
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
              v12 = v11 - 14;
              if ( v12 )
              {
                if ( v12 != 5 )
                  goto LABEL_65;
                goto LABEL_57;
              }
            }
          }
          v51 = 4;
LABEL_65:
          v13 = sub_67B240(v53, v52);
          if ( v51 != v13 )
            goto LABEL_66;
          v33 = v52;
          v4[3] = v42;
          v32 = v53;
          v4[4] = v48;
          v4[5] = 1;
          v15 = sub_67B223(v32, v33);
          v16 = v4[16] == 0;
          v4[12] = v15;
          v4[13] = 0;
          if ( !v16 )
          {
            v17 = operator new(v48 * v15);
            v4[1] = (int)v17;
            if ( !v17 || (v34 = 4 * v48, v4[14] = 1, (Block = operator new(v34)) == 0) )
            {
LABEL_85:
              v14 = -2147024882;
              goto LABEL_96;
            }
            for ( i = 0; i < v48; ++i )
              *((_DWORD *)Block + i) = v4[1] + i * v4[12];
            sub_67B020(v53, Block);
            if ( *v4 == 41 )
            {
              v44 = 0;
              v46 = 0;
              if ( sub_67B203(v53, v52, 8) )
                sub_67B390(v53, v52, &v50, &v46);
              if ( sub_67B203(v53, v52, 16) )
                sub_67B3C8(v53, v52, &v39, &v44, 0);
              if ( *(float *)(v53 + 304) <= 0.000001 || *(float *)(v53 + 308) <= 0.000001 )
              {
                for ( j = 0; j < 256; ++j )
                  v35[j] = j;
              }
              else
              {
                v19 = *(float *)(v53 + 308);
                v49 = 0;
                v37 = 1.0 / (v19 * *(float *)(v53 + 304));
                do
                {
                  v20 = (__int64)(pow((double)v49 * 0.00392156862745098, v37) * 255.0 + 0.5);
                  v21 = v49++;
                  v22 = v49 < 256;
                  v35[v21] = v20;
                }
                while ( v22 );
              }
              v24 = operator new(0x400u);
              v4[2] = (int)v24;
              if ( !v24 )
                goto LABEL_85;
              v25 = 0;
              v22 = v44 <= 0;
              v4[15] = 1;
              if ( !v22 )
              {
                v26 = 0;
                do
                {
                  v27 = 4 * v25;
                  *(_BYTE *)(v27 + v4[2]) = v35[*(unsigned __int8 *)(v26 + v50)];
                  *(_BYTE *)(v27 + v4[2] + 1) = v35[*(unsigned __int8 *)(v26 + v50 + 1)];
                  *(_BYTE *)(v27 + v4[2] + 2) = v35[*(unsigned __int8 *)(v26 + v50 + 2)];
                  v28 = *(_BYTE *)(v25 + v39);
                  ++v25;
                  *(_BYTE *)(v27 + v4[2] + 3) = v28;
                  v26 += 3;
                }
                while ( v25 < v44 );
              }
              if ( v25 < v46 )
              {
                v29 = 3 * v25;
                do
                {
                  v30 = 4 * v25;
                  *(_BYTE *)(v30 + v4[2]) = v35[*(unsigned __int8 *)(v29 + v50)];
                  *(_BYTE *)(v30 + v4[2] + 1) = v35[*(unsigned __int8 *)(v29 + v50 + 1)];
                  *(_BYTE *)(v30 + v4[2] + 2) = v35[*(unsigned __int8 *)(v29 + v50 + 2)];
                  ++v25;
                  *(_BYTE *)(v30 + v4[2] + 3) = -1;
                  v29 += 3;
                }
                while ( v25 < v46 );
              }
              if ( v25 < 256 )
              {
                v31 = 4 * v25;
                do
                {
                  *(_BYTE *)(v31 + v4[2]) = -1;
                  *(_BYTE *)(v31 + v4[2] + 1) = -1;
                  *(_BYTE *)(v31 + v4[2] + 2) = -1;
                  *(_BYTE *)(v31 + v4[2] + 3) = -1;
                  v31 += 4;
                }
                while ( v31 < 1024 );
              }
            }
          }
          v14 = 0;
          goto LABEL_96;
        }
LABEL_63:
        v51 = 3;
        goto LABEL_65;
      }
LABEL_57:
      v51 = 1;
      goto LABEL_65;
    }
    if ( v8 != 51 )
    {
      if ( v8 == 81 )
        goto LABEL_57;
      if ( v8 != 909200449 )
      {
        if ( v8 != 909201952 )
          goto LABEL_65;
        goto LABEL_63;
      }
    }
    v51 = 2;
    goto LABEL_65;
  }
LABEL_66:
  v14 = -2147467259;
LABEL_96:
  if ( v53 )
    sub_67B184(&v53, &v52, 0);
  if ( Block )
    j__free(Block);
  return v14;
}

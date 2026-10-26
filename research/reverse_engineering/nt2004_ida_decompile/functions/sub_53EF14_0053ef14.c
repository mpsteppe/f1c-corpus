int __thiscall sub_53EF14(int *this, int a2, int a3)
{
  int *v3; // eax
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
  void *v20; // eax
  unsigned int i; // eax
  double v22; // st7
  __int64 v23; // rax
  int v24; // ecx
  bool v25; // cc
  int j; // eax
  void *v27; // eax
  int v28; // eax
  int v29; // edi
  int v30; // ecx
  char v31; // bl
  int v32; // edi
  int v33; // ecx
  int v34; // eax
  int *__attribute__((__org_typedef(jmp_buf))) v35; // [esp+8h] [ebp-168h]
  int v36; // [esp+Ch] [ebp-164h]
  unsigned int v37; // [esp+Ch] [ebp-164h]
  int v38; // [esp+10h] [ebp-160h]
  _BYTE v39[256]; // [esp+1Ch] [ebp-154h]
  double v40; // [esp+11Ch] [ebp-54h] BYREF
  long double v41; // [esp+124h] [ebp-4Ch]
  _DWORD v42[2]; // [esp+12Ch] [ebp-44h] BYREF
  int v43; // [esp+134h] [ebp-3Ch] BYREF
  int v44; // [esp+138h] [ebp-38h] BYREF
  int *v45; // [esp+13Ch] [ebp-34h]
  int v46; // [esp+140h] [ebp-30h] BYREF
  int v47; // [esp+144h] [ebp-2Ch] BYREF
  int v48; // [esp+148h] [ebp-28h] BYREF
  int v49; // [esp+14Ch] [ebp-24h] BYREF
  int v50; // [esp+150h] [ebp-20h] BYREF
  int v51; // [esp+154h] [ebp-1Ch]
  unsigned int v52; // [esp+158h] [ebp-18h] BYREF
  int v53; // [esp+15Ch] [ebp-14h]
  int v54; // [esp+160h] [ebp-10h] BYREF
  int v55; // [esp+164h] [ebp-Ch]
  int v56; // [esp+168h] [ebp-8h] BYREF
  int *__attribute__((__org_typedef(jmp_buf))) Buf; // [esp+16Ch] [ebp-4h] BYREF

  v45 = this;
  Buf = 0;
  v56 = 0;
  v51 = 0;
  if ( sub_550BCB(a2, 0, a3) )
    return -2147467259;
  v3 = (int *)sub_54E879("1.0.5", 0, sub_53EF08, nullsub_8);
  Buf = v3;
  if ( !v3 )
    goto LABEL_86;
  v56 = sub_550CD0(v3);
  if ( !v56 )
    goto LABEL_86;
  if ( !_setjmp3(Buf, 0, v38) )
  {
    v42[0] = a2;
    v42[1] = a3;
    sub_550B8C(Buf, v42, sub_53EEC5);
    sub_54E97C(Buf, v56);
    sub_54F141(Buf, v56, &v46, &v52, &v49, &v47, 0, 0, 0);
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
      sub_54F2B5(Buf);
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
      sub_54F2C7(Buf);
    if ( !v47 && v49 < 8 )
      sub_54F468(Buf);
    if ( sub_54F116(Buf, v56, &v44) )
    {
      sub_550AC9(Buf, v56, v44);
    }
    else if ( sub_54F0ED(Buf, v56, &v40) )
    {
      sub_54F432((int)Buf, 2.2, v40);
    }
    if ( *v4 != 41 && sub_54F0A7(Buf, v56, 16) )
    {
      sub_54F468(Buf);
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
      sub_54F2AC(Buf);
    if ( *v4 == 20 )
    {
      sub_54F2F9(Buf, 255, 1);
      *v4 = 22;
    }
    sub_54EAEF(Buf, v56);
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
            v13 = sub_54F0D7(Buf, v56);
            if ( v55 != v13 )
              goto LABEL_60;
            v36 = v56;
            v4[3] = v46;
            v35 = Buf;
            v4[4] = v52;
            v4[5] = 1;
            v18 = sub_54F0C1(v35, v36);
            v19 = v4[16] == 0;
            v4[12] = v18;
            v4[13] = 0;
            if ( !v19 )
            {
              v20 = operator new(v52 * v18);
              v4[1] = (int)v20;
              if ( !v20 || (v37 = 4 * v52, v4[14] = 1, (v51 = (int)operator new(v37)) == 0) )
              {
LABEL_86:
                v14 = -2147024882;
                goto LABEL_97;
              }
              for ( i = 0; i < v52; ++i )
                *(_DWORD *)(v51 + 4 * i) = v4[1] + i * v4[12];
              sub_54EEB6(Buf, v51);
              if ( *v4 == 41 )
              {
                v48 = 0;
                v50 = 0;
                if ( sub_54F0A7(Buf, v56, 8) )
                  sub_54F212(Buf, v56, &v54, &v50);
                if ( sub_54F0A7(Buf, v56, 16) )
                  sub_54F245(Buf, v56, &v43, &v48, 0);
                if ( *((float *)Buf + 76) <= 0.000001 || *((float *)Buf + 77) <= 0.000001 )
                {
                  for ( j = 0; j < 256; ++j )
                    v39[j] = j;
                }
                else
                {
                  v22 = *((float *)Buf + 77);
                  v53 = 0;
                  v41 = 1.0 / (v22 * *((float *)Buf + 76));
                  do
                  {
                    v23 = (__int64)(pow((double)v53 * 0.00392156862745098, v41) * 255.0 + 0.5);
                    v24 = v53++;
                    v25 = v53 < 256;
                    v39[v24] = v23;
                  }
                  while ( v25 );
                }
                v27 = operator new(0x400u);
                v4[2] = (int)v27;
                if ( !v27 )
                  goto LABEL_86;
                v28 = 0;
                v25 = v48 <= 0;
                v4[15] = 1;
                if ( !v25 )
                {
                  v29 = 0;
                  do
                  {
                    v30 = 4 * v28;
                    *(_BYTE *)(v30 + v4[2]) = v39[*(unsigned __int8 *)(v29 + v54)];
                    *(_BYTE *)(v4[2] + v30 + 1) = v39[*(unsigned __int8 *)(v29 + v54 + 1)];
                    *(_BYTE *)(v4[2] + v30 + 2) = v39[*(unsigned __int8 *)(v29 + v54 + 2)];
                    v31 = *(_BYTE *)(v28 + v43);
                    ++v28;
                    *(_BYTE *)(v4[2] + v30 + 3) = v31;
                    v29 += 3;
                  }
                  while ( v28 < v48 );
                }
                if ( v28 < v50 )
                {
                  v32 = 3 * v28;
                  do
                  {
                    v33 = 4 * v28;
                    *(_BYTE *)(v33 + v4[2]) = v39[*(unsigned __int8 *)(v32 + v54)];
                    *(_BYTE *)(v4[2] + v33 + 1) = v39[*(unsigned __int8 *)(v32 + v54 + 1)];
                    *(_BYTE *)(v4[2] + v33 + 2) = v39[*(unsigned __int8 *)(v32 + v54 + 2)];
                    *(_BYTE *)(v4[2] + v33 + 3) = -1;
                    ++v28;
                    v32 += 3;
                  }
                  while ( v28 < v50 );
                }
                if ( v28 < 256 )
                {
                  v34 = 4 * v28;
                  do
                  {
                    *(_BYTE *)(v34 + v4[2]) = -1;
                    *(_BYTE *)(v34 + v4[2] + 1) = -1;
                    *(_BYTE *)(v34 + v4[2] + 2) = -1;
                    *(_BYTE *)(v34 + v4[2] + 3) = -1;
                    v34 += 4;
                  }
                  while ( v34 < 1024 );
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
  if ( Buf )
    sub_54F026(&Buf, &v56, 0);
  if ( v51 )
    sub_5BE8AE();
  return v14;
}

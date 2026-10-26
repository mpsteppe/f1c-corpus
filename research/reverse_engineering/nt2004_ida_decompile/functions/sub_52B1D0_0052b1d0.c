void __thiscall sub_52B1D0(int this)
{
  double v2; // st7
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  _DWORD *v7; // esi
  double v8; // st7
  int *v9; // eax
  int v10; // edi
  int v11; // esi
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  signed int v17; // ebx
  signed int v18; // edi
  float v19; // ecx
  _DWORD *v20; // esi
  int v21; // ecx
  char *v22; // eax
  int v23; // eax
  signed int v24; // esi
  double v25; // st7
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  float v31; // [esp+0h] [ebp-44h]
  float v32; // [esp+4h] [ebp-40h]
  char v33; // [esp+1Fh] [ebp-25h]
  int v34; // [esp+20h] [ebp-24h]
  int v35; // [esp+20h] [ebp-24h]
  float v36; // [esp+20h] [ebp-24h]
  float v37; // [esp+20h] [ebp-24h]
  float v38; // [esp+20h] [ebp-24h]
  float v39; // [esp+24h] [ebp-20h]
  float v40; // [esp+28h] [ebp-1Ch]
  float v41; // [esp+2Ch] [ebp-18h]
  float v42; // [esp+30h] [ebp-14h]
  float v43; // [esp+34h] [ebp-10h]
  _DWORD v44[3]; // [esp+38h] [ebp-Ch] BYREF

  v2 = *(float *)(this + 4) - dbl_7DA9C8;
  *(float *)(this + 4) = v2;
  if ( (dword_75CBAC & 1) == 0 || dword_7D5DA4 == 2 )
  {
    v33 = 0;
  }
  else
  {
    v33 = 1;
    if ( v2 < 0.0 )
    {
      if ( *(_BYTE *)(this + 60) )
      {
        *(_BYTE *)(this + 60) = 0;
        sub_52A8D0((const char *)(this + 192));
        *(_DWORD *)(this + 64) = -8388609;
      }
      v32 = dbl_7DA9D0 * *(float *)this;
      v31 = (1.0 - *(float *)(this + 4)) * *(float *)this;
      sub_52C170(v31, v32, NumOfElements);
      *(_DWORD *)(this + 4) = 1065353216;
      sub_52AAF0((float *)(this + 28), v44);
      if ( fabs(dbl_7DA9D0 - *(float *)(this + 64)) > 2.5 || memcmp((const void *)(this + 68), v44, 0xCu) )
      {
        v3 = (_DWORD *)dword_7D3C44;
        if ( dword_79FC40 < 1023 )
        {
          ++dword_79FC40;
          dword_7D3C44 += 208;
        }
        *(float *)&v34 = dbl_7DA9D0;
        sub_4D0D00(v3, 2, 4, 12, 63, v34, 0);
        v4 = v44[0];
        v5 = v44[1];
        v6 = v44[2];
        v7 = v3 + 2;
        *v7 = v44[0];
        v7[1] = v5;
        v7[2] = v6;
        v8 = dbl_7DA9D0;
        *(_DWORD *)(this + 68) = v4;
        *(_DWORD *)(this + 72) = v5;
        *(float *)(this + 64) = v8;
        *(_DWORD *)(this + 76) = v6;
      }
    }
    v9 = *(int **)(this + 88);
    if ( v9 )
    {
      v10 = *v9;
      if ( *v9 )
      {
        *(float *)&v35 = dbl_7DA9D0;
        if ( dbl_7DA9D0 > *(float *)v10 )
        {
          v11 = dword_7D3C44;
          if ( dword_79FC40 < 1023 )
          {
            ++dword_79FC40;
            dword_7D3C44 += 208;
          }
          if ( *(_DWORD *)(v10 + 4) == 1 )
            sub_4D0D00((_DWORD *)v11, 2, 6, 1, 63, v35, 0);
          else
            sub_4D0D00((_DWORD *)v11, 3, 6, 1, 63, v35, 0);
          *(_BYTE *)(v11 + 8) = (__int64)(*(float *)(v10 + 8) * 255.0);
          v12 = *(_DWORD *)(this + 88);
          if ( v12 )
            *(_DWORD *)(this + 88) = *(_DWORD *)(v12 + 4);
        }
      }
    }
  }
  if ( *(float *)(this + 4) > 0.0 )
  {
    v13 = dbl_7DA9C8 / (dbl_7DA9C8 + *(float *)(this + 4));
    *(float *)(this + 8) = v13 * *(float *)(this + 28) + (1.0 - v13) * *(float *)(this + 8);
  }
  else
  {
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 28);
  }
  if ( *(float *)(this + 8) >= 1.0 )
    v14 = 0.5 - *(float *)(this + 32) * 0.5;
  else
    v14 = 1.0 - *(float *)(this + 8) * 0.5;
  v36 = v14;
  if ( *(float *)(this + 24) != 0.0 )
  {
    if ( dword_767CA0 > 1 )
      v36 = (1.0 - v36) * *(float *)(this + 24) + v36;
    *(_DWORD *)(this + 24) = 0;
  }
  if ( fabs(*(float *)(this + 12) - v36) > 0.017999999 )
  {
    sub_597AE0(0);
    if ( v36 >= 0.0 )
    {
      if ( v36 > 1.0 )
        v36 = 1.0;
    }
    else
    {
      v36 = 0.0;
    }
    *(float *)(this + 12) = v36;
    sub_5B5A90(2, LODWORD(v36));
  }
  v15 = (*(float *)(this + 40) - *(float *)(this + 36)) * 4.0;
  v37 = v15;
  if ( v15 >= 0.0 )
  {
    if ( v37 > 1.0 )
      v37 = 1.0;
  }
  else
  {
    v37 = 0.0;
  }
  if ( fabs(*(float *)(this + 160) - v37) > 0.003 )
  {
    *(float *)(this + 160) = v37;
    sub_4F6B00(&dword_7D73D0, 10, v37);
  }
  v16 = ((*(float *)(this + 40) + *(float *)(this + 36)) * 0.5 + *(float *)(this + 32)) * 0.5;
  v39 = (5.0 - *(float *)(this + 176)) * v16 + *(float *)(this + 176);
  v38 = (150.0 - *(float *)(this + 180)) * v16 + *(float *)(this + 180);
  v40 = (0.0099999998 - *(float *)(this + 184)) * v16 + *(float *)(this + 184);
  if ( v16 <= *(float *)(this + 8) )
    v16 = *(float *)(this + 8);
  v43 = (0.5 - *(float *)(this + 164)) * v16 + *(float *)(this + 164);
  v42 = (0.5 - *(float *)(this + 168)) * v16 + *(float *)(this + 168);
  v41 = (0.5 - *(float *)(this + 172)) * v16 + *(float *)(this + 172);
  sub_595AC0(v39, v38);
  sub_595B30(v40);
  sub_595A80((__int64)(v43 * 255.0), (__int64)(v42 * 255.0), (__int64)(v41 * 255.0));
  if ( *(float *)(this + 40) > 0.0 )
    *(_DWORD *)(this + 16) = 1;
  if ( fabs(*(float *)(this + 36) - *(float *)(this + 20)) > 0.0099999998 )
  {
    if ( v33 )
    {
      if ( *(float *)(this + 36) > 0.18000001 && *(float *)(this + 20) <= 0.18000001 )
      {
        v17 = NumOfElements;
        v18 = 0;
        if ( (int)NumOfElements > 0 )
        {
          while ( 1 )
          {
            v19 = dword_75AAD0[v18];
            v20 = *(_DWORD **)(LODWORD(v19) + 18780);
            v21 = LODWORD(v19) + 84;
            if ( v20 )
            {
              v22 = sub_51E210(v21);
              v23 = sub_500A20(v20, v22);
              if ( v23 )
              {
                if ( !*(_BYTE *)(v23 + 20) )
                  break;
              }
            }
            if ( ++v18 >= v17 )
              goto LABEL_61;
          }
          if ( v18 < v17 )
          {
            sub_4F9D50((int)aStewardHasThro);
            v24 = 0;
            do
              sub_42D790((_DWORD *)LODWORD(dword_75AAD0[v24++]));
            while ( v24 < v17 );
          }
        }
      }
    }
LABEL_61:
    v25 = *(float *)(this + 36);
    v26 = dword_7D73D8;
    *(float *)(this + 20) = *(float *)(this + 36);
    if ( v25 <= 0.029999999 )
    {
      if ( v26 > 0 )
      {
        v29 = 0;
        do
        {
          v30 = v29 + dword_7D73DC;
          if ( *(_DWORD *)(dword_7D73DC + v29 + 44) == 7 )
            *(_DWORD *)(v30 + 44) = 6;
          if ( *(_DWORD *)(v30 + 48) == 23 )
            *(_DWORD *)(v30 + 48) = 22;
          v29 += 104;
          --v26;
        }
        while ( v26 );
      }
    }
    else if ( v26 > 0 )
    {
      v27 = 0;
      do
      {
        v28 = v27 + dword_7D73DC;
        if ( *(_DWORD *)(dword_7D73DC + v27 + 44) == 6 )
          *(_DWORD *)(v28 + 44) = 7;
        if ( *(_DWORD *)(v28 + 48) == 22 )
          *(_DWORD *)(v28 + 48) = 23;
        v27 += 104;
        --v26;
      }
      while ( v26 );
    }
  }
}

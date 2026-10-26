char __thiscall sub_4FA900(int this)
{
  bool v2; // cl
  double v3; // st7
  signed int k; // eax
  signed int v5; // ecx
  char v6; // dl
  signed int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // eax
  float *v12; // ecx
  float *v13; // eax
  _DWORD *v14; // ecx
  long double v15; // st7
  float *v16; // eax
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  _DWORD *v20; // ecx
  signed int i; // eax
  char v22; // dl
  signed int j; // eax
  unsigned __int8 v24; // cl
  int v25; // edi
  int v26; // esi
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v31; // [esp+0h] [ebp-74h]
  int v32; // [esp+8h] [ebp-6Ch]
  char v33; // [esp+1Ah] [ebp-5Ah]
  char v34; // [esp+1Bh] [ebp-59h]
  signed int v35; // [esp+1Ch] [ebp-58h]
  float v36; // [esp+1Ch] [ebp-58h]
  float v37; // [esp+20h] [ebp-54h]
  float v38; // [esp+24h] [ebp-50h]
  float v39; // [esp+28h] [ebp-4Ch]
  float v40; // [esp+40h] [ebp-34h]
  unsigned __int8 Base[48]; // [esp+44h] [ebp-30h] BYREF

  v33 = 0;
  v2 = *(_DWORD *)(this + 280) == 1;
  v3 = *(float *)(this + 296) - dbl_7DA9C8;
  *(float *)(this + 296) = v3;
  if ( v3 <= 0.0 )
  {
    v33 = 1;
    *(_DWORD *)(this + 296) = 1048576000;
  }
  if ( v2 || (LOBYTE(k) = v33) != 0 )
  {
    v5 = NumOfElements;
    v6 = 0;
    v7 = 0;
    v34 = 0;
    v35 = 0;
    if ( (int)NumOfElements > 0 )
    {
      while ( 1 )
      {
        v8 = sub_514EE0(dword_75AAD0[v7] + 84);
        v9 = dword_75AAD0[v7];
        v10 = v8;
        v11 = *(_DWORD *)(v9 + 20852);
        if ( v11 != 2 || *(_DWORD *)(v10 + 112) )
        {
          if ( v11 || *(_DWORD *)(v10 + 112) != 2 )
          {
            v12 = *(float **)(v10 + 296);
            v13 = *(float **)(v10 + 292);
            v37 = *v12 - *v13;
            v38 = v12[1] - v13[1];
            v39 = v12[2] - v13[2];
            if ( v37 == 0.0 && v38 == 0.0 && v39 == 0.0 )
            {
              *(float *)(v9 + 20856) = *(float *)(v10 + 116);
              goto LABEL_27;
            }
            v14 = *(_DWORD **)(v9 + 20836);
            v15 = 1.0 / sqrt(v39 * v39 + v38 * v38 + v37 * v37);
            v40 = *(float *)(v9 + 17612) - *(float *)(v10 + 8);
            *(float *)(v9 + 20856) = v39 * v15 * v40
                                   + v38 * v15 * (*(float *)(v9 + 17608) - *(float *)(v10 + 4))
                                   + (*(float *)(v9 + 17604) - *(float *)v10) * (v37 * v15)
                                   + *(float *)(v10 + 116);
            if ( sub_4EED40(v14) )
              sub_41A080((int)flt_629328);
            v7 = v35;
          }
          else
          {
            *(_DWORD *)(v9 + 20856) = 0;
          }
        }
        else
        {
          *(float *)(v9 + 20856) = flt_6290D0;
        }
        if ( !*(_DWORD *)(v10 + 328) )
        {
          v16 = (float *)dword_75AAD0[v7];
          v36 = *(float *)(this + 252)
              - sqrt(v16[4409] * v16[4409] + v16[4407] * v16[4407] + v16[4408] * v16[4408]) * 5.0;
          if ( v18 | v19 )
          {
            if ( *(float *)(v9 + 20856) >= (double)*(float *)(this + 252) && flt_6290D0 + v36 >= *(float *)(v9 + 20856) )
              goto LABEL_27;
          }
          else if ( *(float *)(v9 + 20856) >= (double)*(float *)(this + 252) || *(float *)(v9 + 20856) <= (double)v36 )
          {
            goto LABEL_27;
          }
          v34 = 1;
        }
LABEL_27:
        v5 = NumOfElements;
        v35 = ++v7;
        if ( v7 >= (int)NumOfElements )
        {
          v6 = v34;
          break;
        }
      }
    }
    if ( v6 != *(_BYTE *)(this + 256) && v33 )
    {
      v20 = (_DWORD *)dword_7D3C44;
      if ( dword_79FC40 < 1023 )
      {
        ++dword_79FC40;
        dword_7D3C44 += 208;
      }
      *(float *)&v31 = dbl_7DA9D0;
      if ( v6 )
        sub_4D0D00(v20, 4, 33, 0, 63, v31, 0);
      else
        sub_4D0D00(v20, 4, 34, 0, 63, v31, 0);
      v5 = NumOfElements;
    }
    for ( i = 0; i < v5; ++i )
      Base[i] = *(_BYTE *)(dword_75AAD0[i] + 25248);
    if ( dword_75CBB0 == 7 )
    {
      qsort(Base, v5, 1u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_4F8B20);
      if ( dword_768F3C > 0 )
        sub_4F9200((float *)this, Base);
    }
    else
    {
      qsort(Base, v5, 1u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_4F8A50);
    }
    v22 = 0;
    for ( j = 0; j < (int)NumOfElements; ++j )
    {
      v24 = Base[j];
      if ( *(_BYTE *)(j + this + 304) != v24 )
      {
        v22 = 1;
        *(_BYTE *)(j + this + 304) = v24;
      }
    }
    v25 = *(_DWORD *)(this + 300) + 1;
    *(_DWORD *)(this + 300) = v25;
    LOBYTE(k) = v25;
    if ( v33 && (v22 || (v25 & 0xF) == 0) )
    {
      LOBYTE(k) = NumOfElements;
      if ( (int)NumOfElements > 0 )
      {
        *(_DWORD *)(this + 300) = 0;
        v26 = dword_7D3C44;
        if ( dword_79FC40 < 1023 )
        {
          ++dword_79FC40;
          dword_7D3C44 += 208;
        }
        *(float *)&v32 = dbl_7DA9D0;
        sub_4D0D00((_DWORD *)v26, 4, 7, NumOfElements + 13, 63, v32, 0);
        v27 = 0;
        v28 = v26 + 8;
        do
        {
          v29 = v27 + 6326 * *(unsigned __int8 *)(this + 304);
          ++v27;
          v28 += 4;
          *(float *)(v28 - 4) = flt_631154[v29];
        }
        while ( v27 < 3 );
        if ( *(_BYTE *)(this + 1196) )
        {
          *(_BYTE *)(v26 + 20) = 1;
          *(_BYTE *)(this + 1196) = 0;
        }
        else
        {
          *(_BYTE *)(v26 + 20) = 0;
        }
        for ( k = 0; k < (int)NumOfElements; ++k )
          *(_BYTE *)(v26 + k + 21) = *(_BYTE *)(k + this + 304);
      }
    }
  }
  return k;
}

void __thiscall sub_50E070(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edi
  int i; // esi
  int v8; // ecx
  int v9; // ecx
  int v10; // edi
  float *v11; // eax
  long double v12; // st7
  int v13; // esi
  int v14; // ecx
  float *v15; // edx
  long double v16; // st0
  long double v17; // st1
  long double v18; // st7
  bool v19; // c0
  float *v20; // esi
  int v21; // esi
  _DWORD *v22; // edi
  int v23; // eax
  float *v24; // edx
  int v25; // edi
  int v26; // ecx
  float *v27; // esi
  double v28; // st6
  double v29; // st3
  double v30; // st4
  double v31; // st7
  int v32; // ecx
  float v33; // ebp
  double v34; // st7
  double v35; // st6
  double v36; // st5
  float *v37; // edx
  long double v38; // st7
  int v39; // [esp+10h] [ebp-2Ch]
  float v40; // [esp+14h] [ebp-28h]
  float v41; // [esp+14h] [ebp-28h]
  int j; // [esp+18h] [ebp-24h]
  float v43; // [esp+1Ch] [ebp-20h]
  float v44; // [esp+20h] [ebp-1Ch]
  float v45; // [esp+24h] [ebp-18h]
  int v46; // [esp+28h] [ebp-14h]
  int v47; // [esp+2Ch] [ebp-10h] BYREF
  int v48; // [esp+30h] [ebp-Ch]
  int v49; // [esp+34h] [ebp-8h]
  int v50; // [esp+38h] [ebp-4h]

  v43 = 0.0;
  v47 = 2139095039;
  v44 = 0.0;
  v45 = 0.0;
  v48 = 2139095039;
  v49 = 2139095039;
  v46 = 0;
  v2 = this + 129;
  v50 = 2139095039;
  v3 = 4;
  do
  {
    v4 = *(v2 - 41);
    *(v2 - 1) = 0;
    *v2 = 0;
    v2[1] = v4;
    v2 += 76;
    --v3;
  }
  while ( v3 );
  v5 = this[631];
  this[679] = 0;
  if ( v5 )
  {
    v6 = sub_59EFD0(v5);
    for ( i = 0; i < v6; ++i )
    {
      v8 = sub_59EFF0(i);
      if ( *(float *)(v8 + 244) == 0.0 )
        this[679] = v8;
    }
    v9 = this[679];
    if ( v9 )
    {
      v10 = 0;
      v39 = sub_59CB20(v9);
      if ( v39 > 0 )
      {
        do
        {
          v11 = (float *)sub_59CB40(v10);
          v12 = *v11;
          v13 = 0;
          v40 = 3.4028235e38;
          v14 = 0;
          v15 = (float *)(this + 88);
          do
          {
            v16 = v12 - *(v15 - 2);
            v17 = (v11[2] - *v15) * (v11[2] - *v15) + (v11[1] - *(v15 - 1)) * (v11[1] - *(v15 - 1)) + v16 * v16;
            if ( v17 < v40 )
            {
              v40 = v17;
              v13 = v14;
            }
            ++v14;
            v15 += 76;
          }
          while ( v14 < 4 );
          ++*((_DWORD *)&v43 + v13);
          v18 = fabs(v12);
          v19 = v18 < *((float *)&v47 + v13);
          v20 = (float *)(&v47 + v13);
          if ( v19 )
            *v20 = v18;
          ++v10;
        }
        while ( v10 < v39 );
      }
      v47 = 1036831949;
      v48 = 1036831949;
      v49 = 1036831949;
      v50 = 1036831949;
      v21 = 0;
      v22 = this + 129;
      do
      {
        *v22 = operator new(32 * *((_DWORD *)&v43 + v21++));
        v22 += 76;
      }
      while ( v21 < 4 );
      v23 = 0;
      for ( j = 0; j < v39; ++j )
      {
        v24 = (float *)sub_59CB40(v23);
        v25 = 0;
        v43 = *v24;
        v41 = 3.4028235e38;
        v44 = v24[1];
        v26 = 0;
        v45 = v24[2];
        v27 = (float *)(this + 88);
        do
        {
          v28 = v44 - *(v27 - 1);
          v29 = v43 - *(v27 - 2);
          v30 = (v45 - *v27) * (v45 - *v27) + v28 * v28 + v29 * v29;
          if ( v30 < v41 )
          {
            v41 = v30;
            v25 = v26;
          }
          ++v26;
          v27 += 76;
        }
        while ( v26 < 4 );
        v31 = v43;
        v32 = this[76 * v25 + 129] + 32 * this[76 * v25 + 128];
        v33 = v43;
        ++this[76 * v25 + 128];
        *(float *)v32 = v33;
        *(float *)(v32 + 4) = v44;
        *(float *)(v32 + 8) = v45;
        v34 = v31 - *(float *)&this[76 * v25 + 86];
        v35 = v44 - *(float *)&this[76 * v25 + 87];
        v36 = v45 - *(float *)&this[76 * v25 + 88];
        *(float *)(v32 + 12) = v36 * *(float *)&this[76 * v25 + 98]
                             + v35 * *(float *)&this[76 * v25 + 95]
                             + v34 * *(float *)&this[76 * v25 + 92];
        *(float *)(v32 + 16) = v36 * *(float *)&this[76 * v25 + 99]
                             + v35 * *(float *)&this[76 * v25 + 96]
                             + v34 * *(float *)&this[76 * v25 + 93];
        *(float *)(v32 + 20) = v36 * *(float *)&this[76 * v25 + 100]
                             + v35 * *(float *)&this[76 * v25 + 97]
                             + v34 * *(float *)&this[76 * v25 + 94];
        *(_DWORD *)(v32 + 28) = v24;
        v37 = (float *)(&v47 + v25);
        v38 = fabs(*(float *)&this[76 * v25 + 86]) - *v37 - 0.090000004;
        if ( v38 > 0.0 )
          *(float *)(v32 + 24) = (fabs(v43) - *v37) / v38;
        else
          *(_DWORD *)(v32 + 24) = 0;
        v23 = j + 1;
      }
    }
  }
}

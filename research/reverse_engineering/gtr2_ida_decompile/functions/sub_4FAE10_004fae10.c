char __thiscall sub_4FAE10(float *this, _DWORD *a2)
{
  char result; // al
  int v4; // eax
  int v5; // edx
  int i; // esi
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  float v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st6
  double v19; // st5
  double v20; // st6
  double v21; // st7
  double v22; // st7
  int v23; // esi
  float v24; // [esp+4h] [ebp-4h]
  int v25; // [esp+Ch] [ebp+4h]
  float v26; // [esp+Ch] [ebp+4h]

  if ( dbl_FB1D18 > flt_FADE20 )
    return 0;
  if ( a2[5192] != 4 || !sub_4FB7D0(a2 + 3706) || (v4 = sub_4FB7D0(a2 + 3706), sub_4F1EF0(v4)) )
  {
    v5 = dword_757C10;
    for ( i = 0; i < v5; ++i )
    {
      v7 = LODWORD(this[i]);
      if ( v7 )
      {
        if ( *(_DWORD *)(v7 + 20852) )
        {
          v8 = sub_422780(v7);
          v9 = sub_41FB10(a2, v8);
          if ( v9 < 0.0 && v9 > -55.0 )
          {
            v10 = this[i];
            v11 = *(_DWORD *)(LODWORD(v10) + 20768);
            if ( v11 != 4 && v11 != 5 && *(float *)(LODWORD(v10) + 20476) > 2.0 )
              return 0;
          }
        }
        else
        {
          this[i] = 0.0;
        }
        v5 = dword_757C10;
      }
    }
    if ( *(_DWORD *)dword_B640C8 == 6 )
      return 1;
    if ( a2[5228] > a2[5374] )
    {
      v12 = v5;
      v13 = 0;
      v25 = v5;
      if ( v5 > 0 )
      {
        do
        {
          if ( LODWORD(this[v13]) )
            --v12;
          ++v13;
        }
        while ( v13 < v5 );
        v25 = v12;
      }
      if ( *(_DWORD *)dword_B640C8 == 2 || *(_DWORD *)dword_B640C8 == 4 || *(_DWORD *)dword_B640C8 == 3 )
      {
        v14 = (double)v25;
        v15 = (double)dword_757C10 * 0.80000001;
      }
      else
      {
        v14 = (double)v25;
        v15 = (double)dword_757C10 * 0.89999998;
      }
      v16 = 1.0 - v14 / (v15 + 1.0);
      if ( v16 < 0.0099999998 )
        v16 = 0.0099999998;
      v26 = dbl_FB1D18;
      if ( this[104] < (double)v26 )
      {
        result = 1;
        this[104] = v26 + 4.0;
        return result;
      }
      v17 = v16 * 6.0;
      if ( v17 == 0.0 )
        v17 = 0.001;
      v18 = flt_FADE1C + 1300.0;
      if ( v18 >= flt_FADE20 )
        v19 = flt_FADE20;
      else
        v19 = v18;
      if ( v19 - flt_FADE1C >= 1.0 )
      {
        if ( v18 >= flt_FADE20 )
          v18 = flt_FADE20;
        v20 = v18 - flt_FADE1C;
      }
      else
      {
        v20 = 1.0;
      }
      v21 = v20 / v17 * 0.25;
      if ( v21 >= 1.0 )
      {
        v23 = rand();
        if ( *(_DWORD *)dword_B640C8 == 6 || (v24 = v21, !(v23 % (int)(unsigned __int64)v24)) )
        {
          v22 = dbl_FB1D18;
          if ( dbl_FB1D18 >= this[104] )
            goto LABEL_46;
        }
      }
      else if ( this[104] < (double)v26 )
      {
        v22 = v26;
LABEL_46:
        this[104] = v22 + 6.0;
        return 1;
      }
    }
  }
  return 0;
}

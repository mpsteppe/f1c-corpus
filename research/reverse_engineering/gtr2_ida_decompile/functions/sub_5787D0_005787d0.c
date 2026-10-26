void __thiscall sub_5787D0(int this, float *a2)
{
  float *v3; // edi
  double v4; // st7
  int v5; // eax
  int v6; // eax
  double v7; // st7
  long double v8; // st6
  int v9; // esi
  int v10; // edx
  long double v11; // st5
  long double v12; // st4
  long double v13; // st4
  long double v14; // st4
  long double v15; // st4
  long double v16; // st6
  long double v17; // st5
  int v18; // eax
  bool v19; // zf
  double v20[3]; // [esp+10h] [ebp-18h] BYREF
  float v21; // [esp+2Ch] [ebp+4h]

  *(float *)(this + 15996) = *a2;
  v3 = (float *)*((_DWORD *)a2 + 1);
  *(_DWORD *)(this + 16000) = v3;
  *(float *)(this + 16004) = a2[2];
  *(float *)(this + 16008) = *(float *)(this + 15960) * *(float *)(this + 16004)
                           + *(float *)(this + 15948) * *(float *)(this + 16000)
                           + *(float *)(this + 15996) * *(float *)(this + 15936);
  *(float *)(this + 16012) = *(float *)(this + 15964) * *(float *)(this + 16004)
                           + *(float *)(this + 15952) * *(float *)(this + 16000)
                           + *(float *)(this + 15940) * *(float *)(this + 15996);
  *(float *)(this + 16016) = *(float *)(this + 15968) * *(float *)(this + 16004)
                           + *(float *)(this + 15956) * *(float *)(this + 16000)
                           + *(float *)(this + 15944) * *(float *)(this + 15996);
  v4 = *(float *)(this + 16016);
  *(_DWORD *)(this + 16020) = 0;
  *(_DWORD *)(this + 16024) = 0;
  v21 = -v4;
  *(_DWORD *)(this + 16028) = 0;
  *(float *)(this + 16196) = -1.0 / *(float *)(this + 16292) * v21;
  *(float *)(this + 16448) = -1.0 / *(float *)(this + 16544) * v21;
  *(float *)(this + 16700) = -1.0 / *(float *)(this + 16796) * v21;
  *(float *)(this + 16952) = -1.0 / *(float *)(this + 17048) * v21;
  v5 = *(_DWORD *)(this + 17244);
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        v7 = (*(float *)(this + 16196) + *(float *)(this + 16448)) * 0.5;
      else
        v7 = v21;
    }
    else
    {
      v7 = (*(float *)(this + 16196) + *(float *)(this + 16952) + *(float *)(this + 16700) + *(float *)(this + 16448))
         * 0.25;
    }
  }
  else
  {
    v7 = (*(float *)(this + 16952) + *(float *)(this + 16700)) * 0.5;
  }
  v8 = fabs(v21) * 0.018 + 0.2;
  if ( v8 >= 0.0 )
  {
    if ( v8 > 0.80000001 )
      v8 = 0.80000001;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = *(_DWORD *)(this + 17312);
  v10 = v9;
  *(float *)(this + 17212) = -(v7 * *(float *)(this + 4 * v9 + 17268));
  if ( v9 >= 4 )
  {
    v3 = (float *)(this + 4 * v9 + 17264);
    v11 = v8 * *(float *)(this + 17216);
    do
    {
      v12 = -(v7 * v3[1]);
      if ( v12 < v11 )
      {
        *(float *)(this + 17212) = v12;
        v9 = v10;
      }
      v13 = -(v7 * *v3);
      if ( v13 < v11 )
      {
        *(float *)(this + 17212) = v13;
        v9 = v10 - 1;
      }
      v14 = -(v7 * *(v3 - 1));
      if ( v14 < v11 )
      {
        *(float *)(this + 17212) = v14;
        v9 = v10 - 2;
      }
      v15 = -(v7 * *(v3 - 2));
      if ( v15 < v11 )
      {
        *(float *)(this + 17212) = v15;
        v9 = v10 - 3;
      }
      v10 -= 4;
      v3 -= 4;
    }
    while ( v10 > 3 );
  }
  if ( v10 > 0 )
  {
    v16 = v8 * *(float *)(this + 17216);
    v3 = (float *)(this + 4 * v10 + 17268);
    do
    {
      v17 = -(v7 * *v3);
      if ( v17 < v16 )
      {
        *(float *)(this + 17212) = v17;
        v9 = v10;
      }
      --v10;
      --v3;
    }
    while ( v10 > 0 );
  }
  if ( *(float *)(this + 17212) < (double)*(float *)(this + 17220) )
  {
    v18 = *(_DWORD *)(this + 17220);
    *(_DWORD *)(this + 17304) = 0;
    *(_DWORD *)(this + 17212) = v18;
  }
  else
  {
    *(_DWORD *)(this + 17304) = v9;
  }
  v19 = *(_DWORD *)(this + 14804) == 0;
  *(_DWORD *)(this + 17308) = -2;
  if ( v19 )
  {
    v20[0] = *a2;
    v20[1] = a2[1];
    v20[2] = a2[2];
    sub_456A10((int)&dbl_B66040, (int)v3, v9, v20);
  }
}

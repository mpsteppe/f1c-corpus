int __thiscall sub_440E20(int this)
{
  int result; // eax
  int v3; // edi
  double v4; // st7
  double X; // st7
  int v6; // eax
  int v7; // ecx
  double v8; // st6
  int v9; // edi
  double v10; // st7
  double v11; // st7
  int v12; // eax
  int v13; // ecx
  double v14; // st7
  int v15; // eax
  int v16; // ecx
  int i; // [esp+10h] [ebp-20h]
  float v18; // [esp+10h] [ebp-20h]
  int j; // [esp+10h] [ebp-20h]
  float v20; // [esp+10h] [ebp-20h]
  float v21; // [esp+14h] [ebp-1Ch]
  float v22; // [esp+18h] [ebp-18h]
  float v23; // [esp+18h] [ebp-18h]
  float v24; // [esp+18h] [ebp-18h]
  float v25; // [esp+1Ch] [ebp-14h]
  float v26; // [esp+1Ch] [ebp-14h]
  float v27; // [esp+1Ch] [ebp-14h]
  float v28; // [esp+1Ch] [ebp-14h]
  float v29; // [esp+20h] [ebp-10h]
  float v30; // [esp+28h] [ebp-8h]

  if ( *(_DWORD *)(this + 8708)
    || (result = 1072693248, *(_DWORD *)(this + 8712) != 1072693248)
    || *(_DWORD *)(this + 8716)
    || *(_DWORD *)(this + 8720) != 1072693248 )
  {
    v3 = 0;
    v29 = 0.0;
    v25 = -3.4028235e38;
    for ( i = 0; v3 < *(_DWORD *)(this + 8108); i = v3 )
    {
      v4 = (double)i * 32.0;
      v18 = v4;
      X = v4 * 0.03125;
      v21 = X;
      v22 = floor(X);
      v6 = *(_DWORD *)(this + 8096);
      v7 = (int)v22;
      v8 = ((*(float *)(v6 + 8 * v7 + 12) - *(float *)(v6 + 8 * v7 + 4)) * (v21 - v22)
          + *(float *)(v6 + 8 * v7 + 4)
          + (*(float *)(v6 + 8 * v7 + 8) - *(float *)(v6 + 8 * v7)) * (v21 - v22)
          + *(float *)(v6 + 8 * v7))
         * v18;
      if ( v8 > v25 )
      {
        v25 = v8;
        v29 = v18;
      }
      ++v3;
    }
    result = *(_DWORD *)(this + 8108);
    v9 = 0;
    for ( j = 0; v9 < result; j = v9 )
    {
      v10 = (double)j * 32.0;
      v20 = v10;
      v11 = v10 * 0.03125;
      v30 = v11;
      v26 = v11;
      v23 = floor(v11);
      v12 = *(_DWORD *)(this + 8096);
      v13 = (int)v23;
      v27 = (*(float *)(v12 + 8 * v13 + 12) - *(float *)(v12 + 8 * v13 + 4)) * (v26 - v23)
          + *(float *)(v12 + 8 * v13 + 4)
          + (*(float *)(v12 + 8 * v13 + 8) - *(float *)(v12 + 8 * v13)) * (v26 - v23)
          + *(float *)(v12 + 8 * v13);
      if ( v27 > 0.0 )
      {
        v14 = 1.0 - v20 / v29 * (v20 / v29 * (v20 / v29) * (v20 / v29));
        if ( v14 > 0.0 )
          *(float *)(*(_DWORD *)(this + 8096) + 8 * v9 + 4) = ((*(double *)(this + 8708) - 1.0) * v14 + 1.0) * v27
                                                            - *(float *)(*(_DWORD *)(this + 8096) + 8 * v9);
        v24 = v20 / *(double *)(this + 8064) * (*(double *)(this + 8716) - 1.0) + 1.0;
        v28 = floor(v30);
        v15 = *(_DWORD *)(this + 8096);
        v16 = (int)v28;
        *(float *)(v15 + 8 * v9 + 4) = ((*(float *)(v15 + 8 * v16 + 12) - *(float *)(v15 + 8 * v16 + 4)) * (v30 - v28)
                                      + *(float *)(v15 + 8 * v16 + 4)
                                      + (*(float *)(v15 + 8 * v16 + 8) - *(float *)(v15 + 8 * v16)) * (v30 - v28)
                                      + *(float *)(v15 + 8 * v16))
                                     * v24
                                     - *(float *)(v15 + 8 * v9);
      }
      result = *(_DWORD *)(this + 8108);
      ++v9;
    }
  }
  return result;
}

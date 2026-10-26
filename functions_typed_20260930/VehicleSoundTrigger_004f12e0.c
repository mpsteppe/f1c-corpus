void __thiscall sub_4F12E0(int this, float a2)
{
  int v3; // edi
  int v4; // ebp
  int v5; // esi
  int v6; // edx
  int i; // eax
  int j; // eax
  int v9; // esi
  int m; // esi
  double v11; // st6
  double v12; // st5
  double v13; // st3
  long double v14; // st7
  int v15; // eax
  float v16; // [esp+0h] [ebp-38h]
  float k; // [esp+8h] [ebp-30h]
  float v18[11]; // [esp+Ch] [ebp-2Ch]
  int v19; // [esp+3Ch] [ebp+4h]
  float v20; // [esp+3Ch] [ebp+4h]
  float v21; // [esp+3Ch] [ebp+4h]

  if ( LOBYTE(a2) )
  {
    v3 = 0;
    v4 = 0;
    v5 = this + 13928;
    v19 = 4;
    do
    {
      if ( *(_DWORD *)v5 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 84);
        for ( i = 0; i < v3; ++i )
        {
          if ( LODWORD(v18[i + 5]) == *(_DWORD *)(v6 + 52) )
            break;
        }
        if ( i == v3 )
          v18[v3++ + 5] = *(float *)(v6 + 52);
        for ( j = 0; j < v4; ++j )
        {
          if ( LODWORD(v18[j]) == *(_DWORD *)(v6 + 48) )
            break;
        }
        if ( j == v4 )
          v18[v4++] = *(float *)(v6 + 48);
      }
      v5 += 248;
      --v19;
    }
    while ( v19 );
    v9 = 0;
    for ( k = sqrt(
                *(float *)(this + 13548) * *(float *)(this + 13548)
              + *(float *)(this + 13552) * *(float *)(this + 13552)
              + *(float *)(this + 13556) * *(float *)(this + 13556)); v9 < v3; ++v9 )
      WheelContactForceAggregation((float *)this, LODWORD(v18[v9 + 5]));
    for ( m = 0; m < v4; ++m )
      WheelForceAggregation((char *)this, LODWORD(v18[m]), k);
    v11 = *(float *)(this + 14940) - *(float *)(this + 13552);
    v12 = *(float *)(this + 14944) - *(float *)(this + 13556);
    v13 = *(float *)(this + 14936) - *(float *)(this + 13548);
    v14 = (sqrt(v12 * v12 + v11 * v11 + v13 * v13) - 2.0) * 0.010204081;
    v20 = v14;
    if ( v14 > 0.0 )
    {
      if ( v20 <= 1.0 )
        v21 = v20 * v20;
      else
        v21 = 1.0;
      v16 = k * 0.00390625 + 0.89999998;
      HUDElementConfig(5, 1, v21, v16);
    }
  }
  if ( *(float *)(this + 1956) <= 0.0 )
    *(_BYTE *)(this + 1532) = 0;
  else
    HUDElementConfig(42, 2, *(float *)(this + 1956), 1.0);
  v15 = *(_DWORD *)(this + 12988);
  if ( !v15 )
  {
    if ( dbl_7C9138 <= dbl_7C9150 )
      return;
    goto LABEL_32;
  }
  if ( v15 == 1 && *(float *)(this + 14776) > (double)*(float *)(this + 14788) )
LABEL_32:
    HUDElementConfig(38, 2, 1.0, 1.0);
}


int __thiscall sub_528C20(int this)
{
  int result; // eax
  float *v2; // eax
  _DWORD *v3; // eax
  long double v4; // st4
  float *v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  long double v9; // st7
  int v10; // ebx
  int v11; // edi
  float *v12; // ebp
  double v13; // st7
  double v14; // st6
  long double v15; // st5
  long double v16; // st7
  double v17; // st7
  int v18; // eax
  double v19; // st6
  double v20; // st7
  int v21; // eax
  double v22; // st6
  char v23; // [esp+13h] [ebp-9h]
  float v24; // [esp+18h] [ebp-4h]

  result = *(_DWORD *)(this + 328);
  if ( result < dword_628FA4 )
  {
    v2 = *(float **)(this + 296);
    if ( v2 )
    {
      *(float *)(this + 212) = v2[49] - *(float *)(this + 196);
      *(float *)(this + 216) = v2[50] - *(float *)(this + 200);
      *(float *)(this + 220) = v2[51] - *(float *)(this + 204);
    }
    else
    {
      v3 = *(_DWORD **)(this + 292);
      if ( v3 )
      {
        *(_DWORD *)(this + 212) = v3[53];
        *(_DWORD *)(this + 216) = v3[54];
        *(_DWORD *)(this + 220) = v3[55];
      }
    }
    *(float *)(this + 156) = *(float *)(this + 76) - 1.5 + *(float *)(this + 208);
    *(float *)(this + 160) = *(float *)(this + 80) - 1.5 - *(float *)(this + 208);
    *(float *)(this + 124) = *(float *)(this + 68) - 1.5 + *(float *)(this + 208);
    *(float *)(this + 128) = *(float *)(this + 72) - 1.5 - *(float *)(this + 208);
    *(float *)(this + 148) = *(float *)(this + 140) + *(float *)(this + 68);
    *(float *)(this + 152) = *(float *)(this + 144) + *(float *)(this + 72);
    *(float *)(this + 104) = sqrt(
                               *(float *)(this + 212) * *(float *)(this + 212)
                             + *(float *)(this + 216) * *(float *)(this + 216)
                             + *(float *)(this + 220) * *(float *)(this + 220));
    if ( *(float *)(this + 212) != 0.0 || *(float *)(this + 216) != 0.0 || *(float *)(this + 220) != 0.0 )
    {
      v4 = sqrt(
             *(float *)(this + 212) * *(float *)(this + 212)
           + *(float *)(this + 216) * *(float *)(this + 216)
           + *(float *)(this + 220) * *(float *)(this + 220));
      *(float *)(this + 212) = 1.0 / v4 * *(float *)(this + 212);
      *(float *)(this + 216) = 1.0 / v4 * *(float *)(this + 216);
      *(float *)(this + 220) = 1.0 / v4 * *(float *)(this + 220);
    }
    v5 = *(float **)(this + 300);
    if ( v5 )
    {
      v6 = v5[49] - *(float *)(this + 196);
      v7 = v5[50] - *(float *)(this + 200);
      v8 = v5[51] - *(float *)(this + 204);
      *(float *)(this + 108) = sqrt(v8 * v8 + v7 * v7 + v6 * v6);
    }
    if ( *(float *)(this + 220) == 0.0 )
    {
      *(_DWORD *)(this + 260) = 1070141403;
    }
    else
    {
      v9 = atan2(*(float *)(this + 212) / *(float *)(this + 220), 1.0);
      *(float *)(this + 260) = v9;
      if ( *(float *)(this + 220) > 0.0 )
        *(float *)(this + 260) = v9 + 3.1415927;
    }
    result = *(_DWORD *)(this + 296);
    if ( result )
    {
      result = *(_DWORD *)(result + 296);
      if ( result )
      {
        v10 = result;
        v23 = 0;
        v11 = 1;
        v12 = (float *)(this + 264);
        while ( 1 )
        {
          v13 = *(float *)(v10 + 196) - *(float *)(this + 196);
          v14 = *(float *)(v10 + 204) - *(float *)(this + 204);
          v15 = sqrt(*(float *)(this + 212) * *(float *)(this + 212) + *(float *)(this + 220) * *(float *)(this + 220))
              * sqrt(v14 * v14 + v13 * v13);
          if ( v15 == 0.0 )
            v16 = 1.0;
          else
            v16 = (v13 * *(float *)(this + 212) + v14 * *(float *)(this + 220)) / v15;
          if ( v16 >= 1.0 || v23 )
          {
            v23 = 1;
            *v12 = 0.0;
            if ( v11 <= 0 )
              goto LABEL_29;
            v17 = 0.0;
            v18 = v11;
            v19 = 1.0;
            do
            {
              --v18;
              v17 = v17 + 0.024110001 / v19;
              v19 = v19 + v19;
            }
            while ( v18 );
          }
          else
          {
            v24 = v16;
            v17 = acos(v24);
          }
          *v12 = v17;
          if ( *v12 < 0.024110001 )
          {
LABEL_29:
            v23 = 1;
            *v12 = 0.0;
            if ( v11 > 0 )
            {
              v20 = 0.0;
              v21 = v11;
              v22 = 1.0;
              do
              {
                --v21;
                v20 = v20 + 0.024110001 / v22;
                v22 = v22 + v22;
              }
              while ( v21 );
              *v12 = v20;
            }
          }
          result = *(_DWORD *)(v10 + 296);
          if ( result )
          {
            ++v12;
            ++v11;
            v10 = *(_DWORD *)(v10 + 296);
            if ( v11 - 1 < 5 )
              continue;
          }
          return result;
        }
      }
    }
  }
  return result;
}

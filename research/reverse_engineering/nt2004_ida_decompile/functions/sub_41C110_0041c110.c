char __thiscall sub_41C110(
        _DWORD *this,
        int a2,
        int a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10)
{
  char result; // al
  int v12; // edi
  int v13; // edx
  int v14; // eax
  int v15; // eax
  double v16; // st7
  double v17; // st6
  double v18; // rt0
  double v19; // st6
  long double v20; // st7
  long double v21; // st6
  long double v22; // st5
  long double v23; // rt2
  float v24; // [esp+8h] [ebp-Ch]
  float v25; // [esp+Ch] [ebp-8h]
  float v26; // [esp+10h] [ebp-4h]
  int v27; // [esp+18h] [ebp+4h]
  float v28; // [esp+20h] [ebp+Ch]
  float v29; // [esp+24h] [ebp+10h]
  float v30; // [esp+28h] [ebp+14h]
  float v31; // [esp+2Ch] [ebp+18h]
  float v32; // [esp+38h] [ebp+24h]

  result = 0;
  if ( *this )
  {
    if ( this[2] )
    {
      v12 = this[3];
      if ( v12 )
      {
        if ( this[4] )
        {
          if ( a2 )
          {
            v13 = *(_DWORD *)(a2 + 28);
            v14 = *(_DWORD *)(a2 + 32);
            if ( v13 >= 0 )
            {
              if ( v13 > *(_DWORD *)(v12 + 28) )
                v13 = *(_DWORD *)(v12 + 28);
            }
            else
            {
              v13 = 0;
            }
            if ( v14 >= 0 )
            {
              if ( v14 > *(_DWORD *)(v12 + 32) )
                v14 = *(_DWORD *)(v12 + 32);
            }
            else
            {
              v14 = 0;
            }
            sub_59FDC0(0, 0, v12, 0, 0, v13, v14, -2, 0);
          }
          v15 = *(_DWORD *)(*this + 16);
          v16 = (double)*(int *)(v15 + 28);
          v24 = a4 * v16;
          v17 = (double)*(int *)(v15 + 32);
          v28 = a5 * v17;
          v18 = v17;
          v19 = v16 * a6;
          v30 = v24;
          v25 = v28;
          *(float *)&v27 = v19;
          v20 = v18 * a7;
          v21 = a10 * 0.01745433;
          v29 = v20 + v28;
          v32 = *(float *)&v27 + v24;
          v31 = v29;
          v26 = v32;
          if ( v21 != 0.0 )
          {
            v30 = cos(v21 + 1.5707964) * *(float *)&v27 + v24;
            v29 = sin(v21 + 1.5707964) * v20 + v28;
            v22 = atan2(v20, *(float *)&v27);
            v23 = sqrt(v20 * v20 + *(float *)&v27 * *(float *)&v27);
            v32 = cos(v22 + v21) * v23 + v24;
            v31 = sin(v22 + v21) * v23 + v28;
            v26 = cos(v21) * *(float *)&v27 + v24;
            v25 = sin(v21) * v20 + v28;
          }
          sub_5A16E0(this[4], 0, v24, v28, 1.0, 0.0, 0.0, a3);
          sub_5A16E0(this[4], 1, v30, v29, 1.0, 0.0, a9, a3);
          sub_5A16E0(this[4], 2, v32, v31, 1.0, a8, a9, a3);
          sub_5A16E0(this[4], 3, v26, v25, 1.0, a8, 0.0, a3);
          sub_5A1870(*(_DWORD *)(*this + 16));
          return 1;
        }
      }
    }
  }
  return result;
}

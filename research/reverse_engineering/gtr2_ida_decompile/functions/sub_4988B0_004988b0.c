int __thiscall sub_4988B0(int this)
{
  int result; // eax
  int v3; // ecx
  int v4; // ecx
  char v5; // al
  double v6; // st7
  float v7; // [esp+0h] [ebp-38h]
  float v8; // [esp+8h] [ebp-30h]
  float v9; // [esp+10h] [ebp-28h] BYREF
  float v10; // [esp+14h] [ebp-24h] BYREF
  float v11; // [esp+18h] [ebp-20h] BYREF
  float v12; // [esp+1Ch] [ebp-1Ch]
  float v13; // [esp+20h] [ebp-18h] BYREF
  float v14; // [esp+24h] [ebp-14h] BYREF
  float v15; // [esp+28h] [ebp-10h] BYREF
  int v16; // [esp+2Ch] [ebp-Ch] BYREF
  int v17; // [esp+30h] [ebp-8h] BYREF
  int v18; // [esp+34h] [ebp-4h]

  result = *(_DWORD *)(this + 268);
  if ( result )
  {
    v3 = *(_DWORD *)(this + 48);
    v15 = 0.0;
    v10 = 0.0;
    v11 = 0.0;
    v9 = 0.0;
    v14 = 0.0;
    v13 = 0.0;
    sub_4DE460(v3);
    sub_4DE540(&v17, &v16);
    v4 = *(_DWORD *)(this + 292);
    v18 = v17 - *(_DWORD *)(this + 288);
    LODWORD(v12) = v16 - v4;
    sub_5E5510(&v15, &v10, &v11, &v9, &v14, &v13);
    v9 = flt_B6E080;
    v5 = *(_BYTE *)(this + 273);
    v10 = flt_759F2C;
    v11 = flt_B6E07C;
    if ( v5 )
    {
      if ( *(_BYTE *)(this + 272) )
      {
        v8 = -((double)SLODWORD(v12) * 0.0074999998);
        v7 = (double)v18 * 0.0074999998;
        sub_5DB180(v7, 0.0, v8);
      }
      else
      {
        v6 = (double)SLODWORD(v12);
        v12 = *(float *)(this + 280);
        *(float *)(this + 276) = *(float *)(this + 276) - v6 * 0.025;
        if ( *(float *)(this + 284) <= (double)*(float *)(this + 276) )
        {
          if ( *(float *)(this + 276) > (double)v12 )
            *(float *)(this + 276) = v12;
        }
        else
        {
          *(float *)(this + 276) = *(float *)(this + 284);
        }
      }
    }
    else if ( *(_BYTE *)(this + 272) )
    {
      v9 = v9 - (double)SLODWORD(v12) * 0.0055;
      sub_401760(&v9, -1.5707964, 1.5707964);
    }
    if ( v9 >= -0.81681406 )
    {
      if ( v9 > -0.031415928 )
        v9 = -0.031415928;
    }
    else
    {
      v9 = -0.81681406;
    }
    v10 = sin(v9) * *(float *)(this + 276);
    v11 = cos(v9) * *(float *)(this + 276);
    sub_5E51D0(v15, v10, v11, v9, v14, v13);
    flt_759F2C = v10;
    result = v16;
    flt_B6E07C = v11;
    flt_B6E080 = v9;
    *(_DWORD *)(this + 292) = v16;
  }
  return result;
}

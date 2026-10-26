int __thiscall sub_51A720(float *this, int a2)
{
  float *v2; // edi
  _DWORD *v3; // ecx
  int result; // eax
  int i; // esi
  double v6; // st7
  double v7; // st7
  double v8; // [esp+10h] [ebp-10h]
  double v9; // [esp+18h] [ebp-8h]

  v2 = this + 4931;
  v3 = this + 4931;
  *v3 = 2139095039;
  v3[1] = 2139095039;
  v3[2] = 2139095039;
  v3[3] = 2139095039;
  v3[4] = 2139095039;
  result = *(_DWORD *)dword_766B6C;
  if ( *(int *)dword_766B6C > 0 && *(int *)dword_766B6C <= 2 )
  {
    sub_590140(2, 0);
    for ( i = 0; i < 5; ++i )
    {
      v6 = 1.0;
      switch ( i )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
          v6 = 2.099999904632568;
          break;
        default:
          break;
      }
      v9 = v6 * *(double *)(a2 + 5000);
      v8 = v6 * *(double *)(a2 + 5008);
      v7 = sub_4D1B00(&dword_7D3C50) * v8 + v9;
      if ( dword_75CBB0 == 7 && *(_DWORD *)dword_766B6C == 2 )
        v7 = v7 / flt_7D74C4;
      if ( v7 <= 3.402823466385289e38 )
        *v2 = v7;
      else
        *v2 = 3.4028235e38;
      ++v2;
    }
    return sub_590140(1, 0);
  }
  return result;
}

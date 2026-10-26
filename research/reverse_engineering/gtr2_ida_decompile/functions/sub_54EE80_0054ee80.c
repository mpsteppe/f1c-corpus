int __thiscall sub_54EE80(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v2 = this[208];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_4:
    v3 = -2;
  }
  else
  {
    while ( a2 != this[2 * v3] )
    {
      if ( ++v3 >= v2 )
        goto LABEL_4;
    }
  }
  v4 = v3 - 1;
  if ( v3 < 4 )
  {
LABEL_20:
    if ( v4 < 0 )
      return -2;
    while ( 1 )
    {
      v10 = 5654 * this[2 * v4];
      if ( byte_925105[v10 * 4] )
      {
        if ( dword_923E84[v10] != 2 || fabs(*(float *)&dword_925CCC[5654 * this[2 * v4]] - dbl_FB1D18) < 3.0 )
          break;
      }
      if ( --v4 < 0 )
        return -2;
    }
  }
  else
  {
    v5 = &this[2 * v4 - 4];
    while ( 1 )
    {
      v6 = 5654 * v5[4];
      if ( byte_925105[v6 * 4] )
      {
        if ( dword_923E84[v6] != 2 || fabs(*(float *)&dword_925CCC[5654 * v5[4]] - dbl_FB1D18) < 3.0 )
          break;
      }
      v7 = 5654 * v5[2];
      if ( byte_925105[v7 * 4]
        && (dword_923E84[v7] != 2 || fabs(*(float *)&dword_925CCC[5654 * v5[2]] - dbl_FB1D18) < 3.0) )
      {
        --v4;
        break;
      }
      v8 = 5654 * *v5;
      if ( byte_925105[v8 * 4]
        && (dword_923E84[v8] != 2 || fabs(*(float *)&dword_925CCC[5654 * *v5] - dbl_FB1D18) < 3.0) )
      {
        v4 -= 2;
        break;
      }
      v9 = 5654 * *(v5 - 2);
      if ( byte_925105[v9 * 4]
        && (dword_923E84[v9] != 2 || fabs(*(float *)&dword_925CCC[5654 * *(v5 - 2)] - dbl_FB1D18) < 3.0) )
      {
        v4 -= 3;
        break;
      }
      v4 -= 4;
      v5 -= 8;
      if ( v4 < 3 )
        goto LABEL_20;
    }
  }
  if ( v4 < 0 )
    return -2;
  return this[2 * v4];
}

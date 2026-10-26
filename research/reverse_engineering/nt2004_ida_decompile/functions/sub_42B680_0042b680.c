int __thiscall sub_42B680(int this)
{
  int v2; // edi
  char v3; // dl
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  bool v7; // zf
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  float *v13; // ecx
  double v14; // st7
  int result; // eax
  double v16; // st7
  signed int v17; // ebp
  float *v18; // edx
  int v19; // ecx
  int v20; // edi
  double v21; // st7
  double v22; // st7
  int v23; // [esp+0h] [ebp-1Ch]
  int v24; // [esp+0h] [ebp-1Ch]
  int v25; // [esp+4h] [ebp-18h]
  int v26; // [esp+4h] [ebp-18h]
  char v27; // [esp+1Bh] [ebp-1h]

  v2 = -1;
  if ( *(float *)(this + 23852) - *(float *)(this + 23784) < 0.5 && *(float *)(this + 23780) > 0.75
    || *(float *)(this + 23764) > 50.0 )
  {
    v27 = 1;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v27 = 0;
  }
  v4 = *(_DWORD *)(this + 24024);
  if ( v4 == 8 )
  {
    v5 = *(_DWORD *)(this + 24020);
    if ( *(_DWORD *)(this + 23752) )
    {
      if ( v5 != dword_629108 && *(_DWORD *)(this + 24076) == -1 )
        v2 = dword_629108;
    }
    else if ( v5 != dword_62910C && *(_DWORD *)(this + 24080) == -1 )
    {
      v2 = dword_62910C;
    }
    goto LABEL_100;
  }
  if ( *(float *)(this + 24712) != 0.0 || dword_75CBB4 == 3 || dword_75CBB4 == 6 || v4 == 6 || v4 == 7 )
    goto LABEL_100;
  v6 = *(_DWORD *)(this + 24020);
  switch ( v6 )
  {
    case 11:
      if ( *(_BYTE *)(this + 56) && *(_DWORD *)(this + 23804) )
        v2 = 8;
      if ( (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
         * 0.25 >= *(float *)(this + 23928) )
      {
        v8 = *(_DWORD *)(this + 23800);
        if ( !v8 && *(_DWORD *)(this + 23804) )
          goto LABEL_37;
        v9 = *(_DWORD *)(this + 24080);
        if ( v9 != -1 && *(_DWORD *)(this + 24076) == -1 )
        {
          v2 = 7;
          goto LABEL_38;
        }
        if ( v8 && !*(_DWORD *)(this + 23804) )
        {
          v2 = 7;
          goto LABEL_38;
        }
        if ( v9 != -1 )
          goto LABEL_38;
        v7 = *(_DWORD *)(this + 24076) == -1;
      }
      else
      {
        if ( !*(_DWORD *)(this + 23804) )
          goto LABEL_38;
        v7 = *(_DWORD *)(this + 23800) == 0;
      }
      if ( !v7 )
LABEL_37:
        v2 = 8;
LABEL_38:
      if ( *(_DWORD *)(this + 24076) != -1
        && (*(_DWORD *)(this + 23804) || fabs(*(float *)(this + 23728) - (sub_529A00(1) + 3.5)) > 1.0) )
      {
        v2 = 8;
      }
      break;
    case 7:
      if ( *(_BYTE *)(this + 56) && *(_DWORD *)(this + 23804) )
        v2 = 8;
      if ( *(_DWORD *)(this + 24288) == -1
        && !*(_DWORD *)(this + 24244)
        && *(_DWORD *)(this + 23804)
        && *(_DWORD *)(this + 23800)
        && *(float *)(this + 24696) < (double)*(float *)(this + 23852) )
      {
        v2 = 11;
      }
      if ( *(int *)(this + 24076) > -1 && *(_DWORD *)(this + 23804) )
        v2 = 8;
      if ( (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
         * 0.25 < *(float *)(this + 23928)
        && *(_DWORD *)(this + 23804) )
      {
        v2 = 8;
      }
      break;
    case 6:
      if ( v3 )
      {
        if ( *(_DWORD *)(this + 23804) )
          v2 = 7;
      }
      else
      {
        v10 = sub_42B320(this, COERCE_FLOAT(1));
        if ( v10 == 8 || v10 == 9 )
          sub_42C0F0(9);
      }
      break;
    case 8:
      if ( *(_DWORD *)(this + 24288) == -1
        && !*(_DWORD *)(this + 24244)
        && (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
         * 0.25 > *(float *)(this + 23928)
        && !*(_BYTE *)(this + 56)
        && *(_DWORD *)(this + 23804)
        && *(_DWORD *)(this + 23800)
        && *(float *)(this + 24696) < (double)*(float *)(this + 23852) )
      {
        v2 = 11;
      }
      if ( *(int *)(this + 24080) > -1 && *(_DWORD *)(this + 23800) )
        v2 = 7;
      break;
    case 9:
      if ( v3 )
      {
        if ( *(_DWORD *)(this + 23800) )
          v2 = 8;
      }
      else
      {
        v11 = sub_42B320(this, COERCE_FLOAT(1));
        if ( v11 == 7 || v11 == 6 )
          sub_42C0F0(6);
      }
      break;
    case 13:
      if ( *(float *)(this + 24728) < (double)*(float *)(this + 23852) )
      {
        if ( *(_DWORD *)(this + 23800) )
        {
          if ( *(_DWORD *)(this + 23804) )
            v2 = 11;
          if ( !*(_DWORD *)(this + 23804) )
            v2 = 7;
        }
        else
        {
          v2 = 8;
        }
      }
      break;
    default:
      if ( v6 == 10 && *(float *)(this + 24696) < (double)*(float *)(this + 23852) )
      {
        if ( *(_BYTE *)(this + 56) )
        {
          if ( !*(_DWORD *)(this + 23804) )
            break;
          v2 = 8;
        }
        if ( *(_DWORD *)(this + 23804) )
          v2 = 11;
      }
      break;
  }
LABEL_100:
  *(_DWORD *)(this + 24752) = v2;
  if ( v2 != -1 )
    sub_42C150(v2, 1000593162, COERCE_FLOAT(1));
  sub_421CA0(this);
  v12 = *(_DWORD *)(this + 24020);
  if ( v12 == 3 )
  {
    if ( *(_BYTE *)(this + 24208) )
    {
      v13 = *(float **)(this + 23432);
      v14 = *(float *)(this + 17636) * v13[55] + *(float *)(this + 17632) * v13[54] + v13[53] * *(float *)(this + 17628) >= flt_628F78
          ? *(float *)(this + 17636) * v13[55] + *(float *)(this + 17632) * v13[54] + *(float *)(this + 17628) * v13[53]
          : flt_628F78;
      *(float *)(this + 23760) = v14;
      if ( v14 < *(float *)(this + 24720) )
      {
        *(float *)&v25 = *(float *)(this + 23728) + 3.0;
        *(float *)&v23 = *(float *)(this + 23728) - 3.0;
        sub_529AC0(this + 23760, 0.25, v23, v25);
      }
    }
    sub_421CA0(this);
  }
  else if ( v12 < 2 )
  {
    sub_421EF0(this);
  }
  else
  {
    if ( v12 == 2 )
    {
      *(_BYTE *)(this + 32) = 1;
      return sub_421B60(this);
    }
    if ( v12 == 4 )
    {
      v16 = *(float *)(this + 23764);
      *(_BYTE *)(this + 32) = 1;
      *(_DWORD *)(this + 23732) = 0;
      *(_DWORD *)(this + 23748) = 1065353216;
      *(_DWORD *)(this + 23740) = 0;
      if ( v16 < 0.2 )
        sub_421B60(this);
    }
  }
  v17 = 0;
  if ( (int)NumOfElements > 0 )
  {
    v18 = (float *)(this + 21924);
    do
    {
      if ( *v18 > 0.0 )
        *v18 = *v18 - *(float *)(this + 23856);
      v19 = 0;
      v20 = this + 21256;
      do
      {
        if ( *(_DWORD *)v20 && *(_DWORD *)(*(_DWORD *)v20 + 25248) == v17 )
        {
          if ( *(_DWORD *)(this + 24068) == v19
            || *(_DWORD *)(this + 24072) == v19
            || *(_DWORD *)(this + 24076) == v19
            || *(_DWORD *)(this + 24080) == v19
            || *(_DWORD *)(this + 24084) == v19
            || *(_DWORD *)(this + 24088) == v19 )
          {
            v21 = *(float *)(this + 23856) + *(v18 - 6);
          }
          else
          {
            v21 = *(v18 - 6) - 1.0;
            if ( v21 < 0.0 )
              v21 = 0.0;
          }
          *(v18 - 6) = v21;
        }
        ++v19;
        v20 += 128;
      }
      while ( v19 < 5 );
      ++v17;
      v18 += 8;
    }
    while ( v17 < (int)NumOfElements );
  }
  if ( *(_BYTE *)(this + 32) )
  {
    if ( v27 )
    {
      *(_BYTE *)(this + 32) = 0;
    }
    else
    {
      *(float *)&v26 = *(float *)(this + 23728) + 3.0;
      *(float *)&v24 = *(float *)(this + 23728) - 3.0;
      sub_529AC0(this + 23764, 0.25, v24, v26);
    }
  }
  v22 = *(float *)(this + 23796);
  *(_DWORD *)(this + 23800) = *(float *)(this + 23792) < (double)*(float *)(this + 23852);
  if ( v22 >= *(float *)(this + 23852) )
  {
    result = 0;
    *(_DWORD *)(this + 23804) = 0;
  }
  else
  {
    result = 1;
    *(_DWORD *)(this + 23804) = 1;
  }
  *(_BYTE *)(this + 16) = 0;
  return result;
}

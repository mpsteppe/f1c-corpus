int __thiscall sub_4F78B0(int *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ecx
  int *v5; // eax
  int *v6; // edi
  int v7; // ecx
  int v8; // edi
  int v9; // ebx
  double v10; // st7
  int *v11; // eax
  int *v12; // edi
  long double v13; // st7
  long double v14; // st7
  int result; // eax
  int v16; // edi
  int v17; // ebx
  float v18; // [esp+10h] [ebp-38h]
  float v19; // [esp+14h] [ebp-34h]
  int v20; // [esp+18h] [ebp-30h] BYREF
  float v21; // [esp+1Ch] [ebp-2Ch]
  float v22; // [esp+20h] [ebp-28h]
  int v23[3]; // [esp+24h] [ebp-24h] BYREF
  float v24[5]; // [esp+30h] [ebp-18h] BYREF
  float v25; // [esp+44h] [ebp-4h]

  sub_4F0F50((char *)flt_7D6BD0);
  if ( !byte_75CBB8 || sub_4D9AE0(&dword_7D5DAC) )
  {
    if ( flt_7DAB00 > 0.0 )
    {
      if ( this[7] )
      {
        v5 = (int *)sub_40C460(&dword_6291CC);
        v6 = v5;
        if ( v5 )
        {
          sub_459BC0(v5, &v20, 0);
          sub_459BE0(v6, v24);
          v7 = this[7];
          v25 = v24[2] * 0.25;
          *(float *)&v20 = *(float *)&v20 + v24[0] * 0.25;
          v21 = v21 + v24[1] * 0.25;
          v22 = v22 + v25;
          sub_4F3F90(v7, (float *)&v20, flt_7DAB00);
        }
      }
    }
    v8 = 0;
    if ( this[4] > 0 )
    {
      v9 = 0;
      do
      {
        sub_4F5610(v9 + this[5]);
        ++v8;
        v9 += 116;
      }
      while ( v8 < this[4] );
    }
  }
  else
  {
    v2 = 0;
    if ( this[4] > 0 )
    {
      v3 = 0;
      do
      {
        v4 = this[5] + v3;
        if ( *(_DWORD *)(v4 + 4) <= 5u )
          sub_4F5610(v4);
        ++v2;
        v3 += 116;
      }
      while ( v2 < this[4] );
    }
  }
  if ( dword_7D5DA4 == 2 )
  {
    if ( sub_4DA080(&dword_7D5DAC) == 5 )
    {
      v18 = 0.0;
      goto LABEL_22;
    }
    v10 = sub_4D9E30(&dword_7D5DAC);
  }
  else
  {
    v10 = dbl_7DA9C8;
  }
  v18 = v10;
LABEL_22:
  v11 = (int *)sub_40C460(&dword_6291CC);
  v12 = v11;
  if ( v11 )
  {
    sub_459BC0(v11, v23, 0);
    sub_459BE0(v12, &v20);
    v13 = sqrt(v21 * v21 + v22 * v22 + *(float *)&v20 * *(float *)&v20);
  }
  else
  {
    v13 = 0.0;
    memset(v23, 0, sizeof(v23));
  }
  v14 = 430.0 - v13 * 4.0;
  if ( v14 >= 0.0 )
    v19 = v14;
  else
    v19 = 0.0;
  result = *this;
  v16 = 0;
  if ( *this > 0 )
  {
    v17 = 0;
    do
    {
      sub_4F1720(v17 + this[1], v18, (int)v23, v19);
      result = *this;
      ++v16;
      v17 += 60;
    }
    while ( v16 < *this );
  }
  return result;
}

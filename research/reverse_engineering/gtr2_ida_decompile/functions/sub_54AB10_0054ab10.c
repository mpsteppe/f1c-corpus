float *__thiscall sub_54AB10(float **this)
{
  float *result; // eax
  int v3; // ebx
  int v4; // edi
  float *v5; // ecx
  float *v6; // edi
  int *v7; // eax
  int v8; // ecx
  float v9; // edx
  float v10; // eax
  int *v11; // eax
  float v12; // ecx
  float v13; // edx
  int v14; // edi
  int v15; // ebx
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  long double v20; // st7
  int v21; // edi
  int v22; // ebx
  float v23; // [esp+0h] [ebp-3Ch]
  float v24; // [esp+10h] [ebp-2Ch]
  float v25; // [esp+14h] [ebp-28h]
  int v26; // [esp+18h] [ebp-24h] BYREF
  float v27; // [esp+1Ch] [ebp-20h]
  float v28; // [esp+20h] [ebp-1Ch]
  int v29[3]; // [esp+24h] [ebp-18h] BYREF
  float v30[3]; // [esp+30h] [ebp-Ch] BYREF

  sub_542D90((char *)off_16C99A4);
  if ( !byte_B6413C || sub_521050(&dword_BE120C) )
  {
    if ( sub_592960(&dword_FB1EF8) > 0.0 && this[7] )
    {
      result = (float *)sub_40DCE0(&dword_91BF20);
      v6 = result;
      if ( !result )
        return result;
      v7 = (int *)sub_4012D0(result + 9, (float *)v29, 0.25);
      v8 = *v7;
      v9 = *((float *)v7 + 1);
      v10 = *((float *)v7 + 2);
      v26 = v8;
      v27 = v9;
      v28 = v10;
      v11 = (int *)sub_401290((float *)&v26, v6 + 3, v30);
      v12 = *((float *)v11 + 1);
      v26 = *v11;
      v13 = *((float *)v11 + 2);
      v27 = v12;
      v28 = v13;
      v23 = sub_592960(&dword_FB1EF8);
      sub_544680((int)this[7], (float *)&v26, v23);
    }
    result = this[4];
    v14 = 0;
    if ( (int)result > 0 )
    {
      v15 = 0;
      do
      {
        sub_54AA90(&this[5][v15]);
        result = this[4];
        ++v14;
        v15 += 29;
      }
      while ( v14 < (int)result );
    }
  }
  else
  {
    result = this[4];
    v3 = 0;
    if ( (int)result > 0 )
    {
      v4 = 0;
      do
      {
        v5 = &this[5][v4];
        switch ( *((_DWORD *)v5 + 1) )
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x14:
            sub_54AA90(v5);
            break;
          default:
            break;
        }
        result = this[4];
        ++v3;
        v4 += 29;
      }
      while ( v3 < (int)result );
    }
  }
  if ( byte_B71968 == 1 )
  {
    if ( dword_BE1204 == 2 )
    {
      if ( sub_5210D0(&dword_BE120C) == 5 )
      {
        v24 = 0.0;
        goto LABEL_23;
      }
      v16 = sub_5210C0(&dword_BE120C);
    }
    else
    {
      v16 = dbl_FB1D10;
    }
    v24 = v16;
LABEL_23:
    result = (float *)sub_40DCE0(&dword_91BF20);
    if ( result )
    {
      *(float *)&v26 = -result[3];
      v17 = result[4];
      v29[0] = v26;
      v27 = -v17;
      v18 = result[5];
      *(float *)&v29[1] = v27;
      v28 = -v18;
      v19 = result[11];
      *(float *)&v29[2] = v28;
      v20 = 430.0 - sqrt(result[9] * result[9] + result[10] * result[10] + v19 * v19) * 4.0;
      if ( v20 >= 0.0 )
        v25 = v20;
      else
        v25 = 0.0;
      result = *this;
      v21 = 0;
      if ( (int)*this > 0 )
      {
        v22 = 0;
        do
        {
          sub_547120(&this[1][v22], v24, (float *)v29, v25);
          result = *this;
          ++v21;
          v22 += 15;
        }
        while ( v21 < (int)*this );
      }
    }
  }
  return result;
}

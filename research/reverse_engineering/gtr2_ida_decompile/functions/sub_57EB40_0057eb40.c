void __thiscall sub_57EB40(float *this, float a2)
{
  float *v3; // eax
  bool v4; // zf
  int v5; // ecx
  int v6; // edx
  int v7; // ebp
  int v8; // ebx
  char *v9; // edi
  int v10; // edx
  int i; // eax
  int j; // eax
  int v13; // edi
  int m; // edi
  double v15; // st7
  double v16; // st7
  unsigned int v17; // eax
  long double v18; // st7
  long double v19; // st6
  double v20; // st6
  double v21; // st5
  int v22; // eax
  float v23; // [esp+20h] [ebp-3Ch]
  float v24; // [esp+24h] [ebp-38h]
  float k; // [esp+28h] [ebp-34h]
  float v26; // [esp+28h] [ebp-34h]
  float v27; // [esp+2Ch] [ebp-30h]
  _DWORD v28[6]; // [esp+30h] [ebp-2Ch]
  int v29; // [esp+48h] [ebp-14h]
  float v30; // [esp+4Ch] [ebp-10h]
  float v31; // [esp+50h] [ebp-Ch]
  int v32; // [esp+60h] [ebp+4h]
  float v33; // [esp+60h] [ebp+4h]

  if ( LOBYTE(a2) )
  {
    v3 = this + 7;
    v4 = *(_DWORD *)(*(_DWORD *)this + 5744) == 1;
    v29 = *((int *)this + 7);
    v5 = *((_DWORD *)this + 8);
    v6 = *((_DWORD *)this + 9);
    if ( v4 )
      v29 = *((int *)this + 4811);
    else
      *(float *)&v29 = 0.0;
    *v3 = *(float *)&v29;
    *((_DWORD *)this + 8) = v5;
    v7 = 0;
    *((_DWORD *)this + 9) = v6;
    v8 = 0;
    v9 = (char *)(this + 4096);
    v32 = 4;
    do
    {
      if ( *(_DWORD *)v9 )
      {
        v10 = *(_DWORD *)(*(_DWORD *)v9 + 84);
        for ( i = 0; i < v7; ++i )
        {
          if ( v28[i] == *(_DWORD *)(v10 + 48) )
            break;
        }
        if ( i == v7 )
          v28[v7++] = *(_DWORD *)(v10 + 48);
        for ( j = 0; j < v8; ++j )
        {
          if ( *(&v29 + j) == *(_DWORD *)(v10 + 44) )
            break;
        }
        if ( j == v8 )
          *(&v29 + v8++) = *(_DWORD *)(v10 + 44);
      }
      v9 += 252;
      --v32;
    }
    while ( v32 );
    v13 = 0;
    for ( k = sqrt(this[3999] * this[3999] + this[4000] * this[4000] + this[4001] * this[4001]); v13 < v7; ++v13 )
      sub_57E220((int)this, v28[v13]);
    for ( m = 0; m < v8; ++m )
      sub_57E710((int)this, *(&v29 + m), k);
    sub_58C900(this[3982]);
    *(float *)&v29 = this[4352] - this[3999];
    v15 = this[4353];
    v28[0] = v29;
    v30 = v15 - this[4000];
    v16 = this[4354];
    *(float *)&v28[1] = v30;
    v31 = v16 - this[4001];
    *(float *)&v28[2] = v31;
    if ( (sqrt(v31 * v31 + v30 * v30 + *(float *)&v29 * *(float *)&v29) - 2.0) * 0.010204081 > 0.0 )
      sub_58C630(14);
    if ( sub_592960(&dword_FB1EF8) > 0.0 && !sub_577A80((float *)(*(_DWORD *)this + 16)) )
      sub_58C630(17);
    v17 = *((_DWORD *)this + 3701);
    if ( v17 < 2 )
    {
      v33 = this[4035];
    }
    else if ( *((_BYTE *)this + 5745) )
    {
      v33 = 0.75;
    }
    else
    {
      v33 = 0.0;
    }
    if ( v17 <= 2 )
    {
      v18 = fabs(this[4049]);
      v23 = fabs(this[4112]);
      v24 = fabs(this[4175]);
      v19 = fabs(this[4238]);
      v26 = v19;
      v27 = v19 + v24 + v23 + v18;
      if ( v18 <= v23 )
        v20 = v23;
      else
        v20 = v18;
      if ( v24 <= (double)v26 )
        v21 = v26;
      else
        v21 = v24;
      if ( v20 <= v21 )
      {
        if ( v24 <= (double)v26 )
          v23 = v26;
        else
          v23 = v24;
      }
      else if ( v18 > v23 )
      {
        v23 = v18;
      }
      if ( v23 <= 0.0 )
        v33 = 0.0;
      else
        v33 = v27 / v23 * 0.25 * v33;
    }
    sub_58E480(v23, v33);
  }
  if ( this[723] <= 0.0 )
  {
    *((_BYTE *)this + 2112) = 0;
    *((_BYTE *)this + 317) = 1;
  }
  else
  {
    sub_58C630(56);
  }
  v22 = *((_DWORD *)this + 3701);
  if ( !v22 )
  {
    if ( dbl_B682C8 <= dbl_B682E0 )
      return;
    goto LABEL_58;
  }
  if ( v22 == 1 && this[4312] > (double)this[4315] )
LABEL_58:
    sub_58C630(52);
}

int __thiscall sub_40B4A0(int this, int a2)
{
  const char *v3; // eax
  int v4; // ecx
  int v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st5
  float v11; // [esp+14h] [ebp-A0h]
  float v12; // [esp+18h] [ebp-9Ch]
  float v13; // [esp+1Ch] [ebp-98h]
  float v14; // [esp+24h] [ebp-90h]
  float v15; // [esp+24h] [ebp-90h]
  float v16; // [esp+28h] [ebp-8Ch] BYREF
  float v17; // [esp+2Ch] [ebp-88h]
  float v18; // [esp+30h] [ebp-84h]
  float v19; // [esp+34h] [ebp-80h] BYREF
  float v20; // [esp+38h] [ebp-7Ch]
  float v21; // [esp+3Ch] [ebp-78h]
  int v22; // [esp+40h] [ebp-74h] BYREF
  int v23; // [esp+44h] [ebp-70h]
  float v24; // [esp+48h] [ebp-6Ch]
  int v25; // [esp+4Ch] [ebp-68h]
  float v26; // [esp+50h] [ebp-64h] BYREF
  float v27; // [esp+54h] [ebp-60h]
  float v28; // [esp+58h] [ebp-5Ch]
  float v29; // [esp+5Ch] [ebp-58h]
  float v30; // [esp+60h] [ebp-54h]
  float v31; // [esp+64h] [ebp-50h]
  float v32; // [esp+68h] [ebp-4Ch]
  float v33; // [esp+6Ch] [ebp-48h]
  float v34; // [esp+70h] [ebp-44h]
  float v35; // [esp+74h] [ebp-40h] BYREF
  float v36; // [esp+78h] [ebp-3Ch]
  float v37; // [esp+7Ch] [ebp-38h]
  int v38; // [esp+80h] [ebp-34h] BYREF
  float v39; // [esp+84h] [ebp-30h] BYREF
  int v40; // [esp+88h] [ebp-2Ch] BYREF
  float v41; // [esp+8Ch] [ebp-28h] BYREF
  _BYTE v42[36]; // [esp+90h] [ebp-24h] BYREF

  sub_459BF0(&v39, &v41);
  sub_459C00(&v38, &v40);
  sub_459BC0(&v22, &v16);
  sub_459BE0(&v35);
  if ( *(_BYTE *)(this + 52)
    && *(_DWORD *)(this + 44)
    && (v3 = (const char *)sub_459BA0(*(_DWORD *)(this + 16)), !_strcmpi(v3, aDrivable)) )
  {
    sub_50C760(&v22, &v16);
    sub_579100(&v16, &v26);
    sub_579C10(3.1415927, (int)&v16);
  }
  else
  {
    *(_BYTE *)(this + 52) = 0;
  }
  if ( !*(_BYTE *)(this + 52) || dword_768948 )
  {
    sub_409650((float *)this);
    if ( !*(_BYTE *)(this + 52) )
      sub_579100(&v16, &v26);
    if ( *(float *)(this + 60) != 0.0 || *(float *)(this + 56) != 0.0 || *(float *)(this + 64) != 0.0 )
    {
      sub_579100(&v16, v42);
      if ( *(float *)(this + 60) != 0.0 )
        sub_579C10(*(float *)(this + 60), (int)&v16);
      if ( *(float *)(this + 56) != 0.0 )
        sub_579B50(*(float *)(this + 56), (int)&v16);
      if ( *(float *)(this + 64) != 0.0 )
        sub_579CD0(*(float *)(this + 64), (int)&v16);
    }
    if ( *(float *)(this + 88) != 0.0 )
    {
      v4 = *(_DWORD *)(this + 16);
      if ( v4 )
      {
        v5 = sub_459B90(v4);
        v6 = *(float *)(this + 88);
        if ( v5 == 2 )
        {
          v19 = v29 * v6 + v32 * 0.0 + v26 * 0.0;
          v20 = v30 * v6 + v27 * 0.0 + v33 * 0.0;
          v21 = v31 * v6 + v28 * 0.0 + v34 * 0.0;
        }
        else
        {
          v20 = *(float *)(this + 88);
          v19 = 0.0;
          v21 = 0.0;
          v7 = v20 * *(float *)(dword_75AAC4 + 1928)
             + *(float *)(dword_75AAC4 + 1932) * 0.0
             + *(float *)(dword_75AAC4 + 1924) * 0.0;
          v8 = v20 * *(float *)(dword_75AAC4 + 1940)
             + *(float *)(dword_75AAC4 + 1944) * 0.0
             + *(float *)(dword_75AAC4 + 1936) * 0.0;
          v9 = v20 * *(float *)(dword_75AAC4 + 1952)
             + *(float *)(dword_75AAC4 + 1956) * 0.0
             + *(float *)(dword_75AAC4 + 1948) * 0.0;
          v19 = v29 * v8 + v32 * v9 + v26 * v7;
          v20 = v33 * v9 + v30 * v8 + v27 * v7;
          v21 = v34 * v9 + v31 * v8 + v28 * v7;
        }
        sub_579930(&v19, &v16);
      }
    }
    if ( *(float *)(this + 80) != 0.0 )
      sub_579B50(*(float *)(this + 80), (int)&v16);
  }
  sub_409050((float *)&v22, &v16);
  sub_593AF0(0);
  sub_5934A0(v22, v23, v24, v16, v17, v18);
  v12 = v41 * 0.01745433;
  v11 = v39 * 0.01745433;
  sub_593820(v11, v12, 0);
  sub_593D20(v38, v40);
  v13 = sub_459C10(*(_DWORD *)(this + 16));
  sub_594050(v13);
  if ( *(_DWORD *)(this + 44) )
  {
    if ( sub_40A0D0(this) )
    {
      sub_50C760(&v22, &v16);
      sub_409050((float *)&v22, &v16);
      sub_579100(&v16, v42);
      sub_579C10(3.1415927, (int)&v16);
      sub_5934A0(v22, v23, v24, v16, v17, v18);
      sub_40BEE0(1);
    }
    else
    {
      sub_40BEE0(0);
    }
  }
  v14 = 0.0;
  if ( !byte_75CBB8 )
  {
    v25 = dword_768294;
    v14 = sqrt(v36 * v36 + v37 * v37 + v35 * v35) / (flt_768270 * 0.44704) * *(float *)&dword_768294;
    if ( v14 >= (double)flt_76829C )
    {
      if ( v14 > (double)*(float *)&v25 )
        v14 = *(float *)&v25;
    }
    else
    {
      v14 = flt_76829C;
    }
  }
  v15 = sub_459C20(*(_DWORD *)(this + 16)) + v14;
  return sub_592F40(LODWORD(v15));
}

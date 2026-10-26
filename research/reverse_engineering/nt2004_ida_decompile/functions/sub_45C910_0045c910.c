void __thiscall sub_45C910(float *this)
{
  long double v2; // st7
  long double v3; // st7
  int v4; // [esp+4h] [ebp-98h]
  float v5; // [esp+4h] [ebp-98h]
  float v6; // [esp+8h] [ebp-94h]
  int v7; // [esp+Ch] [ebp-90h] BYREF
  int v8; // [esp+10h] [ebp-8Ch] BYREF
  int v9; // [esp+14h] [ebp-88h] BYREF
  int v10; // [esp+18h] [ebp-84h] BYREF
  float v11; // [esp+1Ch] [ebp-80h] BYREF
  float v12; // [esp+20h] [ebp-7Ch]
  float v13; // [esp+28h] [ebp-74h]
  float v14; // [esp+2Ch] [ebp-70h]
  float v15; // [esp+3Ch] [ebp-60h]
  float v16; // [esp+40h] [ebp-5Ch]
  float v17; // [esp+48h] [ebp-54h]
  float v18; // [esp+4Ch] [ebp-50h]
  float v19; // [esp+5Ch] [ebp-40h]
  float v20; // [esp+60h] [ebp-3Ch]
  float v21; // [esp+68h] [ebp-34h]
  float v22; // [esp+6Ch] [ebp-30h]
  float v23; // [esp+7Ch] [ebp-20h]
  float v24; // [esp+80h] [ebp-1Ch]
  float v25; // [esp+88h] [ebp-14h]
  float v26; // [esp+8Ch] [ebp-10h]

  v4 = sub_45CE00();
  if ( v4 || this[300] != 0.0 )
  {
    v6 = sub_45C870((int)this) + 0.050000001;
    v5 = (double)v4 * 0.035;
    if ( this[299] != v6 )
    {
      v2 = v6 - this[299];
      if ( fabs(v2) > 0.001000000047497451 )
        this[299] = v2 * 0.40000001 + this[299];
      else
        this[299] = v6;
    }
    if ( this[300] != v5 )
    {
      v3 = v5 - this[300];
      if ( fabs(v3) > 0.001000000047497451 )
        this[300] = v3 * 0.40000001 + this[300];
      else
        this[300] = v5;
    }
    sub_5069A0(this[299], this[300]);
    sub_506AE0(0.5, 0.0, 1.0, 2);
    sub_506960(0);
    sub_506B50(&v9, &v10);
    sub_506B70(&v8, &v7, 0);
    v11 = (float)v8;
    v12 = (float)v7;
    v13 = v11;
    v14 = (float)(v10 + v7);
    v15 = v11;
    v16 = v14;
    v17 = (float)(v9 + v8);
    v18 = v14;
    v19 = v17;
    v20 = v14;
    v21 = v17;
    v22 = v12;
    v23 = v17;
    v24 = v12;
    v25 = v11;
    v26 = v12;
    sub_4AB2E0(&v11, 4, -6710887, dword_7E8CDC, 0);
  }
  else
  {
    this[299] = 0.0;
  }
}

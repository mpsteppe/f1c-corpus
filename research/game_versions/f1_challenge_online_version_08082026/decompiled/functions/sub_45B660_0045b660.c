void __thiscall sub_45B660(float *this)
{
  long double v2; // st7
  long double v3; // st7
  int v4; // esi
  int v5; // edi
  float v6; // [esp+4h] [ebp-18h]
  int v7; // [esp+8h] [ebp-14h]
  float v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h] BYREF
  int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h] BYREF

  v7 = sub_45BB00();
  if ( v7 || this[202] != 0.0 )
  {
    v6 = sub_45B5C0((int)this) + 0.050000001;
    v8 = (double)v7 * 0.035;
    if ( this[201] != v6 )
    {
      v2 = v6 - this[201];
      if ( fabs(v2) > 0.001000000047497451 )
        this[201] = v2 * 0.40000001 + this[201];
      else
        this[201] = v6;
    }
    if ( this[202] != v8 )
    {
      v3 = v8 - this[202];
      if ( fabs(v3) > 0.001000000047497451 )
        this[202] = v3 * 0.40000001 + this[202];
      else
        this[202] = v8;
    }
    sub_4DCDA0(this[201], this[202]);
    sub_4DCEE0(0.5, 0.0, 1.0, 2);
    sub_4DCD60(0);
    sub_4DCF30(&v11, &v12);
    sub_4DCF50(&v10, &v9, 0);
    v4 = v10 + v11;
    v5 = v9 + v12;
    sub_494C20(v10, v9, v10, v9 + v12, -6710887, dword_8B8DC8);
    sub_494C20(v10, v5, v4, v5, -6710887, dword_8B8DC8);
    sub_494C20(v4, v5, v4, v9, -6710887, dword_8B8DC8);
    sub_494C20(v4, v9, v10, v9, -6710887, dword_8B8DC8);
  }
  else
  {
    this[201] = 0.0;
  }
}

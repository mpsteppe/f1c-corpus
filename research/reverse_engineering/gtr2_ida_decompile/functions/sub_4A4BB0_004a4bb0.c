int __thiscall sub_4A4BB0(_DWORD *this)
{
  const CHAR *v1; // eax
  const char *v2; // eax
  char *v3; // eax
  float *v4; // esi
  const char *v5; // eax
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  float v11; // [esp+0h] [ebp-4Ch]
  float v12; // [esp+0h] [ebp-4Ch]
  float v13; // [esp+4h] [ebp-48h]
  _BYTE v14[64]; // [esp+Ch] [ebp-40h] BYREF

  v1 = (const CHAR *)this[44];
  if ( !v1 )
    v1 = WindowName;
  sub_630FE0(v14, v1, 63);
  v14[63] = 0;
  v11 = 0.0;
  v2 = (const char *)sub_6331DF(v14, CommandLine);
  if ( v2 )
    v11 = atof(v2);
  v3 = dword_B6F708;
  if ( !dword_B6F708 )
    v3 = (char *)WindowName;
  v4 = (float *)sub_539670(v3);
  if ( v11 >= (double)v4[36] )
  {
    if ( v11 > (double)v4[35] )
      v11 = v4[35];
  }
  else
  {
    v11 = v4[36];
  }
  flt_B70EF4 = v11;
  if ( v11 >= (double)flt_B70EFC )
  {
    if ( v11 > (double)flt_B70F00 )
      flt_B70EF4 = flt_B70F00;
  }
  else
  {
    flt_B70EF4 = flt_B70EFC;
  }
  v5 = (const char *)sub_6331DF(0, CommandLine);
  if ( v5 )
    v6 = atof(v5);
  else
    v6 = 0.0;
  v13 = v4[33];
  v12 = v4[34];
  if ( v6 >= v13 )
  {
    if ( v6 > v12 )
      v6 = v12;
  }
  else
  {
    v6 = v13;
  }
  flt_B70ED0 = v6;
  if ( v8 | v9 )
  {
    flt_B70ED0 = flt_B70ED8;
  }
  else if ( v6 > flt_B70EDC )
  {
    flt_B70ED0 = flt_B70EDC;
  }
  sub_4144F0();
  sub_413D50((_DWORD **)&dword_91BF20, (int)"COCKPIT", 1);
  return 0;
}

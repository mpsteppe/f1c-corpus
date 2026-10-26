int __thiscall sub_4FBA10(float *this)
{
  int v2; // eax
  int v3; // eax
  unsigned int v4; // kr04_4
  unsigned int v5; // kr08_4
  char *v6; // ecx
  int v7; // ebx
  float *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  int i; // ebx
  float v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // edi
  double v23; // st7
  double v24; // st7
  double v25; // st7
  int result; // eax
  double v27; // st7
  void *v28; // ecx
  double v29; // st7
  float v30; // edx
  float v31[3]; // [esp+18h] [ebp-458h] BYREF
  float v32[3]; // [esp+24h] [ebp-44Ch] BYREF
  _BYTE v33[64]; // [esp+30h] [ebp-440h] BYREF
  _DWORD v34[128]; // [esp+70h] [ebp-400h]
  float v35[128]; // [esp+270h] [ebp-200h]

  v2 = sub_5453A0(aSkyboxi, 0);
  *(_DWORD *)this = v2;
  if ( v2 )
  {
    sub_54B420(this + 1, this + 2, this + 3);
    sub_54BDC0(0, 0, 0);
  }
  v3 = 0;
  v4 = strlen(aCloudsny) + 1;
  v5 = strlen(aCloudrny) + 1;
  this[16] = NAN;
  do
  {
    if ( v3 )
    {
      if ( v3 == 1 )
        v6 = aCloudsny;
      else
        v6 = v3 != 2 ? 0 : aCloudrny;
    }
    else
    {
      v6 = aClouds;
    }
    v7 = v3 + 1;
    v8 = &this[4 * v3 + 4];
    v9 = sub_5453A0(v6, *(_DWORD *)this);
    *(_DWORD *)v8 = v9;
    if ( v9 )
    {
      sub_54B420(v8 + 1, v8 + 2, v8 + 3);
      sub_54BDC0(0, 0, 0);
    }
    v3 = v7;
  }
  while ( v7 < 3 );
  v10 = *((_DWORD *)this + 8);
  this[18] = 0.0;
  this[31] = 0.0;
  if ( v10 )
  {
    v34[0] = v10;
    *((_DWORD *)this + 18) = 1;
  }
  if ( *((_DWORD *)this + 12) )
  {
    v35[0] = this[12];
    *((_DWORD *)this + 31) = 1;
  }
  v11 = sub_5452F0(dword_8AFE88);
  for ( i = 0; i < v11; ++i )
  {
    v13 = COERCE_FLOAT(sub_545340(i));
    sub_54BDA0(v33);
    if ( sub_588640(v33, aCloudsny, v4 - 1) )
    {
      if ( !sub_588640(v33, aCloudrny, v5 - 1) )
      {
        v15 = *((_DWORD *)this + 31);
        v35[v15] = v13;
        *((_DWORD *)this + 31) = v15 + 1;
      }
    }
    else
    {
      v14 = *((_DWORD *)this + 18);
      *(float *)&v34[v14] = v13;
      *((_DWORD *)this + 18) = v14 + 1;
    }
  }
  v16 = sub_587C03(4 * *((_DWORD *)this + 18));
  v17 = *((_DWORD *)this + 18);
  *((_DWORD *)this + 19) = v16;
  v18 = 0;
  if ( v17 > 0 )
  {
    do
    {
      *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v18) = v34[v18];
      ++v18;
    }
    while ( v18 < *((_DWORD *)this + 18) );
  }
  v19 = sub_587C03(4 * *((_DWORD *)this + 31));
  v20 = *((_DWORD *)this + 31);
  *((_DWORD *)this + 32) = v19;
  v21 = 0;
  if ( v20 > 0 )
  {
    do
    {
      *(float *)(*((_DWORD *)this + 32) + 4 * v21) = v35[v21];
      ++v21;
    }
    while ( v21 < *((_DWORD *)this + 31) );
  }
  v22 = sub_545F40(dword_8AFE88);
  if ( v22 )
    *((_DWORD *)this + 28) = sub_548890(aCloudsny);
  else
    this[28] = 0.0;
  v23 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.5;
  this[29] = (v23 + 0.5) * flt_7CF914;
  v24 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.5;
  this[30] = (v24 + 0.5) * flt_7CF914;
  if ( v22 )
    *((_DWORD *)this + 41) = sub_548890(aCloudrny);
  else
    this[41] = 0.0;
  v25 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.5;
  this[42] = (v25 + 0.5) * flt_7CF914;
  result = dword_8AAE70 + 1;
  v27 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.5;
  v28 = (void *)*((_DWORD *)this + 8);
  v29 = (v27 + 0.5) * flt_7CF914;
  this[44] = 3.4028235e38;
  this[45] = -3.4028235e38;
  this[43] = v29;
  if ( v28 )
  {
    result = sub_4DD550(v28, v32, v31);
    v30 = v31[0];
    this[44] = v32[0];
    this[45] = v30;
  }
  this[46] = -1.0;
  return result;
}

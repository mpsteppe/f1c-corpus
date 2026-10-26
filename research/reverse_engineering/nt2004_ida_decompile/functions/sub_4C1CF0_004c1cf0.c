char __thiscall sub_4C1CF0(float *this)
{
  float *v2; // edi
  double v3; // st7
  double v4; // st7
  float *v6; // edi
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  double v10; // st7
  float v11; // [esp+8h] [ebp-6Ch]
  float v12; // [esp+Ch] [ebp-68h]
  float v13; // [esp+10h] [ebp-64h]
  float v14; // [esp+14h] [ebp-60h]
  float v15; // [esp+18h] [ebp-5Ch]
  float v16; // [esp+1Ch] [ebp-58h]
  float v17[3]; // [esp+20h] [ebp-54h] BYREF
  float v18[3]; // [esp+2Ch] [ebp-48h] BYREF
  _DWORD v19[3]; // [esp+38h] [ebp-3Ch] BYREF
  _BYTE v20[12]; // [esp+44h] [ebp-30h] BYREF
  float v21[2]; // [esp+50h] [ebp-24h] BYREF
  float v22; // [esp+58h] [ebp-1Ch]
  float v23; // [esp+5Ch] [ebp-18h]
  float v24; // [esp+64h] [ebp-10h]
  float v25; // [esp+68h] [ebp-Ch]
  float v26; // [esp+70h] [ebp-4h]

  sub_4045E0(&flt_628F60, *(_DWORD *)(*(_DWORD *)this + 25264), v18, v19);
  v2 = (float *)(*(_DWORD *)this + 84);
  sub_51C1E0(v17, v20);
  v11 = v17[0] - v18[0];
  v12 = v17[1] - v18[1];
  v3 = v17[2] - v18[2];
  v13 = v3;
  if ( sqrt(v3 * v13 + v12 * v12 + v11 * v11) > 25.0 )
  {
    sub_579100(v19, v21);
    v14 = v22;
    v15 = v24;
    v16 = v26;
    v4 = sub_424C30((_DWORD *)*(_DWORD *)this, *(_DWORD *)(*(_DWORD *)this + 23608));
    if ( v4 < 50.0 )
      v4 = v16 * v13 + v15 * v12 + v14 * v11;
LABEL_11:
    if ( v4 < 0.0 && (unsigned __int8)sub_4EED40(*(_DWORD *)this) && *(_DWORD *)dword_7668AC )
    {
LABEL_9:
      sub_45D100(&byte_764D68, (int)aPitstopSkipped, 3, 16909060, 0);
      sub_4C1790(this, 4);
      return 0;
    }
    return 0;
  }
  sub_579100(v19, v21);
  v4 = v26 * v13 + v24 * v12 + v22 * v11;
  if ( v4 > 1.5 )
    return 0;
  if ( v4 < -5.0 )
  {
    sub_427FC0(*(_DWORD **)this);
    if ( (unsigned __int8)sub_4EED40(*(_DWORD *)this) && *(_DWORD *)dword_7668AC )
      goto LABEL_9;
    return 0;
  }
  if ( fabs(v25 * v13 + v23 * v12 + v21[0] * v11) > 1.5 )
    goto LABEL_11;
  if ( v26 * v2[4379] + v2[4376] * v24 + v2[4373] * v22 < 0.85000002 )
  {
    if ( v4 < 0.0 && (unsigned __int8)sub_4EED40(*(_DWORD *)this) && *(_DWORD *)dword_7668AC )
    {
      sub_45D100(&byte_764D68, (int)aPitstopSkipped, 3, 16909060, 0);
      sub_4C1790(this, 4);
    }
    return 0;
  }
  v6 = v2 + 4386;
  v10 = v6[1] * v6[1] + v6[2] * v6[2] + *v6 * *v6;
  if ( v8 | v9 )
  {
    if ( v10 > 4.0 )
      return 0;
  }
  else if ( v10 > 0.040000003 )
  {
    return 0;
  }
  return 1;
}

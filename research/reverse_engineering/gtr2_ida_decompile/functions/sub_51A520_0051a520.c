int __thiscall sub_51A520(_DWORD *this, float *a2)
{
  long double v3; // st7
  double v6; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  float v9; // [esp+0h] [ebp-14h]
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+0h] [ebp-14h]
  float v12; // [esp+0h] [ebp-14h]
  float v13; // [esp+4h] [ebp-10h]
  float v14; // [esp+4h] [ebp-10h]
  float v15; // [esp+4h] [ebp-10h]
  float v16; // [esp+4h] [ebp-10h]
  float v17; // [esp+8h] [ebp-Ch]
  float v18; // [esp+8h] [ebp-Ch]
  float v19; // [esp+8h] [ebp-Ch]
  float v20; // [esp+8h] [ebp-Ch]
  float v21; // [esp+Ch] [ebp-8h]
  float v22; // [esp+10h] [ebp-4h]
  float v23; // [esp+18h] [ebp+4h]

  v3 = fabs(*a2);
  v22 = fabs(a2[1]);
  v23 = fabs(a2[2]);
  v21 = fabs(a2[3]);
  if ( v3 > v22 )
  {
    if ( v23 > (double)v21 )
    {
      if ( v3 > v23 )
      {
LABEL_6:
        if ( *a2 >= 0.0 )
          return sub_51A4B0(this, 0, a2[1], a2[2], a2[3]);
        v17 = -a2[3];
        v13 = -a2[2];
        v9 = -a2[1];
        return sub_51A4B0(this, 0, v9, v13, v17);
      }
      goto LABEL_11;
    }
    if ( v3 > v21 )
      goto LABEL_6;
    goto LABEL_18;
  }
  v6 = v22;
  if ( v7 | v8 )
  {
    if ( v6 <= v21 )
    {
LABEL_18:
      if ( a2[3] >= 0.0 )
        return sub_51A4B0(this, 3, *a2, a2[1], a2[2]);
      v20 = -a2[2];
      v16 = -a2[1];
      v12 = -*a2;
      return sub_51A4B0(this, 3, v12, v16, v20);
    }
  }
  else if ( v6 <= v23 )
  {
LABEL_11:
    if ( a2[2] >= 0.0 )
      return sub_51A4B0(this, 2, *a2, a2[1], a2[3]);
    v18 = -a2[3];
    v14 = -a2[1];
    v10 = -*a2;
    return sub_51A4B0(this, 2, v10, v14, v18);
  }
  if ( a2[1] >= 0.0 )
    return sub_51A4B0(this, 1, *a2, a2[2], a2[3]);
  v19 = -a2[3];
  v15 = -a2[2];
  v11 = -*a2;
  return sub_51A4B0(this, 1, v11, v15, v19);
}

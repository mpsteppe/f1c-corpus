__int16 *__thiscall sub_45B8C0(__int16 *this, float *a2)
{
  __int16 *v3; // edi
  int v4; // ecx
  float *v5; // edx
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st5
  bool v10; // cl
  bool v11; // al
  bool v12; // bl
  float *v13; // esi
  bool v14; // cl
  bool v15; // al
  float *v16; // esi
  __int16 *result; // eax
  int v18; // esi
  float v19; // [esp+10h] [ebp-Ch]
  float v20; // [esp+10h] [ebp-Ch]
  float v21; // [esp+14h] [ebp-8h]
  float v22; // [esp+14h] [ebp-8h]
  float v23; // [esp+18h] [ebp-4h]
  float v24; // [esp+20h] [ebp+4h]

  v3 = this;
  if ( this[4] < 0 )
  {
LABEL_39:
    v16 = (float *)*((_DWORD *)v3 + 3);
    if ( sub_45AD90(v16, a2) || v3[4] == -2 && sub_45AD90(v16 + 24, a2) )
      return v3;
    else
      return 0;
  }
  while ( 1 )
  {
    v4 = *((char *)v3 + 11);
    v19 = flt_B685D0[*((char *)v3 + 10)];
    v5 = (float *)*((_DWORD *)v3 + 3);
    v23 = flt_B685D0[v4] * a2[2];
    v6 = v19 * *a2;
    v21 = v6;
    v7 = v6 + v23;
    v8 = flt_B685D0[v4] * a2[3];
    v24 = v21 + v8;
    v9 = v19 * a2[1];
    v20 = v23 + v9;
    v22 = v9 + v8;
    v10 = v7 < *v5 && v24 < (double)*v5 && v20 < (double)*v5 && v22 < (double)*v5;
    v11 = v7 > v5[1] && v24 > (double)v5[1] && v20 > (double)v5[1] && v22 > (double)v5[1];
    v12 = v10 || v11;
    v13 = v5 + 4;
    v14 = v7 < v5[4] && v24 < (double)*v13 && v20 < (double)*v13 && v22 < (double)*v13;
    v15 = v7 > v5[5] && v24 > (double)v5[5] && v20 > (double)v5[5] && v22 > (double)v5[5];
    if ( v14 || v15 )
      v15 = 1;
    if ( v12 )
    {
      if ( v15 )
        return 0;
      v3 = (__int16 *)(v5 + 4);
      goto LABEL_38;
    }
    if ( !v15 )
      break;
    v3 = (__int16 *)*((_DWORD *)v3 + 3);
LABEL_38:
    if ( v3[4] < 0 )
      goto LABEL_39;
  }
  v18 = sub_45B8C0(a2);
  result = (__int16 *)sub_45B8C0(a2);
  if ( v18 )
  {
    if ( result )
      return v3;
    return (__int16 *)v18;
  }
  return result;
}

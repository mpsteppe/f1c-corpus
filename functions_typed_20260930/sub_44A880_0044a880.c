float *__thiscall sub_44A880(float *this, float *a2)
{
  __int16 v2; // dx
  double v4; // st7
  double v5; // st6
  float *v6; // esi
  double v7; // st5
  double v8; // st4
  double v9; // rt0
  double v10; // st4
  double v11; // st6
  double v12; // st7
  bool v13; // dl
  bool v14; // al
  bool v15; // bl
  float *v16; // edi
  bool v17; // dl
  bool v18; // al
  float v20; // [esp+10h] [ebp-Ch]
  float v21; // [esp+14h] [ebp-8h]
  float v22; // [esp+14h] [ebp-8h]
  float v23; // [esp+18h] [ebp-4h]
  float v24; // [esp+20h] [ebp+4h]

  v2 = *((_WORD *)this + 4);
  if ( v2 < 0 )
    return this;
  while ( 1 )
  {
    v4 = dword_7CA388[*((__int16 *)this + 5)];
    v5 = *((float *)&unk_7CA3A4 - *((__int16 *)this + 5));
    if ( v2 )
      v5 = -v5;
    v6 = (float *)*((_DWORD *)this + 3);
    v7 = v5 * a2[2];
    v8 = v4 * *a2;
    v24 = v8 + v7;
    v9 = v8;
    v10 = v5 * a2[3];
    v23 = v10;
    v20 = v10 + v9;
    v11 = v4 * a2[1];
    v21 = v11;
    v12 = v7 + v11;
    v22 = v21 + v23;
    v13 = v24 < (double)*v6 && v20 < (double)*v6 && v12 < *v6 && v22 < (double)*v6;
    v14 = v24 > (double)v6[1] && v20 > (double)v6[1] && v12 > v6[1] && v22 > (double)v6[1];
    v15 = v13 || v14;
    v16 = v6 + 4;
    v17 = v24 < (double)v6[4] && v20 < (double)*v16 && v12 < *v16 && v22 < (double)*v16;
    v18 = v24 > (double)v6[5] && v20 > (double)v6[5] && v12 > v6[5] && v22 > (double)v6[5];
    if ( v17 || v18 )
      v18 = 1;
    if ( !v15 )
    {
      if ( !v18 )
        return this;
      this = (float *)*((_DWORD *)this + 3);
      goto LABEL_40;
    }
    if ( v18 )
      return 0;
    this = v6 + 4;
LABEL_40:
    v2 = *((_WORD *)this + 4);
    if ( v2 < 0 )
      return this;
  }
}


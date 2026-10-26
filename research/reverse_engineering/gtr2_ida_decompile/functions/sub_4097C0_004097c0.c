int __thiscall sub_4097C0(_DWORD *this)
{
  int result; // eax
  int v3; // esi
  int v4; // eax
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float v10; // [esp+Ch] [ebp-3Ch]
  int v11; // [esp+10h] [ebp-38h]
  float v12; // [esp+18h] [ebp-30h]
  float v13; // [esp+18h] [ebp-30h]
  double v14; // [esp+18h] [ebp-30h]
  float v15; // [esp+1Ch] [ebp-2Ch]
  float v16; // [esp+1Ch] [ebp-2Ch]
  float v17; // [esp+20h] [ebp-28h]
  float v18; // [esp+20h] [ebp-28h]
  float v19; // [esp+24h] [ebp-24h] BYREF
  float v20; // [esp+28h] [ebp-20h] BYREF
  float v21; // [esp+2Ch] [ebp-1Ch] BYREF
  float v22; // [esp+30h] [ebp-18h] BYREF
  float v23; // [esp+34h] [ebp-14h] BYREF
  float v24; // [esp+38h] [ebp-10h] BYREF
  float v25[3]; // [esp+3Ch] [ebp-Ch] BYREF

  sub_4095D0((int)v25, v11);
  result = sub_4031C0();
  v3 = result;
  if ( result )
  {
    if ( this[4] )
      sub_5DA610(&v19, &v20, &v21, &v22, &v23, &v24);
    v4 = *(_DWORD *)(v3 + 276);
    v5 = *(float *)(v4 + 4);
    v4 += 4;
    v12 = v5 - *(float *)(v3 + 4);
    v6 = *(float *)(v4 + 4);
    v19 = v12;
    v15 = v6 - *(float *)(v3 + 8);
    v7 = *(float *)(v4 + 8);
    v20 = v15;
    v17 = v7 - *(float *)(v3 + 12);
    v21 = v17;
    sub_409390(&v19);
    v13 = v25[0] - *(float *)(v3 + 4);
    v22 = v13;
    v16 = v25[1] - *(float *)(v3 + 8);
    v23 = v16;
    v18 = v25[2] - *(float *)(v3 + 12);
    v24 = v18;
    if ( v18 * *(float *)(v3 + 44) + v16 * *(float *)(v3 + 40) + v13 * *(float *)(v3 + 36) <= 0.0 )
    {
      v8 = 1.570796326794897;
    }
    else
    {
      v22 = -v19;
      v19 = v22;
      v23 = -v20;
      v20 = v23;
      v24 = -v21;
      v8 = -1.570796326794897;
      v21 = v24;
    }
    v14 = v8;
    v9 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.050000001;
    v10 = v9 - atan2(v21, v19) + v14;
    return (*(int (__thiscall **)(_DWORD *, float *, _DWORD))(*this + 16))(this, v25, LODWORD(v10));
  }
  return result;
}

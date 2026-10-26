void __thiscall sub_57F350(float *this)
{
  int v2; // esi
  double v3; // st7
  bool v4; // c0
  bool v5; // c3
  float v6; // edx
  float v7; // ecx
  double v8; // st7
  float *v9; // eax
  float v10; // ecx
  float v11; // edx
  float v12; // eax
  double v13; // st7
  double v14; // st6
  double v15; // st7
  long double v16; // st7
  long double v17; // st6
  float v18; // [esp+8h] [ebp-5Ch]
  float v19; // [esp+Ch] [ebp-58h] BYREF
  float v20; // [esp+10h] [ebp-54h]
  float v21; // [esp+14h] [ebp-50h]
  float v22; // [esp+18h] [ebp-4Ch] BYREF
  float v23; // [esp+1Ch] [ebp-48h]
  float v24; // [esp+20h] [ebp-44h]
  float v25[2]; // [esp+24h] [ebp-40h] BYREF
  double v26[6]; // [esp+30h] [ebp-34h] BYREF
  int v27; // [esp+60h] [ebp-4h]

  if ( sqrt(this[3999] * this[3999] + this[4000] * this[4000] + this[4001] * this[4001]) * 2.2369363 < 1.0
    && !*(_BYTE *)(*(_DWORD *)this + 15572)
    && !sub_577A80(this) )
  {
    v2 = sub_5761B0((int)this);
    if ( v2 )
    {
      sub_573810();
      v3 = *(float *)(v2 + 48);
      v4 = v3 < *(float *)(v2 + 52);
      v5 = v3 == *(float *)(v2 + 52);
      v6 = *(float *)(v2 + 4);
      v7 = *(float *)(v2 + 12);
      v20 = *(float *)(v2 + 8);
      v19 = v6;
      v21 = v7;
      if ( v4 || v5 )
        v8 = *(float *)(v2 + 52) - 1.0;
      else
        v8 = 1.0 - *(float *)(v2 + 48);
      v18 = v8;
      v9 = sub_4012D0((float *)(v2 + 36), v25, v18);
      v10 = *v9;
      v11 = v9[1];
      v12 = v9[2];
      v22 = v10;
      v13 = v10 + v19;
      v23 = v11;
      v24 = v12;
      v19 = v13;
      v14 = v11 + v20;
      v27 = 0;
      v20 = v14;
      v21 = v12 + v21;
      v26[0] = v13;
      v26[1] = v14;
      v26[2] = v21;
      v26[3] = 3.0;
      v26[4] = 9.999999933815813e36;
      if ( sub_45D190(dbl_B68610, (int)v26) )
        v15 = v26[5];
      else
        v15 = v20;
      v20 = v15 + 0.1;
      v16 = -*(float *)(v2 + 168);
      v22 = 0.0;
      v17 = -*(float *)(v2 + 176);
      v24 = 0.0;
      v23 = atan2(v16, v17);
      sub_57DCC0(this, (int)&v19, &v22);
    }
  }
}

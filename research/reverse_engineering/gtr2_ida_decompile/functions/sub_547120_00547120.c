void __thiscall sub_547120(float *this, float a2, float *a3, float a4)
{
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  double v8; // st7
  long double v9; // st6
  long double v10; // st6
  int v11; // edx
  int v12; // eax
  double v13; // st7
  float *v14; // edi
  float *v15; // eax
  float v16; // esi
  int v17; // eax
  _DWORD ***v18; // esi
  _DWORD **v19; // esi
  _DWORD *v20; // esi
  float v21; // [esp+10h] [ebp-Ch]
  float v22; // [esp+10h] [ebp-Ch]
  float v23; // [esp+14h] [ebp-8h]
  float v24; // [esp+18h] [ebp-4h]
  float v25; // [esp+18h] [ebp-4h]
  float v26; // [esp+24h] [ebp+8h]

  v21 = this[1] - *a3;
  v23 = this[2] - a3[1];
  v24 = this[3] - a3[2];
  v5 = a4 + this[4];
  if ( v5 * v5 >= v24 * v24 + v23 * v23 + v21 * v21 )
  {
    this[5] = a2 + this[5];
    v6 = sub_592960(&dword_FB1EF8);
    v7 = 0;
    v8 = (v6 * 3.4000001 + this[6]) * this[7];
    v9 = this[8] * this[5];
    v26 = sin(v9);
    v10 = cos(v9);
    v22 = (v10 * this[11] + v26 * this[9]) * v8;
    v25 = (v10 * this[12] + v26 * this[10]) * v8;
    if ( *((int *)this + 13) > 0 )
    {
      v11 = 0;
      do
      {
        v12 = *((_DWORD *)this + 14);
        v13 = v22 * *(float *)(v12 + v11 + 16);
        v14 = *(float **)(v12 + v11);
        v15 = (float *)(v11 + v12);
        ++v7;
        v11 += 20;
        *v14 = v13 + v15[1];
        *(float *)(*(_DWORD *)v15 + 4) = v15[4] * 0.0 + v15[2];
        *(float *)(*(_DWORD *)v15 + 8) = v25 * v15[4] + v15[3];
      }
      while ( v7 < *((_DWORD *)this + 13) );
    }
    v16 = *this;
    v17 = *(_DWORD *)(LODWORD(v16) + 544);
    v18 = (_DWORD ***)(LODWORD(v16) + 532);
    if ( v17 > 0 )
    {
      v19 = *v18;
      if ( v19 )
      {
        v20 = *v19;
        if ( v20 )
          *v20 &= ~0x800u;
      }
    }
  }
}

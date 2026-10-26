char __thiscall sub_459F60(_DWORD *this, float a2, int a3)
{
  int v4; // ecx
  char result; // al
  _DWORD *v7; // ecx
  _DWORD *v8; // edx
  double v9; // st7
  int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  int v13; // ecx
  int v14; // ebp
  float *v15; // edx
  double v16; // st7
  int v17; // eax
  double v18; // st7
  double v19; // st6
  int v20; // esi
  double v21; // st7
  float v22; // [esp+8h] [ebp-3Ch]
  float v23; // [esp+Ch] [ebp-38h]
  float v24; // [esp+10h] [ebp-34h]
  int v25[4]; // [esp+14h] [ebp-30h] BYREF
  int v26[4]; // [esp+24h] [ebp-20h] BYREF
  _BYTE v27[16]; // [esp+34h] [ebp-10h] BYREF
  float v28; // [esp+4Ch] [ebp+8h]

  v4 = *this;
  result = 0;
  if ( v4 && a3 )
  {
    if ( a2 > 0.0 )
    {
      v9 = sub_45A1D0(this);
      v10 = this[1];
      if ( v9 > a2 )
      {
        v13 = 1;
        if ( v10 - 2 > 1 )
        {
          v14 = *this;
          v15 = (float *)(*this + 80);
          while ( a2 < (double)*(v15 - 7) || a2 >= (double)*v15 )
          {
            ++v13;
            v15 += 7;
            if ( v13 >= v10 - 2 )
              goto LABEL_14;
          }
          v16 = *(float *)(28 * v13 + v14 + 24);
          a2 = (a2 - v16) / (*(float *)(28 * v13 + v14 + 52) - v16);
        }
LABEL_14:
        v17 = *this;
        v18 = a2 * a2;
        v19 = a2 * v18;
        v20 = 28 * v13;
        v23 = v18 + v18 - v19 - a2;
        v22 = v18 * 4.0 - 3.0 * v19 + a2;
        v24 = a2 * 0.0;
        v28 = 3.0 * v19 - v18 * 5.0 + v24 + 2.0;
        v21 = v19 - v18 + v24;
        *(float *)a3 = (*(float *)(28 * (v13 + 2) + v17) * v21
                      + *(float *)(28 * (v13 + 1) + v17) * v22
                      + *(float *)(28 * v13 + v17 - 28) * v23
                      + *(float *)(28 * v13 + v17) * v28)
                     * 0.5;
        *(float *)(a3 + 4) = (*(float *)(*this + 28 * v13 + 60) * v21
                            + *(float *)(28 * v13 + *this + 4) * v28
                            + *(float *)(28 * v13 + *this + 32) * v22
                            + *(float *)(28 * v13 + *this - 24) * v23)
                           * 0.5;
        *(float *)(a3 + 8) = (*(float *)(28 * v13 + *this + 64) * v21
                            + *(float *)(28 * v13 + *this + 8) * v28
                            + *(float *)(28 * v13 + *this + 36) * v22
                            + *(float *)(28 * v13 + *this - 20) * v23)
                           * 0.5;
        sub_579450(28 * v13 + *this + 12, v26);
        sub_579450(v20 + *this + 40, v25);
        sub_579D90((int)v26, (int)v25, a2);
        sub_579430(v27, a3 + 12);
        return 1;
      }
      else
      {
        v11 = (_DWORD *)(*this + 28 * (v10 - 2));
        *(_DWORD *)a3 = *v11;
        *(_DWORD *)(a3 + 4) = v11[1];
        *(_DWORD *)(a3 + 8) = v11[2];
        v12 = (_DWORD *)(28 * this[1] + *this - 44);
        *(_DWORD *)(a3 + 12) = *v12;
        *(_DWORD *)(a3 + 16) = v12[1];
        *(_DWORD *)(a3 + 20) = v12[2];
        return 1;
      }
    }
    else
    {
      v7 = (_DWORD *)(v4 + 28);
      *(_DWORD *)a3 = *v7;
      *(_DWORD *)(a3 + 4) = v7[1];
      *(_DWORD *)(a3 + 8) = v7[2];
      v8 = (_DWORD *)(*this + 40);
      *(_DWORD *)(a3 + 12) = *v8;
      *(_DWORD *)(a3 + 16) = v8[1];
      *(_DWORD *)(a3 + 20) = v8[2];
      return 1;
    }
  }
  return result;
}

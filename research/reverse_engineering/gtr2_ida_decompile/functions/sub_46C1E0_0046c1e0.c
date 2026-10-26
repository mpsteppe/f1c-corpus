_DWORD *__thiscall sub_46C1E0(float *this, float a2)
{
  float *v2; // edx
  _DWORD *result; // eax
  float *v4; // edx
  int v5; // esi
  int v6; // edi
  float *v7; // edx
  double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st4
  float *v12; // edx
  double v13; // st7
  float v14; // [esp+0h] [ebp-10h]
  float v15; // [esp+4h] [ebp-Ch]
  float v16; // [esp+8h] [ebp-8h]
  float v17; // [esp+Ch] [ebp-4h]

  if ( a2 >= 0.0 )
  {
    if ( a2 < (double)this[2] )
    {
      v5 = 0;
      if ( *((_DWORD *)this + 1) - 3 > 0 )
      {
        v6 = *(_DWORD *)this;
        v7 = (float *)(*(_DWORD *)this + 52);
        while ( a2 < (double)*(v7 - 7) || a2 >= (double)*v7 )
        {
          ++v5;
          v7 += 7;
          if ( v5 >= *((_DWORD *)this + 1) - 3 )
            goto LABEL_12;
        }
        v8 = *(float *)(28 * v5 + v6 + 24);
        v14 = (a2 - v8) / (*(float *)(28 * v5 + v6 + 52) - v8);
      }
LABEL_12:
      v9 = v14 * v14;
      v10 = v14 * v9;
      v11 = v14 * 0.0;
      v17 = 3.0 * v10 - v9 * 5.0 + v11 + 2.0;
      v12 = (float *)(28 * v5 + *(_DWORD *)this);
      v16 = v9 * 4.0 - 3.0 * v10 + v14;
      result = this + 4;
      v15 = v10 - v9 + v11;
      v13 = v9 + v9 - v10 - v14;
      this[4] = (v15 * *(float *)(28 * (v5 + 3) + *(_DWORD *)this)
               + v16 * *(float *)(28 * (v5 + 2) + *(_DWORD *)this)
               + v17 * v12[7]
               + v13 * *v12)
              * 0.5;
      this[5] = (v13 * v12[1] + v15 * v12[22] + v16 * v12[15] + v17 * v12[8]) * 0.5;
      this[6] = (v13 * v12[2] + v15 * v12[23] + v16 * v12[16] + v17 * v12[9]) * 0.5;
      this[3] = a2;
    }
    else
    {
      v4 = (float *)(*(_DWORD *)this + 28 * (*((_DWORD *)this + 1) - 2));
      result = this + 4;
      this[4] = *v4;
      this[5] = v4[1];
      this[6] = v4[2];
      this[3] = this[2];
    }
  }
  else
  {
    v2 = (float *)(*(_DWORD *)this + 28);
    result = this + 4;
    this[4] = *v2;
    this[5] = v2[1];
    this[6] = v2[2];
    this[3] = 0.0;
  }
  return result;
}

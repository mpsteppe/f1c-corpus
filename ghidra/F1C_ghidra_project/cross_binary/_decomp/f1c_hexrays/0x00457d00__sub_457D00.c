// f1c  0x00457d00  size=477
_DWORD *__thiscall sub_457D00(float *this, float a2)
{
  float *v2; // edx
  _DWORD *result; // eax
  float *v4; // edx
  int v5; // edi
  int v6; // esi
  int v7; // ebx
  float *v8; // edx
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st4
  float *v13; // edx
  double v14; // st7
  double v15; // st6
  double v16; // st5
  float v17; // [esp+0h] [ebp-10h]
  float v18; // [esp+4h] [ebp-Ch]
  float v19; // [esp+8h] [ebp-8h]
  float v20; // [esp+Ch] [ebp-4h]

  if ( a2 >= 0.0 )
  {
    if ( a2 < (double)this[2] )
    {
      v5 = *((_DWORD *)this + 1) - 3;
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = *(_DWORD *)this;
        v8 = (float *)(*(_DWORD *)this + 52);
        while ( *(v8 - 7) > (double)a2 || *v8 <= (double)a2 )
        {
          ++v6;
          v8 += 7;
          if ( v6 >= v5 )
            goto LABEL_12;
        }
        v9 = *(float *)(28 * v6 + v7 + 24);
        v17 = (a2 - v9) / (*(float *)(28 * v6 + v7 + 52) - v9);
      }
LABEL_12:
      v10 = v17 * v17;
      v11 = v17 * v10;
      v12 = v17 * 0.0;
      v13 = (float *)(*(_DWORD *)this + 28 * v6);
      result = this + 4;
      v20 = 3.0 * v11 - v10 * 5.0 + v12 + 2.0;
      v19 = v10 * 4.0 - 3.0 * v11 + v17;
      v18 = v11 - v10 + v12;
      v14 = v10 + v10 - v11 - v17;
      this[4] = (*(float *)(28 * (v6 + 3) + *(_DWORD *)this) * v18
               + *(float *)(28 * (v6 + 2) + *(_DWORD *)this) * v19
               + *(float *)(28 * (v6 + 1) + *(_DWORD *)this) * v20
               + *v13 * v14)
              * 0.5;
      this[5] = (v13[1] * v14 + v13[22] * v18 + v13[15] * v19 + v13[8] * v20) * 0.5;
      v15 = v13[2] * v14 + v13[23] * v18 + v13[16] * v19;
      v16 = v13[9];
      this[3] = a2;
      this[6] = (v15 + v16 * v20) * 0.5;
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

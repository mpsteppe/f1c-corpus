int __thiscall sub_466650(float *this)
{
  int result; // eax
  double v3; // st7
  double v4; // st7
  char v5; // al
  bool v6; // c3
  int v7; // eax
  int v8; // eax
  long double v9; // st7
  float v10; // edx
  double v11; // st7
  double v12; // st6
  int v13; // edx
  float v14; // [esp+4h] [ebp-28h] BYREF
  float v15; // [esp+8h] [ebp-24h]
  float v16; // [esp+Ch] [ebp-20h]
  float v17; // [esp+10h] [ebp-1Ch] BYREF
  float v18; // [esp+14h] [ebp-18h] BYREF
  int v19; // [esp+18h] [ebp-14h] BYREF
  int v20; // [esp+1Ch] [ebp-10h] BYREF
  int v21; // [esp+20h] [ebp-Ch] BYREF
  int v22; // [esp+24h] [ebp-8h] BYREF
  int v23; // [esp+28h] [ebp-4h] BYREF

  result = *((_DWORD *)this + 60);
  if ( result )
  {
    v21 = 0;
    v20 = 0;
    v19 = 0;
    v18 = 0.0;
    v14 = 0.0;
    v17 = 0.0;
    DualFieldRead(&v22, &v23);
    v3 = FloatFieldAccessor(*((_DWORD *)this + 16));
    v15 = v3;
    v4 = v3 + this[67];
    this[67] = v4;
    if ( v4 > 3.0 )
      this[67] = 3.0;
    DualMatrixTransformMultiply(&v21, &v20, &v19, &v18, &v14, &v17);
    v5 = *((_BYTE *)this + 244);
    v14 = this[69];
    if ( v5 )
    {
      FieldSetterCall(3);
      v6 = v15 == 0.0;
      this[67] = 0.0;
      v7 = v22;
      if ( !v6 )
      {
        LODWORD(v16) = v22 - *((_DWORD *)this + 65);
        this[68] = (double)SLODWORD(v16) / v15 * 0.5;
      }
      v8 = v7 - *((_DWORD *)this + 65);
      v9 = sqrt(this[68] * this[68]) * 0.00030000001;
      if ( v8 <= 0 )
      {
        if ( v8 < 0 )
        {
          v10 = *this;
          v14 = v9 + v14;
          (*(void (__thiscall **)(float *, int))(LODWORD(v10) + 44))(this, 1);
LABEL_24:
          sub_54B4D0(v21, v20, v19, v18, v14, v17);
          v13 = v22;
          result = v23;
          this[69] = v14;
          *((_DWORD *)this + 65) = v13;
          *((_DWORD *)this + 66) = result;
          return result;
        }
      }
      else
      {
        v14 = v14 - v9;
      }
LABEL_23:
      (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 44))(this, 1);
      goto LABEL_24;
    }
    v16 = sqrt(this[68] * this[68]) * 0.00019999999 * (1.0 - this[67] * 0.33333334);
    v11 = v15 * 0.5;
    if ( this[68] <= 20.0 || this[67] >= 3.0 )
    {
      if ( this[68] <= 0.0 )
      {
LABEL_18:
        if ( this[68] >= -20.0 || this[67] >= 3.0 )
        {
          if ( this[68] < 0.0 )
            v14 = v11 + v14;
        }
        else
        {
          v14 = v11 + v16 + v14;
        }
        goto LABEL_23;
      }
      v12 = v14 - v11;
    }
    else
    {
      v12 = v14 - (v16 + v11);
    }
    v14 = v12;
    goto LABEL_18;
  }
  return result;
}

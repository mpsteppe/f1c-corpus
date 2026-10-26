int __thiscall sub_466350(float *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // ecx
  double v5; // st7
  int v6; // ecx
  char v7; // al
  float v8; // edx
  double v9; // st6
  bool v10; // c0
  bool v11; // c3
  double v12; // st6
  float v13; // ecx
  int v14; // edx
  int v15; // eax
  float v16; // edx
  float v17; // [esp+0h] [ebp-38h]
  float v18; // [esp+8h] [ebp-30h]
  int v19; // [esp+10h] [ebp-28h] BYREF
  int v20; // [esp+14h] [ebp-24h] BYREF
  float v21; // [esp+18h] [ebp-20h] BYREF
  float v22; // [esp+1Ch] [ebp-1Ch]
  int v23; // [esp+20h] [ebp-18h] BYREF
  int v24; // [esp+24h] [ebp-14h] BYREF
  int v25; // [esp+28h] [ebp-10h] BYREF
  int v26; // [esp+2Ch] [ebp-Ch] BYREF
  int v27; // [esp+30h] [ebp-8h] BYREF
  int v28; // [esp+34h] [ebp-4h]

  result = *((_DWORD *)this + 59);
  if ( result )
  {
    v3 = *((_DWORD *)this + 16);
    v25 = 0;
    *(float *)&v20 = 0.0;
    v21 = 0.0;
    *(float *)&v19 = 0.0;
    v24 = 0;
    v23 = 0;
    FloatFieldAccessor(v3);
    DualFieldRead(&v27, &v26);
    v4 = *((_DWORD *)this + 66);
    v28 = v27 - *((_DWORD *)this + 65);
    LODWORD(v22) = v26 - v4;
    TwoCallDelegation_2420(&v25, &v20, &v21, &v19, &v24, &v23);
    v5 = this[72];
    v6 = *((int *)this + 70);
    v19 = *((int *)this + 72);
    v7 = *((_BYTE *)this + 245);
    v8 = this[71];
    v20 = v6;
    v21 = v8;
    if ( v7 )
    {
      if ( *((_BYTE *)this + 244) && dword_7D0398 )
      {
        v18 = -((double)SLODWORD(v22) * 0.0074999998);
        v17 = (double)v28 * 0.0074999998;
        OffsetDispatch(v17, 0.0, v18);
        v5 = *(float *)&v19;
      }
      else
      {
        this[62] = this[62] - (double)SLODWORD(v22) * 0.025;
        if ( dword_7D0398 )
        {
          v22 = this[63] + this[63];
          v12 = this[64] * 0.1;
          if ( v12 <= this[62] )
          {
            if ( this[62] > (double)v22 )
              this[62] = v22;
          }
          else
          {
            this[62] = v12;
          }
        }
        else
        {
          v9 = this[64];
          v10 = v9 < this[62];
          v11 = v9 == this[62];
          v22 = this[63];
          if ( v10 || v11 )
          {
            if ( this[62] > (double)v22 )
              this[62] = v22;
          }
          else
          {
            this[62] = v9;
          }
        }
      }
      goto LABEL_27;
    }
    if ( *((_BYTE *)this + 244) )
    {
      v5 = v5 - (double)SLODWORD(v22) * 0.0055;
      *(float *)&v19 = v5;
      if ( dword_7D0398 )
      {
        if ( v5 > 6.2831855 )
        {
          do
            v5 = v5 - 6.2831855;
          while ( v5 > 6.2831855 );
          *(float *)&v19 = v5;
        }
        if ( v5 >= -6.2831855 )
          goto LABEL_27;
        do
          v5 = v5 + 6.2831855;
        while ( v5 < -6.2831855 );
        goto LABEL_26;
      }
      if ( v5 < -1.5707964 )
      {
        v5 = -1.5707964;
LABEL_26:
        *(float *)&v19 = v5;
        goto LABEL_27;
      }
      if ( v5 > 1.5707964 )
      {
        v5 = 1.5707964;
        goto LABEL_26;
      }
    }
LABEL_27:
    *(float *)&v20 = sin(v5) * this[62];
    v21 = cos(v5) * this[62];
    UtilityFunction_1cd0(v25, v20, v21, v19, v24, v23);
    v13 = v21;
    v14 = v19;
    this[70] = *(float *)&v20;
    v15 = v26;
    this[71] = v13;
    *((_DWORD *)this + 72) = v14;
    v16 = *this;
    *((_DWORD *)this + 66) = v15;
    return (*(int (__thiscall **)(float *, int))(LODWORD(v16) + 44))(this, 1);
  }
  return result;
}


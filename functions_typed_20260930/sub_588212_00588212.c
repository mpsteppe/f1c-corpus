// local variable allocation has failed, the output may be wrong!
double __usercall sub_588212@<st0>(int a1@<eax>, double a2@<st1>, int a3, int a4, int a5, int a6)
{
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  char v10; // zf
  double result; // st7
  char v12; // cl
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  unsigned __int8 v17; // cl
  unsigned __int8 v18; // ch
  char v19; // cl
  double *v20; // [esp+10h] [ebp-7Ch]
  double *v21; // [esp+10h] [ebp-7Ch]
  double v22[14]; // [esp+14h] [ebp-78h] BYREF
  int v23; // [esp+88h] [ebp-4h]

  v6 = a1;
  v23 = a1;
  if ( (_WORD)a1 != 639 )
    sub_58DCB5();
  v7 = v6 & 0x7FF00000;
  if ( v7 == 2146435072 )
  {
    if ( a5 | a1 & 0xFFFFF )
    {
      v9 = FloadWithFBFloatLoadWithNaNCheck(0, &a3);
      if ( (a6 & 0x80000) != 0 )
        goto LABEL_15;
      v14 = v13 + 1;
    }
    else
    {
      v9 = FloadWithFBFloatLoadWithNaNCheck(0, &a3);
    }
LABEL_21:
    if ( (a4 & 0x7FF00000) != 0x7FF00000 || !(a3 | a4 & 0xFFFFF) )
    {
      if ( !v14 )
      {
        v20 = v22;
        __asm { fsave   byte ptr [ecx+8] }
        v15 = sub_58DE2C(a2, v9, v22);
        _ECX = v21;
        __asm { frstor  byte ptr [ecx+8] }
        result = *v21;
        if ( !v15 )
          return result;
        goto LABEL_11;
      }
      goto LABEL_17;
    }
    if ( (a4 & 0x80000) == 0 )
    {
LABEL_17:
      result = v9 + a2;
      goto LABEL_11;
    }
LABEL_15:
    result = v9 + a2;
    goto LABEL_11;
  }
  v9 = FloadWithFBFloatLoadWithNaNCheck(v7, &a3);
  if ( v10 )
  {
    v14 = 0;
    goto LABEL_21;
  }
  if ( (v8 & 0x7FF00000) != 0 || a3 | a4 & 0xFFFFF )
  {
    if ( a4 >= 0 || (FloatRoundednessCheck(v9), a2 = -a2, v19) )
    {
      result = X87FPExponentiation(__FYL2X__(a2, v9));
      if ( v12 == 1 )
        result = -result;
      if ( !dword_8D3E40 )
        sub_58DD89(&off_5E63B8, 29);
      return result;
    }
    result = *(double *)&tbyte_5E6C50;
LABEL_11:
    if ( !dword_8D3E40 )
      CRTFloatPassthroughWrapper();
    return result;
  }
  if ( (a6 & 0x7FF00000) == 0 )
  {
    if ( a5 | a6 & 0xFFFFF )
      return 0.0;
    else
      return 1.0;
  }
  FloatRoundednessCheck(v9);
  v18 = HIBYTE(a4) >> 7;
  if ( a6 < 0 )
  {
    result = *(double *)&tbyte_5E6BF0;
    if ( (v17 & v18) != 0 )
      result = -*(double *)&tbyte_5E6BF0;
    goto LABEL_11;
  }
  result = 0.0;
  if ( (v17 & v18) != 0 )
    return -0.0;
  return result;
}


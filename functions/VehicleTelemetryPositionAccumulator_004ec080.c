int __thiscall sub_4EC080(char *this, float *a2)
{
  double v2; // st7
  int v4; // edi
  int result; // eax
  _DWORD *v6; // esi
  float v7; // [esp+8h] [ebp-30h]
  float v8; // [esp+Ch] [ebp-2Ch]
  float v9; // [esp+10h] [ebp-28h]
  float v10; // [esp+14h] [ebp-24h] BYREF
  float v11; // [esp+18h] [ebp-20h]
  float v12; // [esp+1Ch] [ebp-1Ch]
  double v13[3]; // [esp+20h] [ebp-18h] BYREF

  v2 = a2[2];
  v7 = v2 * a2[11];
  v4 = (int)(this + 1764);
  v8 = v2 * a2[12];
  v9 = v2 * a2[13];
  *((float *)this + 3381) = v7 + *((float *)this + 3381);
  *((float *)this + 3382) = v8 + *((float *)this + 3382);
  *((float *)this + 3383) = v9 + *((float *)this + 3383);
  F_3x3MatrixTransform((_DWORD *)this + 441, (float *)this + 3381, (_DWORD *)this + 3384, this + 13488);
  FieldReadDelegate(v4);
  result = *((_DWORD *)this + 3247);
  if ( result )
  {
    if ( result == 2 )
    {
      result = ConditionalStridePointerComputation(dword_7CD25C, *(_DWORD *)(*(_DWORD *)this + 18580));
      if ( result )
      {
        v6 = (_DWORD *)(result + 8);
        ArithmeticComparison_2420((_DWORD *)(result + 8), &v10, (float *)v13);
        v10 = v10 + v7;
        v11 = v11 + v8;
        v12 = v12 + v9;
        return sub_4B2310(v6, &v10, (float *)v13);
      }
    }
  }
  else
  {
    v13[0] = v7;
    v13[1] = v8;
    v13[2] = v9;
    return RigidBodyTransformUpdate(&dbl_7C7428, v13);
  }
  return result;
}

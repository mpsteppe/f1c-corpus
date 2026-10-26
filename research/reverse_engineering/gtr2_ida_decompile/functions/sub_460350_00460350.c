int __thiscall sub_460350(float *this)
{
  int result; // eax
  long double v3; // st7

  result = sub_409B30();
  if ( (_BYTE)result && dword_B640C0 == 5 )
  {
    this[9] = 0.0;
    this[10] = 0.0;
    return result;
  }
  if ( !*(_DWORD *)this )
  {
    result = (dword_B698E8 & 1) != 0 && (byte_B699EC[*((_DWORD *)this + 1)] & 2) != 0;
    goto LABEL_11;
  }
  if ( *(_DWORD *)this == 1 )
  {
    result = *(_DWORD *)(*((_DWORD *)this + 7) + 16);
LABEL_11:
    *((_DWORD *)this + 9) = result;
    if ( result )
      this[10] = 1.0;
    else
      this[10] = 0.0;
    return result;
  }
  result = *(_DWORD *)this - 2;
  if ( *(_DWORD *)this == 2 )
  {
    v3 = fabs(*(float *)(*((_DWORD *)this + 8) + 4));
    this[10] = v3;
    if ( v3 <= 0.5 )
    {
      result = 0;
      this[9] = 0.0;
    }
    else
    {
      result = 1;
      *((_DWORD *)this + 9) = 1;
    }
  }
  return result;
}

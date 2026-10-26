_DWORD *__thiscall sub_51E5E0(_DWORD *this)
{
  float *v2; // esi
  _DWORD *result; // eax
  bool v4; // zf

  v2 = (float *)this[4];
  if ( v2 )
  {
    sub_51CC50();
    sub_51CD50(v2);
    sub_51CEC0();
  }
  result = (_DWORD *)*this;
  v4 = *this == 0;
  this[2] = *this;
  if ( !v4 )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      if ( result[5] )
        sub_5E8460(2, (unsigned __int64)(flt_BE1190 * 255.0));
      result = (_DWORD *)this[2];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[2] = result;
      if ( !result )
        break;
    }
  }
  return result;
}

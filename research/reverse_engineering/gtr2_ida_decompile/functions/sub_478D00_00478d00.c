unsigned __int8 *__thiscall sub_478D00(unsigned __int8 *this, unsigned __int8 *a2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v3; // bl
  unsigned __int8 *result; // eax
  unsigned __int8 v5; // cl
  bool v6; // cf

  v2 = *a2;
  v3 = this[23];
  result = this + 20;
  v5 = this[22];
  v6 = *a2 < v5;
  *result = *a2;
  if ( v6 )
  {
    *result = v5;
  }
  else if ( v2 > v3 )
  {
    *result = v3;
  }
  return result;
}

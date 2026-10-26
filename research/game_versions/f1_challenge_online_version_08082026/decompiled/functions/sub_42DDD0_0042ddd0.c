void *__thiscall sub_42DDD0(_DWORD *this)
{
  void *v2; // eax
  void *result; // eax

  v2 = (void *)this[1];
  *this = 0;
  if ( v2 )
    sub_587BCF(v2);
  result = (void *)this[3];
  this[1] = 0;
  this[2] = 0;
  if ( result )
    result = (void *)sub_587BCF(result);
  this[3] = 0;
  return result;
}

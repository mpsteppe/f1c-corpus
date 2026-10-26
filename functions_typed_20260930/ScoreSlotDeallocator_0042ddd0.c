void *__thiscall sub_42DDD0(_DWORD *this)
{
  void *v2; // eax
  void *result; // eax

  v2 = (void *)this[1];
  *this = 0;
  if ( v2 )
    FreeWrapper_7bcf(v2);
  result = (void *)this[3];
  this[1] = 0;
  this[2] = 0;
  if ( result )
    result = (void *)FreeWrapper_7bcf(result);
  this[3] = 0;
  return result;
}


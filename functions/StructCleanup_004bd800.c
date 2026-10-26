void *__thiscall sub_4BD800(LPVOID *this)
{
  void *v2; // eax
  void *result; // eax

  if ( this[2] )
    FreeWrapper_7bcf(this[2]);
  v2 = this[5];
  this[2] = 0;
  *this = 0;
  this[1] = 0;
  if ( v2 )
    FreeWrapper_7bcf(v2);
  result = this[8];
  this[5] = 0;
  this[3] = 0;
  this[4] = 0;
  if ( result )
    result = (void *)FreeWrapper_7bcf(result);
  this[8] = 0;
  this[6] = 0;
  this[7] = 0;
  return result;
}

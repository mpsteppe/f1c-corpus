void *__thiscall sub_4DFFF0(LPVOID *this)
{
  void *v2; // eax
  void *result; // eax

  if ( this[2] )
    sub_5BE8AE(this[2]);
  v2 = this[5];
  this[2] = 0;
  *this = 0;
  this[1] = 0;
  if ( v2 )
    sub_5BE8AE(v2);
  result = this[8];
  this[5] = 0;
  this[3] = 0;
  this[4] = 0;
  if ( result )
    result = (void *)sub_5BE8AE(result);
  this[8] = 0;
  this[6] = 0;
  this[7] = 0;
  return result;
}

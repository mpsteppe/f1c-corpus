int __thiscall sub_5E87D0(_DWORD *this)
{
  void *v2; // eax
  int result; // eax

  v2 = (void *)this[53];
  --this[51];
  if ( v2 )
    j__free(v2);
  result = this[51];
  this[53] = 0;
  this[52] = 0;
  if ( result > 0 )
  {
    result = (int)operator new(4 * result + 4);
    this[53] = result;
  }
  return result;
}

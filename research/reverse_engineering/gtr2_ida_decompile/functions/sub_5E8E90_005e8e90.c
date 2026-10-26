int __thiscall sub_5E8E90(_DWORD *this)
{
  int v2; // edx
  void *v3; // eax
  int result; // eax

  v2 = this[51];
  ++this[54];
  v3 = (void *)this[53];
  this[51] = v2 + 1;
  if ( v3 )
    j__free(v3);
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

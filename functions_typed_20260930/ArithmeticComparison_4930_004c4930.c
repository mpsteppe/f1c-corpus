int __thiscall ArithmeticComparison_4930(void **this)
{
  int result; // eax
  LPVOID *i; // esi
  LPVOID *v4; // edi
  bool v5; // zf
  void *v6; // ebp

  result = SceneListCleanup(this);
  for ( i = (LPVOID *)this[2]; i; result = FreeWrapper_7bcf(v4) )
  {
    v4 = i;
    v5 = *((_BYTE *)i + 8) == 0;
    i = (LPVOID *)i[1];
    if ( !v5 )
      FreeWrapper_7bcf(*v4);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  v6 = *this;
  if ( v6 )
    return FreeWrapper_7bcf(v6);
  return result;
}


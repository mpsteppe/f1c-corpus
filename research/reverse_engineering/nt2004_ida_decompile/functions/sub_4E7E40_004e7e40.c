int __thiscall sub_4E7E40(void **this)
{
  int result; // eax
  LPVOID *i; // esi
  LPVOID *v4; // edi
  bool v5; // zf
  void *v6; // ebp

  result = sub_4E8200();
  for ( i = (LPVOID *)this[2]; i; result = sub_5BE8AE(v4) )
  {
    v4 = i;
    v5 = *((_BYTE *)i + 8) == 0;
    i = (LPVOID *)i[1];
    if ( !v5 )
      sub_5BE8AE(*v4);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  v6 = *this;
  if ( v6 )
    return sub_5BE8AE(v6);
  return result;
}

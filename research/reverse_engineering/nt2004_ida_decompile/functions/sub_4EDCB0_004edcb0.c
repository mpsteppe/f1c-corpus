int __thiscall sub_4EDCB0(void **this)
{
  _DWORD *i; // esi
  _DWORD *v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax
  _DWORD *j; // esi
  _DWORD *v8; // ebp
  char v9; // al
  LPVOID *v10; // edi
  void *v11; // ebx

  for ( i = this[6]; i; result = sub_5BE8AE(v3) )
  {
    v3 = i;
    v4 = *((_BYTE *)i + 8);
    i = (_DWORD *)i[1];
    if ( v4 )
    {
      v5 = (LPVOID *)*v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
    }
  }
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  for ( j = this[2]; j; result = sub_5BE8AE(v8) )
  {
    v8 = j;
    v9 = *((_BYTE *)j + 8);
    j = (_DWORD *)j[1];
    if ( v9 )
    {
      v10 = (LPVOID *)*v8;
      if ( *v8 )
      {
        if ( *v10 )
          sub_5BE8AE(*v10);
        sub_5BE8AE(v10);
      }
    }
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  v11 = *this;
  if ( v11 )
    return sub_5BE8AE(v11);
  return result;
}

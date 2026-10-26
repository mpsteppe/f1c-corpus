int __thiscall sub_40EB10(void **this)
{
  _DWORD *i; // esi
  _DWORD *v3; // edi
  char v4; // al
  void *v5; // ebx
  int result; // eax
  void *v7; // ecx
  _DWORD *j; // esi
  _DWORD *v9; // edi
  char v10; // al
  void *v11; // ebx
  void *v12; // ebp

  for ( i = this[3]; i; result = sub_5BE8AE(v3) )
  {
    v3 = i;
    v4 = *((_BYTE *)i + 8);
    i = (_DWORD *)i[1];
    if ( v4 )
    {
      v5 = (void *)*v3;
      if ( *v3 )
      {
        sub_413DD0(*v3);
        sub_5BE8AE(v5);
      }
    }
  }
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  v7 = this[7];
  if ( v7 )
    result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)v7 + 48))(v7, 1);
  for ( j = this[3]; j; result = sub_5BE8AE(v9) )
  {
    v9 = j;
    v10 = *((_BYTE *)j + 8);
    j = (_DWORD *)j[1];
    if ( v10 )
    {
      v11 = (void *)*v9;
      if ( *v9 )
      {
        sub_413DD0(*v9);
        sub_5BE8AE(v11);
      }
    }
  }
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  v12 = *this;
  if ( v12 )
    return sub_5BE8AE(v12);
  return result;
}

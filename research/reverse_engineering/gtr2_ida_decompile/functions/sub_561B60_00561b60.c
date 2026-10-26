int __thiscall sub_561B60(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // ebx
  int (__thiscall ***v9)(_DWORD, int); // ecx
  int (__thiscall ***v10)(_DWORD, int); // ecx
  int (__thiscall ***v11)(_DWORD, int); // ecx
  int (__thiscall ***v12)(_DWORD, int); // ecx

  v2 = this + 6;
  v3 = 25;
  do
  {
    if ( *v2 )
    {
      result = (**(int (__thiscall ***)(_DWORD, int))*v2)(*v2, 1);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v5 = this + 31;
  v6 = 3;
  do
  {
    if ( *v5 )
    {
      result = (**(int (__thiscall ***)(_DWORD, int))*v5)(*v5, 1);
      *v5 = 0;
    }
    ++v5;
    --v6;
  }
  while ( v6 );
  v7 = this + 3;
  v8 = 3;
  do
  {
    if ( *v7 )
    {
      result = (**(int (__thiscall ***)(_DWORD, int))*v7)(*v7, 1);
      *v7 = 0;
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  v9 = (int (__thiscall ***)(_DWORD, int))this[56];
  if ( v9 )
  {
    result = (**v9)(v9, 1);
    this[56] = 0;
  }
  v10 = (int (__thiscall ***)(_DWORD, int))this[59];
  if ( v10 )
  {
    result = (**v10)(v10, 1);
    this[59] = 0;
  }
  v11 = (int (__thiscall ***)(_DWORD, int))this[57];
  if ( v11 )
  {
    result = (**v11)(v11, 1);
    this[57] = 0;
  }
  v12 = (int (__thiscall ***)(_DWORD, int))this[58];
  if ( v12 )
  {
    result = (**v12)(v12, 1);
    this[58] = 0;
  }
  return result;
}

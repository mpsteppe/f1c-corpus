int __thiscall sub_5021C0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi
  int result; // eax
  _DWORD *v5; // esi
  int v6; // edi
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // ecx
  int (__thiscall ***v10)(_DWORD, int); // ecx

  v2 = this + 9;
  v3 = 5;
  do
  {
    if ( *v2 )
    {
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 12))(*v2);
      if ( *v2 )
        result = (**(int (__thiscall ***)(_DWORD, int))*v2)(*v2, 1);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v5 = this + 14;
  v6 = 3;
  do
  {
    if ( *v5 )
    {
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v5 + 12))(*v5);
      if ( *v5 )
        result = (**(int (__thiscall ***)(_DWORD, int))*v5)(*v5, 1);
      *v5 = 0;
    }
    ++v5;
    --v6;
  }
  while ( v6 );
  v7 = this + 7;
  v8 = 2;
  do
  {
    if ( *v7 )
    {
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v7 + 12))(*v7);
      if ( *v7 )
        result = (**(int (__thiscall ***)(_DWORD, int))*v7)(*v7, 1);
      *v7 = 0;
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  v9 = this[17];
  if ( v9 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 12))(v9);
    v10 = (int (__thiscall ***)(_DWORD, int))this[17];
    if ( v10 )
      result = (**v10)(v10, 1);
    this[17] = 0;
  }
  return result;
}

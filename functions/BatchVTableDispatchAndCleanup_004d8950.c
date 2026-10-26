int __thiscall sub_4D8950(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi
  int result; // eax
  _DWORD *v5; // esi
  int v6; // edi
  int (__thiscall ***v7)(_DWORD, int); // ecx
  int (__thiscall ***v8)(_DWORD, int); // ecx

  v2 = this + 4;
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
  v5 = this + 29;
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
  v7 = (int (__thiscall ***)(_DWORD, int))this[3];
  if ( v7 )
  {
    result = (**v7)(v7, 1);
    this[3] = 0;
  }
  v8 = (int (__thiscall ***)(_DWORD, int))this[54];
  if ( v8 )
  {
    result = (**v8)(v8, 1);
    this[54] = 0;
  }
  return result;
}

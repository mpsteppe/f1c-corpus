int __thiscall VirtualDispatchHelper(_DWORD *this)
{
  int result; // eax
  int v2; // ecx

  result = this[10];
  if ( !result )
  {
    v2 = this[2];
    if ( v2 )
      return (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 24))(v2);
    else
      return 0;
  }
  return result;
}

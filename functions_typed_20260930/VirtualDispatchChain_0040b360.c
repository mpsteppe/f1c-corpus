int __thiscall VirtualDispatchChain(void *this)
{
  int result; // eax
  int v3; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
  if ( result )
  {
    v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
    return (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(v3);
  }
  return result;
}


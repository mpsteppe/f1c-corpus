char __thiscall sub_52D8D0(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax

  if ( !*this )
  {
    if ( OperatorNewNhMallocWrapper(11584) )
      v5 = RenderObjectConstructor_e170(a2, a3);
    else
      v5 = 0;
    *this = v5;
    if ( (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v5 + 4))(v5, 0, a4) != -1 )
      return 1;
    VirtualCleanup(this);
  }
  return 0;
}


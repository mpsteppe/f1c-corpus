char __thiscall StateChangeHandlerWithSubscriberNotification(int this, int a2)
{
  int v3; // eax
  char v4; // al
  _DWORD *v5; // esi

  if ( (_BYTE)a2 != ByteFieldGetterAt100((_BYTE *)this) )
    (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(1);
  StateChangeNotification((_BYTE *)this, a2);
  if ( (_BYTE)a2 )
  {
    LOBYTE(v3) = (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 64))(this, 4);
  }
  else
  {
    v4 = RangeCheck((_DWORD *)this);
    LOBYTE(v3) = ConditionalStateMachineDispatch((_DWORD *)this, v4);
  }
  v5 = *(_DWORD **)(this + 144);
  if ( v5 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD *, int))(*v5 + 56))(v5, a2);
      v3 = StructFieldAccessor(v5);
      v5 = (_DWORD *)v3;
    }
    while ( v3 );
  }
  return v3;
}


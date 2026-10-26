char __thiscall sub_49DB60(_DWORD *this, int a2)
{
  unsigned int ExecutionResourceId; // eax
  char v4; // al
  Concurrency::details::VirtualProcessor *v5; // esi

  sub_49D150((int)this, a2);
  if ( (_BYTE)a2 )
  {
    LOBYTE(ExecutionResourceId) = (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
  }
  else
  {
    v4 = sub_49D9A0(this);
    LOBYTE(ExecutionResourceId) = sub_49DA90(this, v4);
  }
  v5 = (Concurrency::details::VirtualProcessor *)this[36];
  if ( v5 )
  {
    do
    {
      (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *, int))(*(_DWORD *)v5 + 36))(v5, a2);
      ExecutionResourceId = Concurrency::details::VirtualProcessor::GetExecutionResourceId(v5);
      v5 = (Concurrency::details::VirtualProcessor *)ExecutionResourceId;
    }
    while ( ExecutionResourceId );
  }
  return ExecutionResourceId;
}

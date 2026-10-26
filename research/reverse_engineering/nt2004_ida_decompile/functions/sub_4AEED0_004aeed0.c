int __thiscall sub_4AEED0(_DWORD *this)
{
  int v2; // esi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  Concurrency::details::VirtualProcessor *ExecutionResourceId; // esi
  Concurrency::details::VirtualProcessor *v5; // ebx

  v2 = this[15];
  for ( *this = &off_5EA264; v2; this[15] = v2 )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))this[15];
    v2 = *(_DWORD *)(v2 + 56);
    if ( v3 )
      (**v3)(v3, 1);
  }
  ExecutionResourceId = (Concurrency::details::VirtualProcessor *)sub_4AF0A0(this);
  while ( ExecutionResourceId )
  {
    v5 = ExecutionResourceId;
    ExecutionResourceId = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(ExecutionResourceId);
    if ( v5 )
      (**(void (__thiscall ***)(Concurrency::details::VirtualProcessor *, int))v5)(v5, 1);
  }
  return sub_4B13D0(this);
}

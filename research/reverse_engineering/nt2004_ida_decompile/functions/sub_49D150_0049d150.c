void __thiscall sub_49D150(int this, int a2)
{
  Concurrency::details::VirtualProcessor *ExecutionResourceId; // esi

  ExecutionResourceId = *(Concurrency::details::VirtualProcessor **)(this + 144);
  for ( *(_BYTE *)(this + 100) = a2;
        ExecutionResourceId;
        ExecutionResourceId = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(ExecutionResourceId) )
  {
    (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *, int))(*(_DWORD *)ExecutionResourceId + 36))(
      ExecutionResourceId,
      a2);
  }
}

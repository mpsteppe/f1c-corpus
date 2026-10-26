_DWORD *__thiscall sub_4AF5C0(void *this, _DWORD *a2)
{
  int i; // esi
  Concurrency::details::VirtualProcessor *ExecutionResourceId; // edi
  int v4; // eax

  for ( i = (int)this; sub_4AF450((_DWORD *)i); i = sub_4AF450((_DWORD *)i) )
    ;
  a2[39] = i;
  sub_49D3D0(a2, *(_DWORD *)(i + 12), *(_DWORD *)(i + 4));
  ExecutionResourceId = *(Concurrency::details::VirtualProcessor **)(i + 52);
  if ( ExecutionResourceId )
  {
    if ( Concurrency::details::VirtualProcessor::GetExecutionResourceId(*(Concurrency::details::VirtualProcessor **)(i + 52)) )
    {
      do
        ExecutionResourceId = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(ExecutionResourceId);
      while ( Concurrency::details::VirtualProcessor::GetExecutionResourceId(ExecutionResourceId) );
    }
    sub_49CA30(ExecutionResourceId, (int)a2);
    ++*(_DWORD *)(i + 72);
    return a2;
  }
  else
  {
    v4 = *(_DWORD *)(i + 72) + 1;
    *(_DWORD *)(i + 52) = a2;
    *(_DWORD *)(i + 72) = v4;
    return a2;
  }
}

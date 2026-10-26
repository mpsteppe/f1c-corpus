int __thiscall sub_4AF1A0(_DWORD *this)
{
  Concurrency::details::VirtualProcessor *ExecutionResourceId; // esi
  Concurrency::details::VirtualProcessor *v3; // esi
  Concurrency::details::VirtualProcessor *i; // esi
  char v6; // [esp+8h] [ebp-4h]

  if ( !this[21] )
    return 0;
  ExecutionResourceId = (Concurrency::details::VirtualProcessor *)this[16];
  v6 = 1;
  if ( ExecutionResourceId )
  {
    while ( !(*(unsigned __int8 (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)ExecutionResourceId
                                                                                         + 120))(ExecutionResourceId) )
    {
      ExecutionResourceId = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(ExecutionResourceId);
      if ( !ExecutionResourceId )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = *(Concurrency::details::VirtualProcessor **)(this[17] + 52);
    if ( !v3 )
      goto LABEL_10;
    while ( !(*(unsigned __int8 (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)v3 + 120))(v3) )
    {
      v3 = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(v3);
      if ( !v3 )
        goto LABEL_10;
    }
  }
  v6 = 0;
LABEL_10:
  sub_4AF650(v6);
  for ( i = (Concurrency::details::VirtualProcessor *)this[16];
        i;
        i = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(i) )
  {
    (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)i + 48))(i);
  }
  return 0;
}

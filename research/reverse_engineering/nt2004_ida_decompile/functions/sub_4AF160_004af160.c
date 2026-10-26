char __thiscall sub_4AF160(int this)
{
  char result; // al
  Concurrency::details::VirtualProcessor *i; // esi

  result = *(_BYTE *)(this + 56);
  if ( result )
  {
    for ( i = *(Concurrency::details::VirtualProcessor **)(this + 64);
          i;
          i = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(i) )
    {
      (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)i + 92))(i);
    }
    result = sub_4AF730(*(_DWORD *)(this + 68));
    *(_BYTE *)(this + 56) = 0;
  }
  return result;
}

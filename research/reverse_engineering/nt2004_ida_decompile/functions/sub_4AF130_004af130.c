int __thiscall sub_4AF130(_DWORD *this)
{
  Concurrency::details::VirtualProcessor *i; // esi
  int v3; // esi
  int result; // eax
  Concurrency::details::VirtualProcessor *v5; // esi

  for ( i = (Concurrency::details::VirtualProcessor *)this[16];
        i;
        i = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(i) )
  {
    (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)i + 96))(i);
  }
  v3 = this[17];
  for ( result = sub_4AF450(v3); result; result = sub_4AF450(v3) )
    v3 = sub_4AF450(v3);
  v5 = *(Concurrency::details::VirtualProcessor **)(v3 + 52);
  if ( v5 )
  {
    do
    {
      (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)v5 + 96))(v5);
      result = Concurrency::details::VirtualProcessor::GetExecutionResourceId(v5);
      v5 = (Concurrency::details::VirtualProcessor *)result;
    }
    while ( result );
  }
  return result;
}

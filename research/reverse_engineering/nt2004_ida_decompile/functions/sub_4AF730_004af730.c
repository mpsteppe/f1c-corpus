int __thiscall sub_4AF730(_DWORD *this)
{
  _DWORD *v1; // esi
  int result; // eax
  Concurrency::details::VirtualProcessor *v3; // esi

  v1 = this;
  for ( result = sub_4AF450(this); result; result = sub_4AF450(v1) )
    v1 = (_DWORD *)sub_4AF450(v1);
  v3 = (Concurrency::details::VirtualProcessor *)v1[13];
  if ( v3 )
  {
    do
    {
      (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)v3 + 92))(v3);
      result = Concurrency::details::VirtualProcessor::GetExecutionResourceId(v3);
      v3 = (Concurrency::details::VirtualProcessor *)result;
    }
    while ( result );
  }
  return result;
}

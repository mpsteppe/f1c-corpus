char *__thiscall sub_4AD7C0(_DWORD *this)
{
  char *result; // eax
  int v3; // esi
  Concurrency::details::VirtualProcessor *v4; // esi

  result = (char *)sub_4AD7F0(this);
  if ( result )
  {
    result = (char *)sub_4AD490(this, result);
    if ( result )
    {
      v3 = (int)result;
      for ( result = (char *)sub_4AF450(result); result; result = (char *)sub_4AF450(v3) )
        v3 = sub_4AF450(v3);
      v4 = *(Concurrency::details::VirtualProcessor **)(v3 + 52);
      if ( v4 )
      {
        do
        {
          (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)v4 + 96))(v4);
          result = (char *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(v4);
          v4 = (Concurrency::details::VirtualProcessor *)result;
        }
        while ( result );
      }
    }
  }
  return result;
}

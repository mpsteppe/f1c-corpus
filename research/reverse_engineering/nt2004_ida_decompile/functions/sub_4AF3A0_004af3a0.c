int __thiscall sub_4AF3A0(void *this)
{
  int v2; // ecx
  LPVOID *v3; // esi
  Concurrency::details::VirtualProcessor *i; // esi
  unsigned int ExecutionResourceId; // eax
  void (__thiscall ***v6)(_DWORD, int); // ecx

  v2 = *((_DWORD *)this + 16);
  *(_DWORD *)this = &off_5EA2B4;
  if ( v2 )
  {
    sub_4AFEE0(v2);
    v3 = (LPVOID *)*((_DWORD *)this + 16);
    if ( v3 )
    {
      sub_4AFEE0(*((_DWORD *)this + 16));
      if ( v3[5] )
        sub_5BE8AE(v3[5]);
      if ( v3[1] )
        sub_5BE8AE(v3[1]);
      sub_5BE8AE(v3);
    }
  }
  for ( i = (Concurrency::details::VirtualProcessor *)*((_DWORD *)this + 13); i; *((_DWORD *)this + 13) = i )
  {
    ExecutionResourceId = Concurrency::details::VirtualProcessor::GetExecutionResourceId(i);
    v6 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 13);
    i = (Concurrency::details::VirtualProcessor *)ExecutionResourceId;
    if ( v6 )
      (**v6)(v6, 1);
  }
  if ( *((_DWORD *)this + 23) )
    sub_5BE8AE(*((LPVOID *)this + 23));
  if ( *((_DWORD *)this + 21) )
    sub_5BE8AE(*((LPVOID *)this + 21));
  if ( *((_DWORD *)this + 19) )
    sub_5BE8AE(*((LPVOID *)this + 19));
  return sub_4B13D0(this);
}

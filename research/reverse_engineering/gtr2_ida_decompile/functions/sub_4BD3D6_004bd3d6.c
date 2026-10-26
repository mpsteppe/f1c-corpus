int __usercall sub_4BD3D6@<eax>(int a1@<ebx>, void *a2@<esi>)
{
  void (__stdcall *v2)(int); // eax

  if ( a2 != (void *)__readfsdword(0) )
    _global_unwind2(a2);
  if ( a2 )
  {
    if ( _rt_probe_read4(a1 + 32) && *(_DWORD *)(a1 + 32) == 1447244336 )
    {
      v2 = *(void (__stdcall **)(int))(a1 + 36);
      if ( v2 )
        v2(a1);
    }
    else
    {
      _local_unwind2(a2, *(_DWORD *)(a1 + 28));
    }
  }
  _NLG_Notify(0);
  return (*(int (**)(void))(a1 + 20))();
}

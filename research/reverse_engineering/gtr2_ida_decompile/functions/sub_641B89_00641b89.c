void __usercall sub_641B89(int a1@<ebp>)
{
  if ( *(_DWORD *)(a1 - 28) )
    _unlock_fhandle(*(_DWORD *)(a1 - 32));
}

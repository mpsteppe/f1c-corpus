void __usercall sub_641BDE(int a1@<ebp>)
{
  if ( *(_DWORD *)(a1 - 28) )
    _unlock_fhandle(*(_DWORD *)(a1 - 32));
}

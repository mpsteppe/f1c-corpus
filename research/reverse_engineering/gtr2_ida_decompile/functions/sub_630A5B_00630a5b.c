void __usercall sub_630A5B(int a1@<ebp>)
{
  if ( !*(_DWORD *)(a1 - 32) )
    __ArrayUnwind(
      *(void **)(a1 + 8),
      *(_DWORD *)(a1 + 12),
      *(_DWORD *)(a1 - 28),
      *(void (__thiscall **)(void *))(a1 + 24));
}

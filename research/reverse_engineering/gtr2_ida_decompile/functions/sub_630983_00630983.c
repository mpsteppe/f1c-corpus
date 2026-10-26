void __usercall sub_630983(int a1@<ebp>)
{
  if ( !*(_DWORD *)(a1 - 28) )
    __ArrayUnwind(
      *(void **)(a1 + 8),
      *(_DWORD *)(a1 + 12),
      *(_DWORD *)(a1 + 16),
      *(void (__thiscall **)(void *))(a1 + 20));
}

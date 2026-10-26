int __usercall sub_489CC6@<eax>(int a1@<eax>, int a2)
{
  if ( a1 != *(_DWORD *)dword_16C9A50 )
    a1 = __updatetlocinfo();
  if ( *(int *)(a1 + 40) <= 1 )
    return *(_WORD *)(*(_DWORD *)(a1 + 72) + 2 * a2) & 0x103;
  else
    return __isctype_mt(a1, a2, 259);
}

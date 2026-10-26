int __stdcall sub_677204(int a1, const void *a2, _DWORD *a3)
{
  *a3 = 0;
  if ( memcmp(a2, &unk_749318, 0x10u) && memcmp(a2, &unk_73CCB4, 0x10u) )
    return -2147467262;
  *a3 = a1;
  (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 4))(a1);
  return 0;
}

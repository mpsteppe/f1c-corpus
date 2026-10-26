int __fastcall sub_5BD940(int a1, int a2, __int16 a3)
{
  int v5; // edi
  void *v6; // esi
  int v8; // [esp+10h] [ebp-4h]

  v5 = 0;
  v8 = sub_577650(*(void **)(a1 + 4));
  if ( v8 <= 0 )
    return -1;
  while ( 1 )
  {
    v6 = *(void **)sub_5BE1B0(*(_DWORD *)(a1 + 4), v5);
    if ( sub_577650(v6) == a2
      && Concurrency::details::HardwareAffinity::GetGroup((Concurrency::details::HardwareAffinity *)v6) == a3 )
    {
      break;
    }
    if ( ++v5 >= v8 )
      return -1;
  }
  return v5;
}

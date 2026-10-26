int __fastcall sub_563E80(int a1, int a2)
{
  if ( a2 < 0 || a2 >= sub_563E70(*(void **)(a1 + 4)) )
    return 0;
  else
    return *(_DWORD *)LinearInterpolation(*(_DWORD *)(a1 + 4), a2);
}

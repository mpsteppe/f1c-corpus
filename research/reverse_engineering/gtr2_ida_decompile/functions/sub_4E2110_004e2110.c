void __usercall sub_4E2110(int a1@<ecx>, __int32 a2@<ebx>)
{
  int v3; // eax
  int v4; // [esp+0h] [ebp-14h]

  *(_DWORD *)a1 = &off_712F74;
  v3 = *(_DWORD *)(a1 + 260);
  if ( v3 )
  {
    sub_5F0DA0(v3);
    *(_DWORD *)(a1 + 260) = 0;
  }
  sub_4D5D40((int *)(a1 + 1400));
  sub_4E0E20((int *)(a1 + 1384));
  sub_4E2A20(a1 + 1380);
  sub_4DB510((char *)(a1 + 592));
  `eh vector destructor iterator'((void *)(a1 + 508), 0xCu, 4, (void (__thiscall *)(void *))sub_498720);
  if ( *(_DWORD *)(a1 + 372) )
    j_j__free(*(void **)(a1 + 372));
  sub_4E0DC0((int *)(a1 + 348));
  sub_41ED50((int *)(a1 + 312));
  sub_4729E0(a2, v4);
  if ( *(_DWORD *)(a1 + 56) )
    j_j__free(*(void **)(a1 + 56));
  sub_4D5D40((int *)(a1 + 4));
}

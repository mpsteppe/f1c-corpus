int __stdcall sub_56A9E0(void **a1)
{
  int v1; // eax
  int v2; // esi
  int v4; // eax
  int v5; // eax

  v1 = sub_575D30(*a1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 4))(v1);
  nullsub_6(*a1);
  v2 = dword_7E05EC;
  if ( !dword_7E05EC )
    return 1;
  while ( *(void ***)v2 != a1 )
  {
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v2 )
      return 1;
  }
  if ( v2 == dword_7E05F4 )
    dword_7E05F4 = *(_DWORD *)(v2 + 4);
  v4 = *(_DWORD *)(v2 + 8);
  if ( v4 )
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(v2 + 4);
  else
    dword_7E05EC = *(_DWORD *)(v2 + 4);
  v5 = *(_DWORD *)(v2 + 4);
  if ( v5 )
    *(_DWORD *)(v5 + 8) = *(_DWORD *)(v2 + 8);
  if ( dword_7E05F0 == v2 )
    dword_7E05F0 = *(_DWORD *)(v2 + 8);
  --dword_7E05F8;
  if ( *(_BYTE *)(v2 + 12) )
  {
    if ( *(_DWORD *)v2 )
    {
      sub_56A1F0(*(_DWORD **)v2);
      sub_5BE8AE();
    }
  }
  sub_5BE8AE();
  return 0;
}

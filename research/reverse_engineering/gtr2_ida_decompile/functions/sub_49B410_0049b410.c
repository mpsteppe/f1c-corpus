int __usercall sub_49B410@<eax>(int a1@<ecx>, int a2@<ebp>)
{
  int v3; // esi
  int i; // ebp
  int v5; // eax
  const char *v6; // edx

  v3 = *(_DWORD *)(a1 + 600);
  if ( v3 != sub_48C270() || v3 != dword_757C10 )
  {
    sub_4D0AC0(a2);
    for ( i = 0; i < 104; ++i )
    {
      if ( *(_BYTE *)(a1 + 596) )
        v5 = dword_B6D970[i];
      else
        v5 = dword_B6D7D0[i];
      if ( v5 < 0 )
        break;
      v6 = (char *)&unk_9204A0 + 22616 * v5 + 108 * *((_DWORD *)&unk_9204A0 + 5654 * v5 + 5447) + 21568;
      if ( strlen(v6) )
      {
        sub_4D93B0(v6, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      }
      else
      {
        sub_48C2F0();
        --i;
      }
    }
    *(_DWORD *)(a1 + 600) = sub_48C270();
  }
  return 0;
}

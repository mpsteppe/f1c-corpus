int __fastcall sub_5B9DF0(int a1, const char *a2, int hostshort, int a4, int a5, int a6)
{
  int v8; // eax
  int v9; // ebx
  int result; // eax
  u_short v11; // [esp-4h] [ebp-18h]
  u_short v12; // [esp-4h] [ebp-18h]

  *(_DWORD *)(a1 + 1548) = 1;
  if ( a4 )
  {
    v12 = htons(hostshort);
    inet_addr(a2);
    result = sub_5BC930(v12);
  }
  else
  {
    v11 = htons(hostshort);
    inet_addr(a2);
    v8 = sub_5BD940(v11);
    if ( v8 == -1 )
    {
      v9 = sub_5BBD50(a1, a2, hostshort, 1, a6 != 0);
    }
    else
    {
      v9 = sub_5BDA10(a1 + 72, v8);
      sub_5BBB80(1, a6 != 0);
    }
    sub_5BD910(a1 + 72, v9);
    result = 0;
  }
  if ( !a5 && !result )
  {
    *(_DWORD *)(a1 + 1552) = inet_addr(a2);
    *(_WORD *)(a1 + 1556) = htons(hostshort);
    result = sub_5B9EE0(a1, a4);
  }
  *(_DWORD *)(a1 + 1548) = 0;
  return result;
}

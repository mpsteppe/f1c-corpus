_DWORD *__fastcall sub_5BBD50(int a1, const char *a2, u_short hostshort, int a4, int a5)
{
  unsigned int v6; // esi
  u_short v7; // ax
  _DWORD *v8; // esi

  v6 = inet_addr(a2);
  v7 = htons(hostshort);
  v8 = sub_5BA500(0, v6, v7);
  *((_BYTE *)v8 + 21) = 1;
  sub_5BBB80(a1, (int)v8, a4, a5);
  return v8;
}

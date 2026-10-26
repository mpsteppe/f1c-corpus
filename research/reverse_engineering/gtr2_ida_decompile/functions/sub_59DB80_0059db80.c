char __thiscall sub_59DB80(struct in_addr *this, int a2, int a3)
{
  char *v4; // eax

  htonl(0);
  htons(0);
  v4 = inet_ntoa(this[681]);
  if ( !v4 )
    return 0;
  sub_630FE0(a2, v4, a3 - 1);
  *(_BYTE *)(a3 - 1 + a2) = 0;
  return 1;
}

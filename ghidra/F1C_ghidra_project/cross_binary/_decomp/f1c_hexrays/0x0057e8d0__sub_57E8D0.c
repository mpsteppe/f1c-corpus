// f1c  0x0057e8d0  size=107
char __thiscall sub_57E8D0(_DWORD *this, int a2, int a3)
{
  char *v4; // eax
  int v6; // [esp+8h] [ebp-10h] BYREF
  struct in_addr in; // [esp+Ch] [ebp-Ch]

  in = (struct in_addr)htonl(0);
  htons(0);
  sub_57B9F0(this + 673, &v6);
  v4 = inet_ntoa(in);
  if ( !v4 )
    return 0;
  sub_587DD0(a2, v4, a3 - 1);
  *(_BYTE *)(a3 - 1 + a2) = 0;
  return 1;
}

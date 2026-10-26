char __thiscall sub_56E910(_DWORD *this, char *Destination, int a3)
{
  char *v4; // eax
  int v6; // [esp+8h] [ebp-10h] BYREF
  struct in_addr in; // [esp+Ch] [ebp-Ch]

  in = (struct in_addr)htonl(0);
  htons(0);
  sub_56B5E0(this + 673, &v6);
  v4 = inet_ntoa(in);
  if ( !v4 )
    return 0;
  strncpy(Destination, v4, a3 - 1);
  Destination[a3 - 1] = 0;
  return 1;
}

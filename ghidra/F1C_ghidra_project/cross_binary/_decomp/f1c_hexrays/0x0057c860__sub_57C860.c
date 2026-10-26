// f1c  0x0057c860  size=117
char __stdcall sub_57C860(SOCKET s, int optval)
{
  char v2; // al
  SOCKET v3; // esi

  v2 = optval;
  v3 = s;
  optval = 1;
  if ( v2 )
  {
    setsockopt(s, 6, 1, (const char *)&optval, 4);
    s = 1;
    setsockopt(v3, 0xFFFF, 8, (const char *)&s, 4);
  }
  else
  {
    setsockopt(s, 0xFFFF, 32, (const char *)&optval, 4);
  }
  WSAAsyncSelect(v3, dword_8D3E28, 0x1A0Au, 63);
  return 1;
}

// f1c  0x00598672  size=6
// attributes: thunk
int __stdcall sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen)
{
  return __imp_sendto(s, buf, len, flags, to, tolen);
}

// f1c  0x00598684  size=6
// attributes: thunk
int __stdcall recv(SOCKET s, char *buf, int len, int flags)
{
  return __imp_recv(s, buf, len, flags);
}

// attributes: thunk
int __stdcall recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
  return __imp_recvfrom(s, buf, len, flags, from, fromlen);
}

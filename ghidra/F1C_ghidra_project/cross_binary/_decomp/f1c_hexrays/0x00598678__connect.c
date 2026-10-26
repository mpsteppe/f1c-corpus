// f1c  0x00598678  size=6
// attributes: thunk
int __stdcall connect(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp_connect(s, name, namelen);
}

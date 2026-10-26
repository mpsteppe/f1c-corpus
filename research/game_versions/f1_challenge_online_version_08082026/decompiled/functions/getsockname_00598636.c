// attributes: thunk
int __stdcall getsockname(SOCKET s, struct sockaddr *name, int *namelen)
{
  return __imp_getsockname(s, name, namelen);
}

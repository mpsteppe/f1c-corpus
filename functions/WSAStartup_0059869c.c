// attributes: thunk
int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData)
{
  return __imp_WSAStartup(wVersionRequested, lpWSAData);
}

// f1c  0x0059868a  size=6
// attributes: thunk
int __stdcall setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen)
{
  return __imp_setsockopt(s, level, optname, optval, optlen);
}

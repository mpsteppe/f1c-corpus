// attributes: thunk
struct hostent *__stdcall gethostbyname(const char *name)
{
  return __imp_gethostbyname(name);
}

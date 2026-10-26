// attributes: thunk
int __stdcall gethostname(char *name, int namelen)
{
  return __imp_gethostname(name, namelen);
}

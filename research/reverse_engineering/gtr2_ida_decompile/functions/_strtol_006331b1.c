int __cdecl strtol(const char *String, char **EndPtr, int Radix)
{
  return strtoxl((char *)String, EndPtr, Radix, 0);
}

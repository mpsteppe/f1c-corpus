unsigned int __cdecl strtoul(const char *String, char **EndPtr, int Radix)
{
  return strtoxl((char *)String, EndPtr, Radix, 1);
}

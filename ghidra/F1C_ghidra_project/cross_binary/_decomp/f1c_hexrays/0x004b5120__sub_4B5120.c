// f1c  0x004b5120  size=179
bool __thiscall sub_4B5120(const char *this, int a2)
{
  const char *v3; // ecx

  v3 = (const char *)(a2 + 18196 + strlen((const char *)(a2 + 18196)));
  if ( (unsigned int)v3 > a2 + 18196 )
  {
    while ( *v3 != 92 )
    {
      if ( (unsigned int)--v3 <= a2 + 18196 )
        return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 17952));
    }
    ++v3;
  }
  return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 17952));
}

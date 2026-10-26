bool __thiscall sub_4D47D0(const char *this, int a2)
{
  const char *v3; // ecx

  v3 = (const char *)(a2 + 24992 + strlen((const char *)(a2 + 24992)));
  if ( (unsigned int)v3 > a2 + 24992 )
  {
    while ( *v3 != 92 )
    {
      if ( (unsigned int)--v3 <= a2 + 24992 )
        return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 24772));
    }
    ++v3;
  }
  return !strcmp(this + 65, v3) && !strcmp(this + 1, (const char *)(a2 + 24772));
}

int __thiscall TeammatePitStatusLookup(F1CPitMachine *this)
{
  int *vehicle; // edx
  int v2; // esi
  int v3; // eax
  int *v4; // ecx

  vehicle = (int *)this->vehicle;
  v2 = *((_DWORD *)this->vehicle + 4649);
  v3 = 0;
  if ( dword_5C329C <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = (int *)*(&dword_7C54F0 + v3);
    if ( v4[4649] == v2 && v4 != vehicle )
      break;
    if ( ++v3 >= dword_5C329C )
      return 0;
  }
  return v4[3348];
}


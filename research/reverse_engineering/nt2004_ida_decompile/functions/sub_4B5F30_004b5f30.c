int __thiscall sub_4B5F30(char *this, char *Str)
{
  char *v2; // esi

  v2 = this + 12;
  if ( sub_5A29F0((int)(this + 12), Str, 0, 0, 0, 0, 2052, 1) )
    *(_DWORD *)v2 = 0;
  return *(_DWORD *)v2;
}

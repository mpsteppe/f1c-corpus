char *__thiscall sub_431E40(int this, char *Source)
{
  char *v2; // esi

  v2 = (char *)(this + 12);
  if ( sub_41F230((_DWORD *)this, Source, (char *)(this + 12)) )
  {
    if ( Source )
    {
      strncpy(v2, Source, 0x1FFu);
      v2[511] = 0;
      return v2;
    }
    *v2 = 0;
  }
  return v2;
}

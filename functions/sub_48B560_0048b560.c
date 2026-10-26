char __thiscall sub_48B560(int this, unsigned __int8 a2)
{
  if ( CharacterClassificationQuery(a2) )
  {
    if ( *(_DWORD *)(this + 744) == 1 )
    {
      if ( a2 != 92 && a2 != 47 && a2 != 58 && a2 != 46 && (a2 != 32 || strlen(*(const char **)(this + 752))) )
        return 1;
    }
    else
    {
      if ( *(_DWORD *)(this + 744) != 2 )
        return 1;
      if ( sub_589B9E(a2) || sub_589B70(a2) || a2 == 46 || a2 == 58 )
        return 1;
    }
  }
  return 0;
}

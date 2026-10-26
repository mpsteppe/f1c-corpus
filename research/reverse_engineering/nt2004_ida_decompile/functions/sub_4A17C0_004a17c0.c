char __thiscall sub_4A17C0(int this, unsigned __int8 a2)
{
  if ( a2 >= 0x20u && a2 <= 0xFCu && a2 != 124 )
  {
    if ( *(_DWORD *)(this + 788) == 1 )
    {
      if ( a2 != 92 && a2 != 47 && a2 != 58 && a2 != 46 && (a2 != 32 || strlen(*(const char **)(this + 796))) )
        return 1;
    }
    else
    {
      if ( *(_DWORD *)(this + 788) != 2 )
        return 1;
      if ( isdigit(a2) || isalpha(a2) || a2 == 46 || a2 == 58 )
        return 1;
    }
  }
  return 0;
}

int __thiscall sub_438330(char **this, int a2)
{
  int result; // eax

  result = 0;
  if ( dword_757C10 > 0 )
  {
    while ( *(_DWORD *)(*(&dword_91E088 + result) + 22468) != a2 )
    {
      if ( ++result >= dword_757C10 )
        return result;
    }
    return sub_438180(this, result);
  }
  return result;
}

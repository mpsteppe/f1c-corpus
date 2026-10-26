int __thiscall sub_4365F0(const char **this, int a2)
{
  int result; // eax

  result = 0;
  if ( (int)NumOfElements > 0 )
  {
    while ( *(_DWORD *)(dword_75AAD0[result] + 25248) != a2 )
    {
      if ( ++result >= (int)NumOfElements )
        return result;
    }
    return sub_436470(this, result);
  }
  return result;
}

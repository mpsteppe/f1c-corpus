char __thiscall sub_4FAE50(_DWORD *this, int a2)
{
  char result; // al
  int v3; // edx

  result = 0;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 20884) == 1 )
    {
      v3 = this[298];
      if ( *(_DWORD *)(a2 + 20848) >= v3 && v3 < this[36] )
      {
        result = 1;
        this[298] = v3 + 1;
      }
    }
  }
  return result;
}

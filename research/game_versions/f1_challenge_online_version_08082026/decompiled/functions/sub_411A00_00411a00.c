int __stdcall sub_411A00(int a1, int a2)
{
  int result; // eax

  result = sub_4144C0(a1);
  if ( result != 9875 && result != 9876 )
  {
    if ( result >= 0 )
    {
      if ( !a2 )
        return word_5BEBB0[result];
      if ( a2 == 1 )
        return word_5BF2F8[result];
    }
    return -1;
  }
  return result;
}

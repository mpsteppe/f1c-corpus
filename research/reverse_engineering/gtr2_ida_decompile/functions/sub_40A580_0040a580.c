int __stdcall sub_40A580(int a1)
{
  int result; // eax

  if ( a1 )
  {
    result = a1 - 1;
    if ( a1 == 1 )
    {
      AIL_set_preference(42, 50);
      return AIL_serve();
    }
  }
  else
  {
    AIL_set_preference(42, 8);
    return AIL_serve();
  }
  return result;
}

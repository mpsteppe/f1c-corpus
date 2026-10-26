int __stdcall sub_49F6A0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int result; // eax

  if ( a1 )
  {
    if ( a4 )
    {
      v6 = a5;
      if ( a5 )
      {
        if ( a6 == 1 )
        {
          SubtractionWithGuard(a1, a2, &a2, a4);
        }
        else if ( a6 == 2 )
        {
          CenterCalc(a1, a2, &a2, a4);
        }
        return sub_553070(a1, a2, a3, v6);
      }
    }
  }
  return result;
}

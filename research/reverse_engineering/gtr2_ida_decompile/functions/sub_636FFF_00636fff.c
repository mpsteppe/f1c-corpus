void __cdecl sub_636FFF(int a1, int a2)
{
  if ( a1 >= 20 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    sub_636C06(a1 + 16);
}

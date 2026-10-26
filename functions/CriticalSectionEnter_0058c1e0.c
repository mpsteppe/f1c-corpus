void __cdecl sub_58C1E0(int a1, int a2)
{
  if ( a1 >= 20 )
    EnterCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    CriticalSectionLazyInitEnter(a1 + 28);
}

void __cdecl sub_636FD0(unsigned int a1)
{
  if ( a1 < (unsigned int)&off_912DD0 || a1 > (unsigned int)&stru_913030 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 32));
  else
    sub_636C06(((int)(a1 - (_DWORD)&off_912DD0) >> 5) + 16);
}

// f1c  0x0058c232  size=35
void __cdecl sub_58C232(int a1, int a2)
{
  if ( a1 >= 20 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  else
    sub_58E04B(a1 + 28);
}

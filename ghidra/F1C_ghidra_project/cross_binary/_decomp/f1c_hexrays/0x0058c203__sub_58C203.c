// f1c  0x0058c203  size=47
void __cdecl sub_58C203(unsigned int a1)
{
  if ( a1 < (unsigned int)&off_5E6748 || a1 > (unsigned int)&unk_5E69A8 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 32));
  else
    sub_58E04B(((int)(a1 - (_DWORD)&off_5E6748) >> 5) + 28);
}

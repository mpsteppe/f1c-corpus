int __cdecl sub_518BD4(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int result; // eax

  v3 = *(_DWORD *)(a1 + 88);
  if ( (v3 & 1) != 0 && (v3 & 4) != 0 || (result = GuardedCallWithLongjmp(a1, (int)"No image in file"), a2) )
  {
    *(_DWORD *)(a1 + 88) |= 0x18u;
    if ( a3 )
      CallbackDispatch(a1, (int)"Incorrect IEND chunk length");
    return sub_518828(a1, a3);
  }
  return result;
}


// f1c  0x00512114  size=26
int __cdecl sub_512114(int a1, int a2, int a3)
{
  if ( a1 && a2 )
    return a3 & *(_DWORD *)(a2 + 8);
  else
    return 0;
}

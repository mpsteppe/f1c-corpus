// f1c  0x004cefa0  size=53
int __userpurge sub_4CEFA0@<eax>(int a1@<ecx>, double a2@<st0>, int a3, int a4, int a5)
{
  int v5; // edx
  int result; // eax
  int i; // ecx

  v5 = *(_DWORD *)(a1 + 16);
  result = 0;
  if ( v5 > 0 )
  {
    for ( i = *(_DWORD *)(a1 + 20); *(_DWORD *)(i + 4) != a3; i += 108 )
    {
      if ( ++result >= v5 )
        return result;
    }
    return sub_4CD6C0(i, a2, a4, a5);
  }
  return result;
}

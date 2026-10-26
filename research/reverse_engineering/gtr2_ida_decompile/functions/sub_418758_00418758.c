// positive sp value has been detected, the output may be wrong!
int __userpurge sub_418758@<eax>(int a1@<ecx>, int a2@<esi>, int a3, int a4)
{
  int result; // eax
  int v5; // edi

  if ( *(_DWORD *)(a4 + 14804) != 1
    || *(_DWORD *)(a1 + 14804) != 1
    || (result = dword_91E230 / dword_91C000, !(dword_91E230 % dword_91C000)) )
  {
    v5 = *(_DWORD *)(a1 + 2696);
    sub_5EDA00(1, 0);
    sub_5767B0(a4, *(_DWORD *)(a2 + 36) + 15996);
    sub_5ED820(v5, 1);
    return sub_5EDA00(0, 0);
  }
  return result;
}

int __userpurge sub_59B4C0@<eax>(int *a1@<ecx>, int a2@<esi>, int a3)
{
  int v3; // esi
  int result; // eax

  v3 = *a1;
  result = sub_5A7230(*a1 + 316, a2);
  if ( a3 <= result )
    *(_DWORD *)(v3 + 132) = a3;
  else
    *(_DWORD *)(v3 + 132) = result;
  return result;
}

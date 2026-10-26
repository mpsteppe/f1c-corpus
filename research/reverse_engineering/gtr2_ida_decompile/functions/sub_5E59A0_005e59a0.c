int __userpurge sub_5E59A0@<eax>(int a1@<ecx>, __int32 a2@<ebx>, int a3)
{
  int v3; // eax
  int *v5; // ecx
  int result; // eax

  v3 = *(_DWORD *)(a3 + 796);
  if ( v3 )
    v5 = (int *)(v3 + 800);
  else
    v5 = (int *)(*(_DWORD *)(a1 + 764) + 388);
  sub_5D9700(v5, a2, a3, a3, 0);
  result = sub_5FDFB0(a3, 1);
  *(_DWORD *)(a3 + 796) = a1;
  return result;
}

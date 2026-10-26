int __userpurge sub_56A480@<eax>(int *a1@<ecx>, int a2@<esi>, int a3)
{
  int v3; // esi
  int result; // eax

  v3 = *a1;
  result = sub_577930(*a1 + 300, a2);
  if ( a3 <= result )
    *(_DWORD *)(v3 + 128) = a3;
  else
    *(_DWORD *)(v3 + 128) = result;
  return result;
}

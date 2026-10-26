int __usercall sub_535010@<eax>(int a1@<ecx>, char *a2@<edi>)
{
  int *v2; // edx
  int result; // eax

  v2 = *(int **)(a1 + 4);
  *(_DWORD *)(a1 + 8) = v2;
  if ( v2 && *v2 )
    return off_16C9218();
  result = 0;
  *(_DWORD *)(a1 + 8) = v2;
  if ( v2 )
  {
    if ( *v2 )
      return sub_533F30(*v2, a2, -1);
  }
  return result;
}

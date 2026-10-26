int __usercall sub_4FB770@<eax>(int a1@<ecx>, int a2@<ebx>, float a3@<edi>)
{
  int *v4; // ecx
  int result; // eax
  int *v6; // ecx

  v4 = *(int **)(a1 + 12);
  if ( v4 )
    result = sub_4FA820(v4, a2, a3);
  v6 = *(int **)(a1 + 16);
  if ( v6 )
    return sub_4FA820(v6, a2, a3);
  return result;
}

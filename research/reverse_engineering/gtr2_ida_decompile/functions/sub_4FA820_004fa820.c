int __usercall sub_4FA820@<eax>(int *a1@<ecx>, int a2@<ebx>, float a3@<edi>)
{
  int result; // eax
  int v5; // edi
  int v6; // ebx

  result = a1[75];
  if ( result )
  {
    sub_4FA6A0(a1, a2, a3);
    result = a1[72];
    v5 = 0;
    if ( result > 0 )
    {
      v6 = 0;
      do
      {
        sub_4F3330((void *)(v6 + a1[73]));
        result = a1[72];
        ++v5;
        v6 += 768;
      }
      while ( v5 < result );
    }
  }
  return result;
}

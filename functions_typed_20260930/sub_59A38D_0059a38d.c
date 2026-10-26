void *__userpurge sub_59A38D@<eax>(void *a1@<ecx>, int a2@<ebp>, char a3)
{
  CDestructorWithVTableChain(a2);
  if ( (a3 & 1) != 0 )
    FreeWrapper_7bcf(a1);
  return a1;
}


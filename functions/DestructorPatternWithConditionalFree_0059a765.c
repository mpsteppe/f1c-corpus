void *__userpurge sub_59A765@<eax>(void *a1@<ecx>, int a2@<ebp>, char a3)
{
  ExceptionCleanupWithDestructorCall(a2);
  if ( (a3 & 1) != 0 )
    FreeWrapper_7bcf(a1);
  return a1;
}

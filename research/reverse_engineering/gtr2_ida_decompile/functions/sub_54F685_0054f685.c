void *__usercall sub_54F685@<eax>(char a1@<cf>, char a2@<al>, int a3@<ebx>, int a4@<edi>, size_t a5)
{
  int v5; // ebx

  v5 = a3 + 1;
  if ( a2 == a1 + 78 )
    return operator new(a5);
  else
    return *(void **)(v5 - 1 + a4);
}

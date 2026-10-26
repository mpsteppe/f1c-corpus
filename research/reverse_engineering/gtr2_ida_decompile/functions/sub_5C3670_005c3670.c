// positive sp value has been detected, the output may be wrong!
void *__userpurge sub_5C3670@<eax>(void *a1@<ecx>, int a2@<esi>, char a3)
{
  int v6; // [esp-8h] [ebp-8h]

  sub_5C35E0(a2, v6);
  if ( (a3 & 1) != 0 )
    j__free(a1);
  return a1;
}

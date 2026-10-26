char *__usercall _shift@<eax>(char *result@<eax>, int a2@<edi>)
{
  char *v2; // esi
  int v3; // eax

  v2 = result;
  if ( a2 )
  {
    v3 = sub_6354D0((int)result);
    return (char *)memcpy(&v2[a2], v2, v3 + 1);
  }
  return result;
}

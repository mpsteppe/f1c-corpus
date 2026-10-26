void *__stdcall sub_67A7B7(void **a1, void **a2)
{
  void *v2; // edi
  void *result; // eax

  v2 = 0;
  if ( a1 )
    v2 = *a1;
  if ( a2 )
  {
    result = *a2;
    if ( *a2 )
    {
      result = (void *)sub_6B7251(*a2);
      *a2 = 0;
    }
  }
  if ( v2 )
  {
    sub_67A404((int)v2);
    result = (void *)sub_6B7251(v2);
    *a1 = 0;
  }
  return result;
}

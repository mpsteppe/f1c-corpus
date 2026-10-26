int *__stdcall sub_615C10(int *a1, int *a2)
{
  int *v2; // esi
  int *v3; // edi
  int *v4; // ebp
  int *v5; // ebx
  int *v6; // eax
  int *result; // eax

  v2 = a1;
  if ( !a1 )
    return a2;
  v3 = a2;
  if ( !a2 )
    return a1;
  if ( sub_615B00((void *)*a1, *a2) )
  {
    v4 = a1;
    v5 = a1;
    v2 = (int *)a1[1];
  }
  else
  {
    v4 = a2;
    v5 = a2;
    v3 = (int *)a2[1];
  }
  if ( v2 )
  {
    while ( v3 )
    {
      if ( sub_615B00((void *)*v2, *v3) )
      {
        v6 = v2;
        v2 = (int *)v2[1];
      }
      else
      {
        v6 = v3;
        v3 = (int *)v3[1];
      }
      v5[1] = (int)v6;
      v5 = v6;
      if ( !v2 )
        goto LABEL_12;
    }
    result = v4;
    v5[1] = (int)v2;
  }
  else
  {
LABEL_12:
    result = v4;
    if ( v3 )
      v5[1] = (int)v3;
    else
      v5[1] = 0;
  }
  return result;
}

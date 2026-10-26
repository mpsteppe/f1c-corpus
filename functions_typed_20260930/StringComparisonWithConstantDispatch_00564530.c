int __fastcall sub_564530(__int16 *a1, const char *a2, int a3)
{
  int *v4; // eax

  if ( !strcmp(a2, aPing) )
    return ShortToIntFieldGetter(a1);
  v4 = DoubleCallWrapper((int)a1, (int)a2);
  if ( v4 )
    return SingleFunctionCallWrapper_7f59(v4[1]);
  else
    return a3;
}


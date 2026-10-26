int __stdcall sub_53CB20(int *a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax
  void *v6; // esi

  v4 = sub_587C03(60);
  if ( v4 )
    v5 = sub_5426A0(v4);
  else
    v5 = 0;
  *a1 = v5;
  if ( !sub_5429B0(a2, 0, 0, a3, a4) )
    return 0;
  v6 = (void *)*a1;
  if ( *a1 )
  {
    j_nullsub_3(v6);
    sub_587BCF(v6);
  }
  return -1;
}

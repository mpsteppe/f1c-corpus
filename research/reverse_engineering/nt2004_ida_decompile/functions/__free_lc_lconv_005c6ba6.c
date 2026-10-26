void __cdecl _free_lc_lconv(LPVOID *a1)
{
  if ( a1 )
  {
    if ( a1[3] != &unk_7FF47C )
    {
      sub_5C1B88(a1[3]);
      sub_5C1B88(a1[4]);
      sub_5C1B88(a1[5]);
      sub_5C1B88(a1[6]);
      sub_5C1B88(a1[7]);
      sub_5C1B88(a1[8]);
      sub_5C1B88(a1[9]);
    }
  }
}

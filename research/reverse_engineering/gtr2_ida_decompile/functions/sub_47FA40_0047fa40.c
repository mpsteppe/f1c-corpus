char sub_47FA40()
{
  int v0; // esi

  v0 = dword_757C10;
  if ( *(int *)dword_B640C8 > 0 )
  {
    if ( *(int *)dword_B640C8 <= 5 )
    {
      if ( dbl_FB1D18 > flt_FADE20 && dword_757C10 > 0 )
        return 1;
    }
    else if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      return sub_551D70(&unk_FADD40);
    }
  }
  return !sub_4737F0(&dword_B6CBA8) && !v0;
}

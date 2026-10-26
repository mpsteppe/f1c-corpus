char sub_469460()
{
  size_t v0; // esi

  v0 = NumOfElements;
  if ( dword_75CBB0 > 0 )
  {
    if ( dword_75CBB0 <= 6 )
    {
      if ( dbl_7DA9D0 > flt_7D74C0 && (int)NumOfElements > 0 )
        return 1;
    }
    else if ( dword_75CBB0 == 7 )
    {
      return sub_4FB240(&unk_7D7428);
    }
  }
  return !sub_464400(dword_764D70) && !v0;
}

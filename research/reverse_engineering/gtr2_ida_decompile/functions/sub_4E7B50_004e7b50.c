char __thiscall sub_4E7B50(_BYTE *this)
{
  char result; // al

  result = byte_B6F118;
  if ( !byte_B6F118 )
  {
    if ( dword_B6B9E0 )
      this[17] = this[17] == 0;
    result = this[17];
    if ( result )
    {
      if ( flt_757718 > 0.0 )
        sub_40D560(&flt_757718);
      sub_472930((float **)&dword_B6CB98, 4);
      sub_410B50(&dword_91BF20);
      sub_410A80(&dword_91BF20);
      return off_16C9278();
    }
  }
  return result;
}

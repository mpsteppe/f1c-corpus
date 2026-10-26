int sub_4D8960()
{
  int result; // eax

  if ( (dword_761FF8 & 1) == 0 )
    return 2;
  if ( byte_7621C7 )
    return 0;
  if ( (dword_761FF8 & 1) == 0 )
    return 2;
  if ( byte_7621C4 )
    return 1;
  if ( (dword_761FF8 & 1) == 0 )
    return 2;
  if ( byte_7621CC )
    return 3;
  if ( (dword_761FF8 & 1) == 0 )
    return 2;
  result = 4;
  if ( !byte_7621C9 )
    return 2;
  return result;
}

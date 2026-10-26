int __stdcall sub_53A250(char *String1)
{
  if ( sub_616840("SeasonRaces") )
  {
    if ( String1 )
      return sub_616630(String1);
    if ( dword_BE1CD8 )
      return sub_616630((char *)(dword_BE1CD8 + 396 * dword_BE1CD4 + 260));
  }
  return 0;
}

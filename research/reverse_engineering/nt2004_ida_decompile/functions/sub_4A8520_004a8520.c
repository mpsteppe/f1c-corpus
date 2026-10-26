int __thiscall sub_4A8520(_DWORD *this)
{
  int v2; // edi

  v2 = 1;
  if ( sub_4A84A0(this) )
  {
    while ( !strstr(Str, asc_608AB8) && sub_4A84A0(this) )
      ;
  }
  do
  {
    if ( !sub_4A84A0(this) )
      break;
    if ( strstr(Str, asc_608AB8) )
      ++v2;
    if ( strstr(Str, asc_608AB4) )
      --v2;
  }
  while ( v2 >= 1 );
  --this[119];
  return 0;
}

int __thiscall sub_4DAD10(_DWORD *this)
{
  int v2; // edi

  v2 = 1;
  if ( sub_4DAC90(this) )
  {
    while ( !strstr(byte_75AF70, "{") && sub_4DAC90(this) )
      ;
  }
  do
  {
    if ( !sub_4DAC90(this) )
      break;
    if ( strstr(byte_75AF70, "{") )
      ++v2;
    if ( strstr(byte_75AF70, "}") )
      --v2;
  }
  while ( v2 >= 1 );
  --this[190];
  return 0;
}

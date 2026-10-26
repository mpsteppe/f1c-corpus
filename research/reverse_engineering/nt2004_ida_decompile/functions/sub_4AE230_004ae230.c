int __thiscall sub_4AE230(_DWORD **this, char *Source, _DWORD *a3, _DWORD *a4)
{
  char *v6; // eax

  *a3 = 0;
  *a4 = 0;
  if ( !Source )
    return -1;
  if ( this[92] )
  {
    if ( sub_41F230(dword_62A170, Source, Destination) )
    {
      strncpy(Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    v6 = (char *)*this[92];
    if ( !v6 )
      v6 = &byte_629120;
    sub_4AE370(v6, (int)Destination, (int)a3, (int)a4);
  }
  return 0;
}

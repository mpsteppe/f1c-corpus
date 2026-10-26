int __thiscall sub_4ADFB0(_DWORD **this, char *Source, int a3, int a4, int a5, int a6)
{
  const char *v6; // ebx
  char *v9; // eax
  char *v10; // edx
  int v11; // [esp+8h] [ebp-4h] BYREF

  v6 = Source;
  if ( !Source )
    return -1;
  if ( this[92] )
  {
    if ( sub_41F230(dword_62A170, Source, Destination) )
    {
      strncpy(Destination, v6, 0x1FFu);
      byte_62A37B = 0;
    }
    v9 = (char *)*this[92];
    if ( !v9 )
      v9 = &byte_629120;
    sub_4AE370(v9, (int)Destination, (int)&v11, (int)&Source);
    v10 = (char *)*this[92];
    if ( !v10 )
      v10 = &byte_629120;
    sub_4AE3F0(v10, (int)v6, a5 + (a6 - a5) / 2, a3 + (a4 - a3) / 2, 8);
  }
  return 0;
}

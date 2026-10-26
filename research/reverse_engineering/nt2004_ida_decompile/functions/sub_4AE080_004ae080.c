int __thiscall sub_4AE080(_DWORD **this, char *Source, int a3, int a4, int a5, int a6)
{
  const char *v6; // ebp
  char *v9; // eax
  int v10; // ecx
  char *v11; // eax
  int v12; // [esp+8h] [ebp-4h] BYREF

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
    sub_4AE370(v9, (int)Destination, (int)&v12, (int)&Source);
    if ( a4 - a3 <= (int)Source )
      v10 = a3;
    else
      v10 = a3 + (a4 - a3) / 2 - (int)Source / 2;
    v11 = (char *)*this[92];
    if ( !v11 )
      v11 = &byte_629120;
    sub_4AE3F0(v11, (int)v6, a5, v10, 0);
  }
  return 0;
}

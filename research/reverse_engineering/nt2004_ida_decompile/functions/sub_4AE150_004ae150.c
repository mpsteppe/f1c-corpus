int __thiscall sub_4AE150(_DWORD **this, char *Source, int a3, int a4, int a5, int a6)
{
  char *v8; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // [esp+8h] [ebp-8h] BYREF
  int v12; // [esp+Ch] [ebp-4h] BYREF

  if ( !Source )
    return -1;
  if ( this[92] )
  {
    if ( sub_41F230(dword_62A170, Source, Destination) )
    {
      strncpy(Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    v8 = (char *)*this[92];
    if ( !v8 )
      v8 = &byte_629120;
    sub_4AE370(v8, (int)Destination, (int)&v11, (int)&v12);
    if ( a4 - a3 <= v12 )
      v9 = a3;
    else
      v9 = a3 + (a4 - a3) / 2 - v12 / 2;
    v10 = (char *)*this[92];
    if ( !v10 )
      v10 = &byte_629120;
    sub_4AE3F0(v10, (int)Source, a6 - v11, v9, 0);
  }
  return 0;
}

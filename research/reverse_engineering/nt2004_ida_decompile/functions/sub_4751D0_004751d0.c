int __thiscall sub_4751D0(_DWORD *this)
{
  int v2; // eax
  const char *v3; // eax
  char Destination[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v6; // [esp+105h] [ebp-3h]
  char v7; // [esp+107h] [ebp-1h]

  sub_472690(this);
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0xFCu);
  v6 = 0;
  v7 = 0;
  sub_4CE010(Destination, 256);
  v2 = sub_4A50D0(this);
  if ( v2 )
  {
    v3 = *(const char **)(v2 + 64);
    if ( !v3 )
      v3 = &byte_629120;
    if ( strcmp(v3, Destination) )
      sub_475280(this);
  }
  return 0;
}

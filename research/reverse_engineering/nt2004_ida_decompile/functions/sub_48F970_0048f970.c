int __thiscall sub_48F970(_DWORD *this)
{
  char *v2; // eax
  char Destination[129]; // [esp+7h] [ebp-101h] BYREF
  char Buffer[128]; // [esp+88h] [ebp-80h] BYREF

  sub_436120((const char **)&dword_75E8F0, &Destination[1], 128, Destination);
  if ( sub_41F230(dword_62A170, aCurrentSetup_0, ::Destination) )
  {
    strncpy(::Destination, aCurrentSetup_0, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, "%s %s", ::Destination, &Destination[1]);
  sub_49EC60(Buffer);
  v2 = *(char **)(this[61] + 64);
  if ( !v2 )
    v2 = &byte_629120;
  sub_4AE350(v2);
  return 0;
}

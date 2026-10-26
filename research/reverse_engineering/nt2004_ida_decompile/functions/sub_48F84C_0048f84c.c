int __usercall sub_48F84C@<eax>(char a1@<zf>, char a2@<sf>, char a3@<of>, const char *a4@<edi>, int a5@<esi>)
{
  char Buffer[24516]; // [esp+14h] [ebp-5FC4h] BYREF

  if ( a2 ^ a3 | a1 )
    a4 = (const char *)&off_5FD8D8;
  if ( sub_41F230(dword_62A170, a4, Destination) )
  {
    if ( a4 )
    {
      strncpy(Destination, a4, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  sprintf(Buffer, "%d %s", a5, Destination);
  sub_49EC60(Buffer);
  return 0;
}

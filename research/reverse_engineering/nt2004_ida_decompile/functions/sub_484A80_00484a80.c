int __thiscall sub_484A80(_DWORD **this)
{
  const char *v1; // eax
  char Destination[64]; // [esp+4h] [ebp-40h] BYREF

  switch ( dword_76AD4C )
  {
    case 0:
      *this[210] = 0;
      break;
    case 1:
      *this[210] = 1;
      break;
    case 2:
      *this[210] = 2;
      break;
    case 3:
      *this[210] = 3;
      break;
    case 4:
      *this[210] = 4;
      break;
    default:
      break;
  }
  v1 = (const char *)sub_49D690(*this[210]);
  strncpy(Destination, v1, 0x3Fu);
  Destination[63] = 0;
  return sub_4A1AC0(Destination);
}

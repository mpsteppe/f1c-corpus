_DWORD *sub_505790()
{
  _DWORD *result; // eax

  result = operator new(0x10u);
  if ( !result )
    return 0;
  result[1] = 4;
  *((_BYTE *)result + 8) = 0;
  result[3] = 0;
  *result = &off_5EAA04;
  return result;
}

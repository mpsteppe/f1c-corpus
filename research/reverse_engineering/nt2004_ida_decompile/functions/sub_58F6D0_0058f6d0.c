_BYTE *__cdecl sub_58F6D0(_BYTE *a1)
{
  int v1; // ecx
  _BYTE *result; // eax

  v1 = 12;
  a1[97] = 0;
  a1[96] = 0;
  result = a1 + 7;
  do
  {
    *result = 0;
    result += 8;
    --v1;
  }
  while ( v1 );
  return result;
}

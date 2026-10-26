_BYTE *__stdcall sub_6B7413(_BYTE *a1, int a2)
{
  _BYTE *result; // eax

  result = a1;
  *a1 = HIBYTE(a2);
  a1[1] = BYTE2(a2);
  a1[2] = BYTE1(a2);
  a1[3] = a2;
  return result;
}

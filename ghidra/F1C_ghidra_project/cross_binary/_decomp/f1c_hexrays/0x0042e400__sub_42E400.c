// f1c  0x0042e400  size=105
_BYTE *__thiscall sub_42E400(int this)
{
  _BYTE *result; // eax
  _DWORD *v2; // esi
  _DWORD *v3; // edx

  *(_DWORD *)(this + 7356) = 1133679739;
  *(_BYTE *)(this + 7352) = 1;
  result = (_BYTE *)(this + 7380);
  v2 = (_DWORD *)(this + 7404);
  v3 = (_DWORD *)(this + 7384);
  do
  {
    *(v3 - 5) = 1133679739;
    *(result - 20) = 1;
    *v3 = 0;
    *result = 1;
    *v2 = 1135865364;
    v2[1] = 1135865364;
    v2[2] = 1135865364;
    ++v3;
    v2 += 3;
    result[20] = 1;
    ++result;
  }
  while ( (int)&result[-7380 - this] < 4 );
  return result;
}

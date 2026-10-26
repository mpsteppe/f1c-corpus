_DWORD *__thiscall sub_4E3A90(int this)
{
  _DWORD *result; // eax
  int v2; // esi

  result = (_DWORD *)(this + 224);
  v2 = 48;
  do
  {
    *(result - 48) = 0;
    *result = -1;
    result[48] = -1;
    ++result;
    --v2;
  }
  while ( v2 );
  *(_DWORD *)(this + 608) = 0;
  *(_DWORD *)(this + 612) = 0;
  *(_DWORD *)(this + 616) = 0;
  *(_DWORD *)(this + 620) = 0;
  *(_DWORD *)(this + 624) = 0;
  *(_DWORD *)(this + 632) = 0;
  *(_DWORD *)(this + 636) = -1;
  *(_BYTE *)(this + 640) = 0;
  return result;
}

_DWORD *__thiscall sub_59B260(int this, int a2, _DWORD *a3)
{
  unsigned __int8 v4; // cl
  _DWORD *result; // eax

  *(_DWORD *)(this + 4) = *(_DWORD *)a2;
  qmemcpy((void *)(this + 8), (const void *)(a2 + 4), 0x24u);
  v4 = *(_BYTE *)(a2 + 40);
  *(_BYTE *)(this + 44) = v4;
  qmemcpy((void *)(this + 45), (const void *)(a2 + 41), v4);
  result = a3;
  *a3 = v4 + 41;
  return result;
}

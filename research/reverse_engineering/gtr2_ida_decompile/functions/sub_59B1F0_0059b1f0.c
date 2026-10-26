_DWORD *__thiscall sub_59B1F0(int this, _DWORD *a2, int a3, _DWORD *a4)
{
  unsigned int v4; // ebx
  _DWORD *result; // eax

  *a2 = *(_DWORD *)(this + 4);
  qmemcpy(a2 + 1, (const void *)(this + 8), 0x25u);
  v4 = *(unsigned __int8 *)(this + 44);
  qmemcpy((char *)a2 + 41, (const void *)(this + 45), v4);
  result = a4;
  *a4 = v4 + 41;
  return result;
}

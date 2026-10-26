_DWORD *__thiscall sub_53E380(_DWORD *this, _DWORD *a2, const void *a3, _DWORD *a4, int a5, int a6)
{
  _DWORD *result; // eax
  _DWORD *v7; // ecx

  result = this;
  v7 = this + 2;
  *v7 = *a2;
  v7[1] = a2[1];
  v7[2] = a2[2];
  qmemcpy(result + 8, a3, 0x24u);
  result[17] = *a4;
  result[18] = a4[1];
  result[19] = a4[2];
  result[39] = a5;
  result[40] = a6;
  return result;
}

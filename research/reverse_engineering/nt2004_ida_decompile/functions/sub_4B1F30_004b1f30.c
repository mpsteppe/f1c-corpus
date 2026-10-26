_WORD *__thiscall sub_4B1F30(int this, _WORD *a2)
{
  __int64 v2; // rax
  _WORD *result; // eax

  v2 = (__int64)((double)*(char *)(this + 36) * ((double)dword_6152E8 * 0.00125) * 10.0
               + (double)dword_6152E8 * 0.00125 * 5.0);
  HIDWORD(v2) = *(__int16 *)(this + 26);
  *(_WORD *)(this + 20) = v2;
  result = a2;
  *(_WORD *)(this + 22) = *a2;
  *(_DWORD *)a2 += HIDWORD(v2);
  return result;
}

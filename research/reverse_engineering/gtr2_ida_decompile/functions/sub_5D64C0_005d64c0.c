_DWORD *__thiscall sub_5D64C0(_DWORD *this, int a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = (_DWORD *)(this[2] + 68 * a2);
  if ( result )
  {
    *result = *a3;
    qmemcpy(result + 1, a3 + 1, 0x40u);
  }
  return result;
}

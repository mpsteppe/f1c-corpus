_DWORD *__thiscall sub_685D41(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = *(_DWORD **)(*(_DWORD *)(this[5] + 4 * a3) + 20);
  if ( result != (_DWORD *)-1 )
    return sub_685BBE(this, a2, (int)result, a4);
  return result;
}

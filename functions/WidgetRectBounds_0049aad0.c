_DWORD *__thiscall sub_49AAD0(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *result; // eax

  if ( *(__int16 *)(this + 40) <= 0 || *(__int16 *)(this + 42) <= 0 )
  {
    *a2 = *(_DWORD *)(this + 4);
    *a3 = *(_DWORD *)(this + 8);
    result = a4;
    *a4 = *(_DWORD *)(this + 12);
    *a5 = *(_DWORD *)(this + 16);
  }
  else
  {
    *a2 = *(__int16 *)(this + 38);
    *a3 = *(__int16 *)(this + 42) + *(__int16 *)(this + 38) - 1;
    *a4 = *(__int16 *)(this + 36);
    result = a5;
    *a5 = *(__int16 *)(this + 40) + *(__int16 *)(this + 36) - 1;
  }
  return result;
}

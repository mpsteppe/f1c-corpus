char __thiscall sub_463C80(void *this, int a2, void *a3, _DWORD *a4)
{
  char result; // al

  result = 0;
  if ( a2 >= 0 && a2 < *(_DWORD *)(*(_DWORD *)this + 6512) )
  {
    qmemcpy(a3, (const void *)(116 * a2 + *(_DWORD *)this + 752), 0x74u);
    *a4 = *(_DWORD *)(*(_DWORD *)this + 4 * a2 + 6320);
    return 1;
  }
  return result;
}

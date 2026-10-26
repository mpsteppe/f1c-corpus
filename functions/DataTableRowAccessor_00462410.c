char __thiscall sub_462410(void *this, int a2, void *a3, _DWORD *a4)
{
  char result; // al

  result = 0;
  if ( a2 >= 0 && a2 < *(_DWORD *)(*(_DWORD *)this + 15892) )
  {
    qmemcpy(a3, (const void *)(140 * a2 + *(_DWORD *)this + 916), 0x8Cu);
    *a4 = *(_DWORD *)(*(_DWORD *)this + 4 * a2 + 15476);
    return 1;
  }
  return result;
}

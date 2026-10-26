int __thiscall sub_58BC80(int *this, int a2)
{
  int result; // eax
  int i; // esi

  result = *this;
  for ( i = 0; i < *this; ++i )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 4 * i) + 8))(*(_DWORD *)(a2 + 4 * i));
    result = *this;
  }
  return result;
}

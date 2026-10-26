_DWORD *__stdcall sub_6B5170(int a1)
{
  _DWORD *result; // eax

  sub_6B4F40((int *)a1);
  sub_6B50D0((int *)a1);
  (**(void (__stdcall ***)(int))(a1 + 448))(a1);
  (**(void (__stdcall ***)(int))(a1 + 432))(a1);
  result = *(_DWORD **)(a1 + 440);
  *result = *(_DWORD *)(*(_DWORD *)(a1 + 432) + 4);
  return result;
}

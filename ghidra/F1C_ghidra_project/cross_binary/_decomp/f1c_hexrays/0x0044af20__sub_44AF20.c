// f1c  0x0044af20  size=60
_DWORD *__stdcall sub_44AF20(_DWORD *a1, int a2)
{
  _DWORD *result; // eax

  *a1 = **(_DWORD **)a2;
  a1[1] = *(_DWORD *)(*(_DWORD *)a2 + 8);
  a1[2] = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 8);
  a1[3] = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 16);
  a1[4] = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16);
  result = *(_DWORD **)(a2 + 8);
  a1[5] = *result;
  return result;
}

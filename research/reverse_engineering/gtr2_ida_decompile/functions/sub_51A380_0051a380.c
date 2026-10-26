__int16 __thiscall sub_51A380(char *this, int a2)
{
  char *v2; // ecx
  __int16 result; // ax

  v2 = this + 2960;
  *(_DWORD *)v2 = *(_DWORD *)a2;
  *((_DWORD *)v2 + 1) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)v2 + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)v2 + 3) = *(_DWORD *)(a2 + 12);
  result = *(_WORD *)(a2 + 16);
  *((_WORD *)v2 + 8) = result;
  return result;
}

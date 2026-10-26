int __fastcall sub_6B8BF9(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v2 = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(a2 + 52) = 2 * *(_DWORD *)(a2 + 36);
  *(_WORD *)(v2 + 2 * *(_DWORD *)(a2 + 68) - 2) = 0;
  memset(*(void **)(a2 + 60), 0, 2 * *(_DWORD *)(a2 + 68) - 2);
  v3 = 6 * *(_DWORD *)(a2 + 124);
  *(_DWORD *)(a2 + 120) = (unsigned __int16)word_745202[v3];
  *(_DWORD *)(a2 + 132) = (unsigned __int16)word_745200[v3];
  *(_DWORD *)(a2 + 136) = (unsigned __int16)word_745204[v3];
  *(_DWORD *)(a2 + 116) = (unsigned __int16)word_745206[v3];
  result = 2;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 112) = 2;
  *(_DWORD *)(a2 + 88) = 2;
  return result;
}

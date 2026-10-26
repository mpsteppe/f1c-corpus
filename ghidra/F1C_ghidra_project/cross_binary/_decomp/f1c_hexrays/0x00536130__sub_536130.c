// f1c  0x00536130  size=41
int __fastcall sub_536130(int a1, __int16 a2)
{
  int v2; // esi
  int result; // eax

  *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = HIBYTE(a2);
  v2 = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = v2;
  *(_BYTE *)(v2 + *(_DWORD *)(a1 + 8)) = a2;
  result = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = result;
  return result;
}

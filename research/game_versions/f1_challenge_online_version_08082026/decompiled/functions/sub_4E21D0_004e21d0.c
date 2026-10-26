int __stdcall sub_4E21D0(int a1, float a2)
{
  int v2; // edi
  int v3; // ebx
  int i; // esi
  int v5; // eax
  int result; // eax

  v2 = (sub_587BDC(a2 * 254.0 + 0.5) << 24) + 0xFFFFFF;
  v3 = sub_54E100(a1);
  for ( i = 0; i < v3; *(_DWORD *)(v5 + 24) = v2 )
    v5 = sub_54E120(i++);
  result = *(_DWORD *)(a1 + 20) | 0x10000000;
  *(_DWORD *)(a1 + 20) = result;
  return result;
}

int __stdcall sub_6D5E80(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  int v3; // edx
  _DWORD *v4; // edi
  int v5; // ecx
  int result; // eax

  v1 = *(_DWORD **)(a1 + 24);
  v2 = *(_DWORD **)(a1 + 372);
  v3 = v1[1];
  v2[4] = *v1;
  v2[5] = v3;
  sub_6D5640((int)v2);
  sub_6D5530((int)v2, 127, 7);
  v4 = *(_DWORD **)(a1 + 24);
  v5 = v2[5];
  v2[6] = 0;
  v2[7] = 0;
  result = v2[4];
  *v4 = result;
  v4[1] = v5;
  return result;
}

int __stdcall sub_50C800(int a1, float a2)
{
  int v2; // ebx
  int i; // esi
  int v4; // eax
  int result; // eax

  v2 = sub_59CB20(a1);
  for ( i = 0; i < v2; *(_DWORD *)(v4 + 24) = ((unsigned int)(__int64)(a2 * 254.0 + 0.5) << 24) + 0xFFFFFF )
    v4 = sub_59CB40(i++);
  result = *(_DWORD *)(a1 + 20) | 0x10000000;
  *(_DWORD *)(a1 + 20) = result;
  return result;
}

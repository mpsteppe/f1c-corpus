int __stdcall sub_6D0FF0(_DWORD *a1)
{
  int v1; // ecx
  int result; // eax

  v1 = a1[114];
  result = a1[29];
  *(_DWORD *)(v1 + 92) = a1[79];
  *(_DWORD *)(v1 + 96) = result;
  return result;
}

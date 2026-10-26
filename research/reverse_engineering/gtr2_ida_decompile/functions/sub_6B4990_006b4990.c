int __usercall sub_6B4990@<eax>(int a1@<eax>)
{
  int v2; // edx
  int v3; // eax
  const void *v4; // esi
  int v5; // edx
  int result; // eax

  v2 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1408) + 256;
  v3 = 0;
  *(_DWORD *)(a1 + 328) = v2;
  memset((void *)(v2 - 256), 0, 0x100u);
  do
  {
    *(_BYTE *)(v3 + v2) = v3;
    ++v3;
  }
  while ( v3 <= 255 );
  v4 = *(const void **)(a1 + 328);
  v5 = v2 + 128;
  memset((void *)(v5 + 128), 0xFFu, 0x180u);
  result = 0;
  memset((void *)(v5 + 512), 0, 0x180u);
  qmemcpy((void *)(v5 + 896), v4, 0x80u);
  return result;
}

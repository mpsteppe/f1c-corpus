// f1c  0x00516c0c  size=111
int __usercall sub_516C0C@<eax>(int a1@<eax>)
{
  int v2; // edx
  int v3; // eax
  int v4; // edx
  int result; // eax

  v2 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1408) + 256;
  v3 = 0;
  *(_DWORD *)(a1 + 284) = v2;
  memset((void *)(v2 - 256), 0, 0x100u);
  do
  {
    *(_BYTE *)(v3 + v2) = v3;
    ++v3;
  }
  while ( v3 <= 255 );
  v4 = v2 + 128;
  memset((void *)(v4 + 128), 0xFFu, 0x180u);
  result = 0;
  memset((void *)(v4 + 512), 0, 0x180u);
  qmemcpy((void *)(v4 + 896), *(const void **)(a1 + 284), 0x80u);
  return result;
}

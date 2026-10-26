// f1c  0x00563080  size=70
BOOL __thiscall sub_563080(_DWORD *this)
{
  SOCKET v2; // eax
  char optval[4]; // [esp+4h] [ebp-4h] BYREF

  *(_DWORD *)optval = 1;
  v2 = socket(2, 2, 17);
  this[34] = v2;
  return v2 == -1 || setsockopt(v2, 0xFFFF, 32, optval, 4) != 0;
}

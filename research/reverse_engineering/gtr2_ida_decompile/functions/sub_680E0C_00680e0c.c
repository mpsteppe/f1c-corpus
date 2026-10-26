BOOL __thiscall sub_680E0C(_DWORD *this)
{
  unsigned int v1; // eax

  v1 = *this & 0xFFF00000;
  return v1 == 0x10000000 || v1 == 269484032 || v1 == 287309824 || v1 == 544210944 || v1 == 545259520 || v1 == 546308096;
}

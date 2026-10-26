BOOL __thiscall sub_680F22(_DWORD *this)
{
  unsigned int v1; // eax

  v1 = *this & 0xFFF00000;
  return v1 == 1930428416
      || v1 == 1932525568
      || v1 == 1943011328
      || v1 == 1944059904
      || v1 == 1945108480
      || v1 == 1946157056;
}

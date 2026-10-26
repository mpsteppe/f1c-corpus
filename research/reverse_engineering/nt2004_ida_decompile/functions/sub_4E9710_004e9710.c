unsigned int __thiscall sub_4E9710(_DWORD *this)
{
  HANDLE FileMappingA; // eax
  LPVOID v3; // eax

  *this = 0;
  this[1] = 0;
  FileMappingA = CreateFileMappingA((HANDLE)0xFFFFFFFF, 0, 4u, 0, 0xB4u, aNt2004);
  *this = FileMappingA;
  if ( FileMappingA )
  {
    v3 = MapViewOfFile(FileMappingA, 0xF001Fu, 0, 0, 0xB4u);
    this[1] = v3;
    if ( !v3 )
      *this = 0;
  }
  return sub_4E9620(this);
}

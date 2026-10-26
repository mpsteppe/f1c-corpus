int sub_58F940()
{
  unsigned int v0; // eax
  BOOL v1; // edx
  unsigned int v2; // eax
  bool v3; // cf
  unsigned int v4; // eax
  int v5; // ecx
  unsigned int v6; // eax
  int result; // eax

  v0 = dword_61B5C0 + dword_61B5C4;
  v1 = dword_61B5C0 + dword_61B5C4 < (unsigned int)dword_61B5C4 || v0 < dword_61B5C0;
  dword_61B5C0 += dword_61B5C4;
  v2 = dword_61B5BC + v1 + v0;
  v3 = v2 < dword_61B5BC;
  dword_61B5BC = v2;
  v4 = dword_61B5B8 + v3 + v2;
  v5 = -(v4 < dword_61B5B8);
  dword_61B5B8 = v4;
  v6 = dword_61B5B4 - v5 + v4;
  v3 = v6 < dword_61B5B4;
  dword_61B5B4 = v6;
  result = v6 + v3 + dword_61B5B0;
  ++dword_61B5C4;
  dword_61B5B0 = result;
  if ( !dword_61B5C4 && !++dword_61B5C0 && !++dword_61B5BC && !++dword_61B5B8 && !++dword_61B5B4 )
    dword_61B5B0 = ++result;
  return result;
}

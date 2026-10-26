int __stdcall sub_4F9420(int a1, int a2, int a3, int a4)
{
  int v4; // eax

  v4 = MultiTableCoordinateSearch(a1, a2, a3, a4);
  if ( v4 < 0 )
    return 1;
  dword_5D6D68 = a3;
  dword_8AFE78 = a4;
  dword_5D6D60 = a1;
  dword_8AFE74 = v4;
  dword_5D6D64 = a2;
  return 0;
}

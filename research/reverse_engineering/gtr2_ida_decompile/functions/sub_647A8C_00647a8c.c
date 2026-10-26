int __stdcall sub_647A8C(DWORD NumberOfBytesWritten)
{
  int v1; // esi

  v1 = *(_DWORD *)(NumberOfBytesWritten + 24);
  sub_6462BB(*(_DWORD *)(v1 + 20), *(char **)(v1 + 24), 0x1000u, &NumberOfBytesWritten);
  *(_DWORD *)v1 = *(_DWORD *)(v1 + 24);
  *(_DWORD *)(v1 + 4) = 4096;
  return 1;
}

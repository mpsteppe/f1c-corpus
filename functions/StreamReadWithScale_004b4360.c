char __stdcall sub_4B4360(int a1, float a2, int a3)
{
  int v3; // esi

  v3 = a3;
  FileWriteWithBackendDispatch(a3, 4);
  if ( (*(_DWORD *)v3 & 0xE0000000) != 0x20000000 || (*(_DWORD *)v3 & 0xFC0000) != 0 )
  {
    *(float *)(v3 + 4) = a2;
  }
  else
  {
    FileWriteWithBackendDispatch(&a3, 1);
    a3 = (unsigned __int8)a3;
    *(float *)(v3 + 4) = (double)(unsigned __int8)a3 * 0.0001670000056037679 + a2;
  }
  FileWriteWithBackendDispatch(v3 + 8, (*(_DWORD *)v3 >> 8) & 0x3FF);
  return 0;
}

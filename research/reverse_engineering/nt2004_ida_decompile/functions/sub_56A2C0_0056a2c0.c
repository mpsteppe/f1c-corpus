int __thiscall sub_56A2C0(int *this, int a2)
{
  int v2; // esi
  int v3; // edi
  DWORD v4; // eax
  char *v5; // eax
  char v6; // cl
  void *v7; // esi

  v2 = *this;
  v3 = 0;
  v4 = WaitForSingleObject(*(HANDLE *)(*this + 1560), 5u);
  if ( v4 != 258 && v4 != -1 )
  {
    v3 = *(_DWORD *)(v2 + 1476);
    *(_DWORD *)(v2 + 1476) = 0;
    if ( a2 )
    {
      v5 = (char *)(v2 + 1480);
      do
      {
        v6 = *v5;
        v5[a2 - (v2 + 1480)] = *v5;
        ++v5;
      }
      while ( v6 );
    }
    *(_BYTE *)(v2 + 1480) = 0;
    v7 = *(void **)(v2 + 1560);
    if ( v7 )
      ReleaseMutex(v7);
  }
  return v3;
}

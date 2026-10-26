int __thiscall sub_57E7E0(int *this)
{
  void *v1; // eax
  int *v2; // ebx
  DWORD v3; // eax
  int *v4; // ebp
  int v5; // esi
  int v6; // edi
  int result; // eax

  v1 = (void *)this[715];
  v2 = this + 711;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[716])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = *v4;
  while ( v5 )
  {
    v6 = v5;
    v5 = *(_DWORD *)(v5 + 4);
    if ( *(_BYTE *)(v6 + 8) )
      FreeWrapper_7bcf(*(LPVOID *)v6);
    FreeWrapper_7bcf((LPVOID)v6);
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  result = v2[4];
  if ( result )
    return ReleaseMutex((HANDLE)v2[4]);
  return result;
}

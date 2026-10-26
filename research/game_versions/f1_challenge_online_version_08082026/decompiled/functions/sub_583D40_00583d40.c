char __fastcall sub_583D40(int a1, int a2)
{
  int v2; // esi
  void *v3; // eax
  DWORD v4; // eax
  char *v5; // eax
  void *v6; // esi
  char v7; // bl

  v2 = a1 + 40 * a2 + 12;
  v3 = *(void **)(a1 + 40 * a2 + 16);
  if ( v3 && ((v4 = WaitForSingleObject(v3, *(_DWORD *)(a1 + 40 * a2 + 20))) == 0 || v4 == 128) )
    v5 = (char *)v2;
  else
    v5 = 0;
  v6 = *(void **)(v2 + 4);
  v7 = *v5;
  if ( v6 )
    ReleaseMutex(v6);
  return v7;
}

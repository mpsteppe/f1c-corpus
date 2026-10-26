int sub_431C70()
{
  int v0; // esi
  void *v1; // edi
  int v2; // esi
  void *v3; // edi
  int result; // eax

  sub_4331A0(&dword_7C73E8);
  v0 = dword_7C7418;
  while ( v0 )
  {
    v1 = (void *)v0;
    v0 = *(_DWORD *)(v0 + 4);
    sub_582290(v1);
    sub_587BCF(v1);
  }
  v2 = dword_7C7404;
  dword_7C7418 = 0;
  dword_7C741C = 0;
  dword_7C7420 = 0;
  dword_7C7424 = 0;
  while ( v2 )
  {
    v3 = (void *)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_434240(v3);
    sub_587BCF(v3);
  }
  dword_7C7404 = 0;
  dword_7C7408 = 0;
  dword_7C740C = 0;
  dword_7C7410 = 0;
  if ( dword_7C73F8 )
    sub_587BCF((LPVOID)dword_7C73F8);
  if ( dword_7C73F0 )
    sub_587BCF((LPVOID)dword_7C73F0);
  result = dword_7C73E8;
  if ( dword_7C73E8 )
    return sub_587BCF((LPVOID)dword_7C73E8);
  return result;
}

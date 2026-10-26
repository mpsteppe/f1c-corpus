int __thiscall sub_4EAAC0(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  LPVOID **v8; // ecx
  int result; // eax
  void *v10; // esi

  v2 = *(_DWORD *)(this + 140);
  v3 = this + 100;
  if ( v2 )
  {
    sub_592310(v2);
    *(_DWORD *)(v3 + 40) = 0;
  }
  if ( *(_DWORD *)(v3 + 28) )
    sub_5BE8AE(*(LPVOID *)(v3 + 28));
  sub_40D5B0((LPVOID *)(v3 + 12));
  sub_40D5B0((LPVOID *)v3);
  v4 = *(_DWORD *)(this + 84);
  while ( v4 )
  {
    v4 = *(_DWORD *)(v4 + 4);
    sub_4EDC60(1);
  }
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  v5 = *(_DWORD *)(this + 68);
  while ( v5 )
  {
    v5 = *(_DWORD *)(v5 + 4);
    sub_4ED8E0(1);
  }
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  v6 = *(_DWORD *)(this + 52);
  while ( v6 )
  {
    v6 = *(_DWORD *)(v6 + 4);
    sub_4ED8E0(1);
  }
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  v7 = *(_DWORD *)(this + 36);
  while ( v7 )
  {
    v8 = (LPVOID **)v7;
    v7 = *(_DWORD *)(v7 + 4);
    sub_414480(v8, 1);
  }
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 48) = 0;
  if ( *(_DWORD *)(this + 28) )
    sub_5BE8AE(*(LPVOID *)(this + 28));
  if ( *(_DWORD *)(this + 20) )
    sub_5BE8AE(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 12);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 12));
  v10 = *(void **)(this + 4);
  if ( v10 )
    return sub_5BE8AE(v10);
  return result;
}

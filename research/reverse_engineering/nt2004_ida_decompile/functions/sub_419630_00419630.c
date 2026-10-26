void __cdecl sub_419630()
{
  int v0; // esi
  LPVOID *v1; // edi
  bool v2; // zf

  nullsub_6(&unk_629328);
  v0 = dword_6293E8;
  while ( v0 )
  {
    v1 = (LPVOID *)v0;
    v2 = *(_BYTE *)(v0 + 8) == 0;
    v0 = *(_DWORD *)(v0 + 4);
    if ( !v2 && *v1 )
      sub_5BE8AE(*v1);
    sub_5BE8AE(v1);
  }
  dword_6293E8 = 0;
  dword_6293EC = 0;
  dword_6293F0 = 0;
  dword_6293F4 = 0;
}

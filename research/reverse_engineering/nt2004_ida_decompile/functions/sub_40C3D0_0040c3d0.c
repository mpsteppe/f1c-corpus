void __thiscall sub_40C3D0(int *this)
{
  int v1; // esi
  int v2; // edi
  int v3; // ecx
  int v4; // ecx

  v4 = *this;
  v1 = v4;
  if ( !*(_DWORD *)(v4 + 44) )
    sub_409CE0(v4);
  if ( (*(_DWORD *)(dword_75AAC4 + 25296) & 2) == 0 )
    sub_42DB40(dword_75AAC8);
  v2 = *(_DWORD *)(v1 + 16);
  sub_40AA00(v1);
  if ( *(_DWORD *)(v1 + 24) == 1 )
    sub_4092A0((int **)v1);
  LOBYTE(v3) = *(_DWORD *)(v1 + 16) != v2;
  sub_40B330(v1, *(_DWORD *)(v1 + 16), v3, 1);
}

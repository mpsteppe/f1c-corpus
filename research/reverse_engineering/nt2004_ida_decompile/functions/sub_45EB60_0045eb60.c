void __thiscall sub_45EB60(int this)
{
  int v2; // edi
  LPVOID **v3; // ecx
  char *v4; // edi
  int v5; // ebx
  int v6; // edi
  char *v7; // edi
  int v8; // ebx

  sub_4667A0(this + 30120);
  v2 = *(_DWORD *)(this + 30096);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_414480(v3, 1);
  }
  *(_DWORD *)(this + 30096) = 0;
  *(_DWORD *)(this + 30100) = 0;
  *(_DWORD *)(this + 30104) = 0;
  *(_DWORD *)(this + 30108) = 0;
  v4 = (char *)(this + 27716);
  v5 = 49;
  do
  {
    v4 -= 424;
    nullsub_6(v4);
    --v5;
  }
  while ( v5 );
  v6 = *(_DWORD *)(this + 6724);
  while ( v6 )
  {
    v6 = *(_DWORD *)(v6 + 4);
    sub_466750(1);
  }
  *(_DWORD *)(this + 6724) = 0;
  *(_DWORD *)(this + 6728) = 0;
  *(_DWORD *)(this + 6732) = 0;
  *(_DWORD *)(this + 6736) = 0;
  *(_DWORD *)(this + 6712) = off_5D6450;
  v7 = (char *)(this + 6320);
  v8 = 48;
  do
  {
    v7 -= 116;
    nullsub_6(v7);
    --v8;
  }
  while ( v8 );
  if ( *(_DWORD *)(this + 432) )
    sub_5BE8AE(*(LPVOID *)(this + 432));
  if ( *(_DWORD *)(this + 156) )
    sub_5BE8AE(*(LPVOID *)(this + 156));
  if ( *(_DWORD *)(this + 144) )
    sub_5BE8AE(*(LPVOID *)(this + 144));
  if ( *(_DWORD *)(this + 136) )
    sub_5BE8AE(*(LPVOID *)(this + 136));
  nullsub_6((void *)(this + 44));
}

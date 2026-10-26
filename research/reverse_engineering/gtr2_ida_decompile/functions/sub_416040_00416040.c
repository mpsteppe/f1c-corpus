void __thiscall sub_416040(int this, int a2)
{
  void *v3; // eax
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // ecx

  *(_DWORD *)(this + 164) = *(_DWORD *)(a2 + 20);
  if ( *(_DWORD *)(this + 168) )
    j_j__free(*(void **)(this + 168));
  v3 = operator new(4 * *(_DWORD *)(this + 164));
  v4 = *(_DWORD *)(this + 164);
  *(_DWORD *)(this + 168) = v3;
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = (_DWORD *)(a2 + 24);
    do
      *(_DWORD *)(*(_DWORD *)(this + 168) + 4 * v5++) = *v6++;
    while ( v5 < *(_DWORD *)(this + 164) );
  }
  v7 = *(_DWORD *)(this + 132);
  *(_BYTE *)(this + 172) = *(_BYTE *)(a2 + 88);
  if ( v7 && *(_DWORD *)(this + 136) )
  {
    if ( sub_616630("CinematicEvent") )
    {
      if ( *(int *)(a2 + 4) > 0 )
      {
        sub_415300(*(_DWORD *)(this + 136));
        if ( *(_DWORD *)(*(_DWORD *)(this + 136) + 36) == 2 )
          JUMPOUT(0x416112);
        JUMPOUT(0x41615E);
      }
      JUMPOUT(0x416172);
    }
    JUMPOUT(0x416182);
  }
  JUMPOUT(0x416183);
}

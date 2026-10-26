void __thiscall sub_67352C(int this)
{
  unsigned int v2; // ebx
  int v3; // eax
  void *v4; // edi
  unsigned int v5; // edi
  int v6; // eax
  void *v7; // ebx

  v2 = 0;
  if ( *(_DWORD *)(this + 56) )
  {
    if ( *(_WORD *)(*(_DWORD *)(this + 24) + 10) )
    {
      do
      {
        v3 = *(_DWORD *)(this + 56);
        v4 = *(void **)(v3 + 4 * v2);
        if ( v4 )
        {
          sub_67352C(*(_DWORD *)(v3 + 4 * v2));
          j__free(v4);
        }
        ++v2;
      }
      while ( v2 < *(unsigned __int16 *)(*(_DWORD *)(this + 24) + 10) );
    }
    j__free(*(void **)(this + 56));
  }
  v5 = 0;
  if ( *(_DWORD *)(this + 60) )
  {
    if ( *(_WORD *)(*(_DWORD *)(this + 24) + 8) )
    {
      do
      {
        v6 = *(_DWORD *)(this + 60);
        v7 = *(void **)(v6 + 4 * v5);
        if ( v7 )
        {
          sub_67352C(*(_DWORD *)(v6 + 4 * v5));
          j__free(v7);
        }
        ++v5;
      }
      while ( v5 < *(unsigned __int16 *)(*(_DWORD *)(this + 24) + 8) );
    }
    j__free(*(void **)(this + 60));
  }
  j__free(*(void **)(this + 64));
}

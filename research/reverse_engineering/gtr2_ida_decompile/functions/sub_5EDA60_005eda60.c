int __thiscall sub_5EDA60(int this, int a2, int a3)
{
  void *v4; // eax
  void *v6; // eax

  if ( a2 == 2 )
  {
    if ( *(_DWORD *)(this + 44) )
    {
      j__free(*(void **)(this + 44));
      *(_DWORD *)(this + 44) = 0;
    }
    v4 = operator new(a3 << 6);
    *(_DWORD *)(this + 20) = a3;
    *(_DWORD *)(this + 44) = v4;
    *(_DWORD *)(this + 4) = 2;
    return 0;
  }
  else
  {
    if ( a2 == 1 )
    {
      if ( *(_DWORD *)(this + 44) )
      {
        j__free(*(void **)(this + 44));
        *(_DWORD *)(this + 44) = 0;
      }
      v6 = operator new(28 * a3);
      *(_DWORD *)(this + 4) = 1;
      *(_DWORD *)(this + 44) = v6;
      *(_DWORD *)(this + 20) = a3;
    }
    return 0;
  }
}

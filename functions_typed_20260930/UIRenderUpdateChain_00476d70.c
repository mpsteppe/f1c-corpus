int __thiscall UIRenderUpdateChain(_DWORD *this)
{
  int v2; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  v2 = LinkedListIndexedAccessor_f590(this);
  if ( v2 )
  {
    if ( *(int *)(v2 + 72) > 0 )
    {
      v3 = *(int **)(v2 + 60);
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = *(_DWORD *)(v4 + 60);
          if ( v5 )
          {
            if ( dword_5EB10C )
              (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
            BufferInitWith10fDefaults(flt_5EA618);
            TeamNameDisplayIDLookup(v5);
          }
        }
      }
    }
  }
  return 0;
}


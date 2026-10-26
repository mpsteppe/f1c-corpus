int __thiscall sub_583570(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  _BYTE *v3; // ebx
  int *v4; // ebp
  int v5; // eax
  void *v6; // esi
  int result; // eax

  v1 = this;
  v2 = (_DWORD *)*this;
  if ( *this )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      if ( v3[8] )
      {
        v4 = *(int **)v3;
        if ( *(_DWORD *)v3 )
        {
          v5 = *v4;
          if ( *v4 )
          {
            v6 = (void *)(v5 - 4);
            NTimeCallbackLoopWithSEH(v5, 4156, *(_DWORD *)(v5 - 4), EmptyStub_aa60);
            FreeWrapper_7bcf(v6);
            v1 = this;
          }
          FreeWrapper_7bcf(v4);
        }
      }
      FreeWrapper_7bcf(v3);
    }
    while ( v2 );
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}


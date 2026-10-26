void __thiscall sub_4C7CA0(_DWORD *this)
{
  int v1; // ebx
  int v2; // esi
  void (__thiscall ***v3)(_DWORD, int); // edi
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  _DWORD v8[2]; // [esp+Ch] [ebp-10h] BYREF
  _DWORD *v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]

  v9 = this;
  if ( dword_8ACFCC )
    RenderFlagSetter(7, 4096);
  v8[1] = dword_8AFE88;
  if ( dword_8AFE88 )
  {
    v1 = 0;
    v10 = AudioNetworkNodeCount(dword_8AFE88);
    if ( v10 > 0 )
    {
      do
      {
        v2 = LinkedListNodeFinder(v1);
        if ( v2 )
        {
          v8[0] = 0;
          FlagPropertyGetter(v8, 4096);
          if ( v8[0] )
          {
            v3 = (void (__thiscall ***)(_DWORD, int))MemoryAllocation_9a50();
            if ( v3 )
            {
              if ( VTableDispatchWithNegation(v2) )
                goto LABEL_22;
              v4 = v9;
              if ( !v9[3] )
              {
                v5 = (_DWORD *)OperatorNewNhMallocWrapper(16);
                if ( v5 )
                {
                  *v5 = 0;
                  v5[1] = 0;
                  v5[2] = 0;
                  v5[3] = 0;
                }
                else
                {
                  v5 = 0;
                }
                v4[3] = v5;
              }
              v6 = (_DWORD *)v4[3];
              if ( !v6 )
              {
LABEL_22:
                (**v3)(v3, 1);
              }
              else
              {
                v7 = OperatorNewNhMallocWrapper(12);
                if ( v7 )
                {
                  *(_DWORD *)v7 = v3;
                  *(_DWORD *)(v7 + 4) = 0;
                  *(_BYTE *)(v7 + 8) = 1;
                }
                else
                {
                  v7 = 0;
                }
                if ( *v6 )
                {
                  *(_DWORD *)(v6[1] + 4) = v7;
                }
                else
                {
                  *v6 = v7;
                  v6[2] = v7;
                }
                v6[1] = v7;
                ++v6[3];
              }
            }
          }
        }
        ++v1;
      }
      while ( v1 < v10 );
    }
  }
}

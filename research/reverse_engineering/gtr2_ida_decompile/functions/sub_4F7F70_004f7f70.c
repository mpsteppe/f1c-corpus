void __thiscall sub_4F7F70(int this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  _DWORD *i; // edi

  if ( (*(_BYTE *)(this + 12) & 1) == 0 )
  {
    v2 = *(_DWORD *)(this + 296);
    if ( v2 )
    {
      if ( !*(_BYTE *)(v2 + 8) )
      {
        v3 = 0;
        if ( *(int *)(this + 288) > 0 )
        {
          v4 = 0;
          do
          {
            if ( *(_BYTE *)(*(_DWORD *)(this + 292) + v4 + 11) )
              sub_4F7BF0();
            ++v3;
            v4 += 768;
          }
          while ( v3 < *(_DWORD *)(this + 288) );
        }
        v5 = *(_DWORD **)(this + 296);
        if ( v5[35] )
        {
          v6 = v5[40];
          if ( !v6 || *(_DWORD *)(v6 + 96) && *(_DWORD *)(v6 + 116) )
          {
            v7 = v5[38];
            v8 = 0;
            if ( v7 > 0 )
            {
              for ( i = (_DWORD *)(v5[39] + 116); *i; i += 30 )
              {
                if ( ++v8 >= v7 )
                  return;
              }
              sub_4F59C0();
            }
          }
        }
      }
    }
  }
}

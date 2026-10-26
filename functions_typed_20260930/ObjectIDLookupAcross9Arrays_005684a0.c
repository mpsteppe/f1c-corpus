char __thiscall sub_5684A0(_DWORD *this, const char *a2)
{
  char v2; // bl
  unsigned int v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  int v7; // esi
  _DWORD *v8; // ecx
  _DWORD *v9; // ecx
  int v10; // esi
  _DWORD *v11; // ecx
  unsigned int v13; // [esp+8h] [ebp-4h]
  int v14; // [esp+10h] [ebp+4h]

  v2 = 0;
  if ( a2 )
  {
    v14 = HashTableEntrySearch(this, a2);
    if ( v14 >= 0 )
    {
      v4 = 0;
      v13 = 0;
      do
      {
        v5 = (_DWORD *)this[v4];
        if ( v5 )
        {
          do
          {
            v6 = (_DWORD *)ShortComputation_adb0(v5);
            if ( v6 )
            {
              do
              {
                v7 = ShortComputation_adb0(v6);
                if ( FieldGetter_79d0(v8) == v14 )
                {
                  sub_568320(this, v9);
                  v2 = 1;
                }
                v6 = (_DWORD *)v7;
              }
              while ( v7 );
            }
            v10 = SimpleFieldGetter_bfc0(v5);
            if ( FieldGetter_79d0(v11) == v14 )
            {
              sub_568320(this, v5);
              v2 = 1;
            }
            v5 = (_DWORD *)v10;
          }
          while ( v10 );
          v4 = v13;
        }
        v13 = ++v4;
      }
      while ( v4 < 9 );
    }
  }
  return v2;
}


void __thiscall sub_4EEEC0(_DWORD *this)
{
  int v1; // ebx
  int v2; // esi
  void (__thiscall ***v3)(_DWORD, int); // edi
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD v8[2]; // [esp+Ch] [ebp-10h] BYREF
  _DWORD *v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]

  v9 = this;
  v8[1] = dword_7DA9B8;
  if ( dword_7DA9B8 )
  {
    v1 = 0;
    v10 = sub_597540(dword_7DA9B8);
    if ( v10 > 0 )
    {
      do
      {
        v2 = sub_597590(v1);
        if ( v2 )
        {
          v8[0] = 0;
          sub_59EF10(v8, 4096);
          if ( v8[0] )
          {
            v3 = (void (__thiscall ***)(_DWORD, int))sub_4F0E20();
            if ( v3 )
            {
              if ( sub_4F04C0(v2) )
                goto LABEL_20;
              v4 = v9;
              if ( !v9[2] )
              {
                v5 = operator new(0x10u);
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
                v4[2] = v5;
              }
              v6 = (_DWORD *)v4[2];
              if ( !v6 )
              {
LABEL_20:
                (**v3)(v3, 1);
              }
              else
              {
                v7 = operator new(0xCu);
                if ( v7 )
                {
                  *v7 = v3;
                  v7[1] = 0;
                  *((_BYTE *)v7 + 8) = 1;
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

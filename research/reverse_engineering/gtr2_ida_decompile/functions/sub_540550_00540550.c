void __thiscall sub_540550(_DWORD *this)
{
  int v1; // ebp
  int v2; // esi
  void (__thiscall ***v3)(_DWORD, int); // edi
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  _DWORD v6[2]; // [esp+8h] [ebp-10h] BYREF
  _DWORD *v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v7 = this;
  if ( dword_FADE70 )
    sub_5DB5B0(7, 4096);
  v6[1] = dword_FB1D04;
  if ( dword_FB1D04 )
  {
    v1 = 0;
    v8 = sub_5DAB20(dword_FB1D04);
    if ( v8 > 0 )
    {
      do
      {
        v2 = sub_5DAB30(v1);
        if ( v2 )
        {
          v6[0] = 0;
          sub_5DA960(v6, 4096);
          if ( v6[0] )
          {
            v3 = (void (__thiscall ***)(_DWORD, int))sub_541AC0();
            if ( v3 )
            {
              if ( sub_5414B0(v2) )
                goto LABEL_16;
              v4 = v7;
              if ( !v7[3] )
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
                v4[3] = v5;
              }
              if ( !v4[3] )
LABEL_16:
                (**v3)(v3, 1);
              else
                sub_5FDFB0(v3, 1);
            }
          }
        }
        ++v1;
      }
      while ( v1 < v8 );
    }
  }
}

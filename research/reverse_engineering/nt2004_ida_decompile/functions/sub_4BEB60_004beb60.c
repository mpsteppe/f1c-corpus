void __thiscall sub_4BEB60(int *this, int a2, int a3)
{
  _DWORD **v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // eax
  _DWORD **v8; // eax
  int v9; // eax

  if ( dword_75CBB0 == 7 )
  {
    if ( (*(_BYTE *)this & 1) == 0 || this[50] != a2 )
    {
      v4 = (_DWORD **)this[46];
      this[48] = (int)v4;
      if ( v4 )
      {
        v5 = *v4;
        if ( *v4 )
        {
          do
          {
            v6 = v5[25];
            if ( v6 )
            {
              if ( sub_4BD140(v5, a2) )
              {
                sub_59EF50(v6);
                sub_4BD160((int)v5, a2, 0.0);
                if ( v5[18] != -1 && v5[25] )
                  sub_5A2930(0, 0, 0);
              }
              else
              {
                sub_59EF60(v6);
              }
            }
            v7 = this[48];
            if ( !v7 )
              break;
            v8 = *(_DWORD ***)(v7 + 4);
            this[48] = (int)v8;
            if ( !v8 )
              break;
            v5 = *v8;
          }
          while ( *v8 );
        }
      }
      v9 = *this | 1;
      this[50] = a2;
      *this = v9;
      this[16] = 0;
    }
  }
  else
  {
    *this |= 1u;
    sub_4BEC30(this);
  }
}

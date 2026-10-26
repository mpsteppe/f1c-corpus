void __thiscall sub_5505A0(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *i; // esi
  int *v5; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edx

  if ( a2 )
  {
    if ( a3 <= *(_DWORD *)(a2 + 164) )
    {
      v3 = *(_DWORD *)(a2 + 168) + 148 * a3;
      if ( *(int *)(v3 + 72) > 1 )
      {
        for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
        {
          if ( i[70] )
          {
            v5 = (int *)(i[71] + 52);
            v6 = i[70];
            do
            {
              if ( *(v5 - 12) == a2 )
              {
                v7 = *v5;
                v8 = *(_DWORD *)(v3 + 80);
                if ( *v5 >= v8 )
                  v7 -= v8;
                *v5 = v7;
              }
              v5 += 16;
              --v6;
            }
            while ( v6 );
          }
        }
      }
    }
  }
}


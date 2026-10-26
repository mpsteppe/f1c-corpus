// f1c  0x005506a0  size=191
void __thiscall sub_5506A0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *j; // edx
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  _DWORD *i; // edx
  int v10; // ecx
  _DWORD *v11; // eax

  if ( a3 )
  {
    v8 = *(_DWORD *)(a3 + 168) + 148 * a4;
    if ( *(int *)(v8 + 72) > 1 )
    {
      for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
      {
        v10 = i[70];
        if ( v10 )
        {
          v11 = (_DWORD *)(i[71] + 52);
          do
          {
            if ( *(v11 - 12) == a3 && a2 < *(_DWORD *)(v8 + 80) )
              *v11 = a2;
            v11 += 16;
            --v10;
          }
          while ( v10 );
        }
      }
    }
  }
  else
  {
    for ( j = (_DWORD *)this[129]; j; j = (_DWORD *)j[4] )
    {
      if ( j[70] )
      {
        v5 = (_DWORD *)(j[71] + 52);
        v6 = j[70];
        do
        {
          v7 = *(_DWORD *)(*(v5 - 12) + 168);
          if ( *(int *)(v7 + 72) > 1 && a2 < *(_DWORD *)(v7 + 80) )
            *v5 = a2;
          v5 += 16;
          --v6;
        }
        while ( v6 );
      }
    }
  }
}

int __thiscall sub_5ED650(_DWORD **this, int a2, int a3)
{
  _DWORD **v3; // esi
  int result; // eax
  int *v5; // ecx
  int v6; // ebp
  int v7; // eax
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  int v11; // eax
  int v12; // eax
  int *v13; // eax

  v3 = this;
  result = 0;
  if ( (*(_BYTE *)a2 & 2) == 0 )
  {
    if ( *this[113] >= this[113][2] )
    {
      return 1;
    }
    else
    {
      v5 = *(int **)(a2 + 532);
      *(_DWORD *)(a2 + 540) = v5;
      if ( v5 )
      {
        v6 = *v5;
        if ( *v5 )
        {
          do
          {
            if ( (*(_DWORD *)v6 & 0x100000) != 0 )
            {
              if ( (*(_DWORD *)a2 & 0x10) != 0 )
              {
                if ( (*(_DWORD *)a2 & 0x40) != 0 )
                {
                  v7 = *(_DWORD *)(a2 + 624);
                  if ( v7 )
                  {
                    sub_5D7280((char *)(a2 + 180), a2 + 72, (float *)(v7 + 180));
                  }
                  else
                  {
                    qmemcpy((void *)(a2 + 184), (const void *)(a2 + 76), 0x40u);
                    v3 = this;
                  }
                  sub_5D7160(a2 + 248, (float *)(a2 + 180));
                  *(_DWORD *)a2 &= ~0x40u;
                  *(_DWORD *)v6 &= ~0x2000u;
                }
                if ( (*(_DWORD *)v6 & 0x2000) == 0 )
                {
                  sub_5D7810((float *)(v6 + 216), (float *)(v6 + 228), (float *)(a2 + 184));
                  *(_DWORD *)v6 |= 0x2000u;
                }
              }
              if ( !(v9 | v10) && (a3 & 1) != 0 )
              {
                if ( (*(_BYTE *)a2 & 0x10) != 0 )
                  v11 = sub_5ECBC0(v3, a2, (_DWORD *)v6, a3);
                else
                  v11 = sub_5ED040(v3, a2, (int *)v6, a3);
                if ( v11 > 0 )
                  *v3[113] += v11;
              }
            }
            v12 = *(_DWORD *)(a2 + 540);
            if ( !v12 )
              break;
            v13 = *(int **)(v12 + 4);
            *(_DWORD *)(a2 + 540) = v13;
            if ( !v13 )
              break;
            v6 = *v13;
          }
          while ( *v13 );
          return 0;
        }
      }
    }
  }
  return result;
}

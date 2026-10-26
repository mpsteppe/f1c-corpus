int __thiscall sub_672B87(_DWORD *this, __int64 a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int i; // esi
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  double v13; // st7
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // edi
  _DWORD *v18; // eax
  int result; // eax
  _DWORD *v20; // eax
  int v21; // esi
  int v22; // eax
  __int64 v23; // [esp-4h] [ebp-18h]
  int v24; // [esp+20h] [ebp+Ch]

  v3 = a2;
  if ( !(_DWORD)a2 )
  {
    if ( HIDWORD(a2) )
    {
      for ( i = 0; i < a3; ++i )
      {
        v6 = sub_681AAA(*(_DWORD *)(this[2] + 136), 0, 0, 0.0);
        *(_DWORD *)(HIDWORD(a2) + 4 * i) = v6;
        v7 = this[2];
        if ( v6 >= *(_DWORD *)(v7 + 8) )
          v8 = 0;
        else
          v8 = *(_DWORD *)(*(_DWORD *)(v7 + 20) + 4 * v6);
        if ( v8 )
          *(_DWORD *)(v8 + 48) = -1;
      }
    }
    return 0;
  }
  v9 = *(_DWORD *)(a2 + 4);
  switch ( v9 )
  {
    case 14:
      v10 = (unsigned int *)HIDWORD(a2);
      if ( !HIDWORD(a2) )
        return 0;
      v11 = *(_DWORD *)(a2 + 16);
      if ( v11 == 6 )
      {
        v12 = 0;
        if ( *(_DWORD *)(a2 + 24) == -1 )
        {
          if ( a3 )
          {
            do
            {
              *(_DWORD *)(HIDWORD(a2) + 4 * v12) = *(_DWORD *)(this[7] + 4 * v12);
              ++v12;
            }
            while ( v12 < a3 );
          }
        }
        else if ( a3 )
        {
          do
          {
            *(_DWORD *)(HIDWORD(a2) + 4 * v12) = *(_DWORD *)(this[6] + 4 * (v12 + *(_DWORD *)(a2 + 24)));
            ++v12;
          }
          while ( v12 < a3 );
        }
        return 0;
      }
      v13 = 0.0;
      v24 = 0;
      if ( v11 )
      {
        v14 = v11 - 1;
        if ( v14 )
        {
          v15 = v14 - 1;
          if ( v15 )
          {
            if ( v15 == 1 )
              v13 = *(double *)(a2 + 24);
            goto LABEL_33;
          }
          v13 = (double)*(unsigned int *)(a2 + 24);
        }
        else
        {
          v13 = (double)*(int *)(a2 + 24);
        }
        v24 = 2;
      }
      else
      {
        if ( *(_DWORD *)(a2 + 24) )
          v13 = 1.0;
        else
          v13 = 0.0;
        v24 = 23;
      }
LABEL_33:
      v16 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, v13);
      *v10 = v16;
      v17 = this[2];
      if ( v16 >= *(_DWORD *)(v17 + 8) )
        v18 = 0;
      else
        v18 = *(_DWORD **)(*(_DWORD *)(v17 + 20) + 4 * v16);
      if ( v18 )
      {
        *v18 |= v24;
        v18[12] = -1;
      }
      return 0;
    case 13:
      return sub_6714D6((int)this, a2, 0);
    case 1:
      while ( 1 )
      {
        v20 = *(_DWORD **)(v3 + 8);
        if ( !v20 )
          goto LABEL_41;
        if ( v20[1] == 14 )
        {
          v21 = 1;
          if ( v20[4] == 6 )
            v21 = v20[7];
          result = sub_672B87(v20, HIDWORD(a2), v21);
          if ( result < 0 )
            return result;
          v22 = HIDWORD(a2);
          if ( HIDWORD(a2) )
            goto LABEL_54;
        }
        else
        {
          if ( v20[1] != 13 )
            goto LABEL_41;
          v21 = v20[5] * v20[6];
          HIDWORD(v23) = HIDWORD(a2);
          LODWORD(v23) = *(_DWORD *)(v3 + 8);
          result = sub_6714D6((int)this, v23, 0);
          if ( result < 0 )
            return result;
          if ( HIDWORD(a2) )
          {
            v22 = HIDWORD(a2);
LABEL_54:
            HIDWORD(a2) = v22 + 4 * v21;
          }
        }
        v3 = *(_DWORD *)(v3 + 12);
        if ( !v3 )
          return 0;
      }
  }
LABEL_41:
  sub_663C07(this, 0, 0, "internal error: unrecognized value");
  return -2147467259;
}

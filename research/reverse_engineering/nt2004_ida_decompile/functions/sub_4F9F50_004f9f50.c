void __thiscall sub_4F9F50(_DWORD *this)
{
  int v2; // ebx
  int i; // esi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // esi
  int v16; // ecx
  int v17; // eax
  _DWORD *v18; // eax

  v2 = this[62];
  if ( dword_75CBB4 >= 5 )
  {
    switch ( this[70] )
    {
      case 0:
      case 7:
        v7 = 0;
        if ( v2 <= 0 )
          return;
        while ( 1 )
        {
          v8 = v7;
          if ( v7 >= 0 && v7 < this[62] )
          {
            v9 = this[59];
            if ( v7 <= 0 )
            {
LABEL_20:
              if ( v9 )
              {
                v10 = *(_DWORD **)v9;
                goto LABEL_23;
              }
            }
            else
            {
              while ( v9 )
              {
                v9 = *(_DWORD *)(v9 + 4);
                if ( --v8 <= 0 )
                  goto LABEL_20;
              }
            }
          }
          v10 = 0;
LABEL_23:
          sub_4F8D30(v10, 3);
          if ( ++v7 >= v2 )
            return;
        }
      case 1:
      case 2:
      case 3:
      case 4:
      case 6:
        v11 = 0;
        if ( v2 <= 0 )
          return;
        while ( 1 )
        {
          v12 = v11;
          if ( v11 >= 0 && v11 < this[62] )
          {
            v13 = this[59];
            if ( v11 <= 0 )
            {
LABEL_31:
              if ( v13 )
              {
                v14 = *(_DWORD **)v13;
                goto LABEL_34;
              }
            }
            else
            {
              while ( v13 )
              {
                v13 = *(_DWORD *)(v13 + 4);
                if ( --v12 <= 0 )
                  goto LABEL_31;
              }
            }
          }
          v14 = 0;
LABEL_34:
          sub_4F8D30(v14, 1);
          if ( ++v11 >= v2 )
            return;
        }
      case 8:
        v15 = 0;
        if ( v2 <= 0 )
          return;
        break;
      default:
        return;
    }
    while ( 1 )
    {
      v16 = v15;
      if ( v15 >= 0 && v15 < this[62] )
      {
        v17 = this[59];
        if ( v15 <= 0 )
        {
LABEL_42:
          if ( v17 )
          {
            v18 = *(_DWORD **)v17;
            goto LABEL_45;
          }
        }
        else
        {
          while ( v17 )
          {
            v17 = *(_DWORD *)(v17 + 4);
            if ( --v16 <= 0 )
              goto LABEL_42;
          }
        }
      }
      v18 = 0;
LABEL_45:
      sub_4F8D30(v18, 2);
      if ( ++v15 >= v2 )
        return;
    }
  }
  for ( i = 0; i < v2; ++i )
  {
    v4 = i;
    if ( i >= 0 && i < this[62] )
    {
      v5 = this[59];
      if ( i <= 0 )
      {
LABEL_8:
        if ( v5 )
        {
          v6 = *(_DWORD **)v5;
          goto LABEL_11;
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = *(_DWORD *)(v5 + 4);
          if ( --v4 <= 0 )
            goto LABEL_8;
        }
      }
    }
    v6 = 0;
LABEL_11:
    sub_4F8D30(v6, 0);
  }
}

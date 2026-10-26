BOOL __thiscall sub_696CB7(void *this, int *a2, int *a3, int a4)
{
  int *v5; // edi
  int *v6; // esi
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  int v10; // esi
  bool v11; // zf
  unsigned int v12; // eax
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // esi
  int v21[4]; // [esp+Ch] [ebp-4Ch] BYREF
  int v22; // [esp+1Ch] [ebp-3Ch]
  int v23; // [esp+24h] [ebp-34h]
  int v24; // [esp+28h] [ebp-30h]
  int v25[4]; // [esp+30h] [ebp-28h] BYREF
  int v26; // [esp+40h] [ebp-18h]
  int v27; // [esp+48h] [ebp-10h]
  int v28; // [esp+4Ch] [ebp-Ch]
  int v29; // [esp+54h] [ebp-4h]

  v29 = (int)this;
  if ( a4 )
  {
    if ( !a2 )
      return 1;
  }
  else if ( !a2 )
  {
    return !a3;
  }
  if ( !a3 )
    return 0;
  sub_67F2AD(v21);
  sub_67F2AD(v25);
  if ( a2[1] == 9 )
  {
    v5 = a2;
  }
  else
  {
    v5 = v21;
    v22 = 4;
    v23 = 1;
    v24 = sub_6951CB((_DWORD *)v29, a2);
    if ( a4 && sub_695154((_DWORD *)v29, a2) )
      v22 = 1;
  }
  if ( a3[1] == 9 )
  {
    v6 = a3;
  }
  else
  {
    v6 = v25;
    v26 = 4;
    v27 = 1;
    v28 = sub_6951CB((_DWORD *)v29, a3);
    if ( a4 && sub_695154((_DWORD *)v29, a3) )
      v26 = 1;
  }
  v7 = v5[4];
  if ( v7 != 4 )
  {
    v8 = v6[4];
    if ( v8 != 4 )
    {
      switch ( v7 )
      {
        case 0:
          return v8 != 3;
        case 1:
          if ( !v8 )
            return 1;
          if ( v8 != 1 )
          {
            if ( v8 == 2 )
            {
              v9 = v6[6];
              if ( v9 == 1 && v5[7] > (unsigned int)v6[7] )
                return 0;
              v10 = v6[7];
              if ( v10 == 1 && v5[7] > v9 )
                return 0;
              if ( v9 != 1 && v10 != 1 )
              {
                v11 = v10 * v9 == v5[7];
                break;
              }
              return 1;
            }
            return v8 != 3;
          }
          return v5[7] <= (unsigned int)v6[7];
        case 2:
          if ( !v8 )
            return 1;
          if ( v8 != 1 )
          {
            if ( v8 != 2 )
              return v8 != 3;
            if ( v5[6] > (unsigned int)v6[6] )
              return 0;
            return v5[7] <= (unsigned int)v6[7];
          }
          v12 = v5[6];
          if ( v12 == 1 && v5[7] > (unsigned int)v6[7] )
            return 0;
          v13 = v5[7];
          if ( v13 == 1 && v12 > v6[7] )
            return 0;
          if ( v12 == 1 || v13 == 1 )
            return 1;
          v11 = v13 * v12 == v6[7];
          break;
        case 3:
          if ( v8 != 3 )
            return 0;
          v14 = v6[5];
          switch ( v14 )
          {
            case 13:
              return 1;
            case 15:
              v15 = v5[5];
              if ( v15 == 15 || v15 == 16 || v15 == 17 || v15 == 18 )
                return 1;
              v11 = v15 == 19;
              break;
            case 20:
              v16 = v5[5];
              if ( v16 == 20 || v16 == 21 || v16 == 22 || v16 == 23 )
                return 1;
              v11 = v16 == 24;
              break;
            default:
              v11 = v5[5] == v14;
              break;
          }
          break;
        default:
          return 1;
      }
      return v11;
    }
  }
  v17 = v5[6] * v5[7];
  v18 = v6[6] * v6[7];
  if ( a4 )
  {
    if ( v17 > v18 )
      return 0;
    v19 = 0;
    if ( v17 )
    {
      while ( sub_6955DE((_DWORD *)v29, (int)a2, v19, v21) >= 0
           && sub_6955DE((_DWORD *)v29, (int)a3, v19, v25) >= 0
           && sub_696CB7(v21, v25, 1) )
      {
        if ( ++v19 >= v17 )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    if ( v7 != v6[4] || v17 != v18 )
      return 0;
    v20 = 0;
    if ( v17 )
    {
      while ( sub_6955DE((_DWORD *)v29, (int)a2, v20, v21) >= 0
           && sub_6955DE((_DWORD *)v29, (int)a3, v20, v25) >= 0
           && sub_695259(v21, v25) )
      {
        if ( ++v20 >= v17 )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

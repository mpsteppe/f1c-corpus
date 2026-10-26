int __thiscall sub_40A680(_DWORD *this, int a2)
{
  int v2; // ebx
  int v4; // eax
  char *v5; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  int v15; // eax
  char *v16; // eax
  int v17; // eax
  char *v18; // eax
  int v19; // eax
  char *v20; // eax
  int v21; // edi
  char *v22; // eax
  int v23; // [esp+10h] [ebp-4h]

  v2 = 0;
  v23 = 0;
  if ( a2 )
  {
    v4 = this[4];
    if ( v4 )
    {
      v5 = *(char **)(v4 + 4);
      if ( !v5 )
        v5 = &byte_5EA438;
      if ( !sub_588410(v5, a2) )
        return this[4];
    }
    v7 = this[5];
    if ( v7 )
    {
      v8 = *(char **)(v7 + 4);
      if ( !v8 )
        v8 = &byte_5EA438;
      if ( !sub_588410(v8, a2) )
        return this[5];
    }
    v9 = this[6];
    if ( v9 )
    {
      v10 = *(char **)(v9 + 4);
      if ( !v10 )
        v10 = &byte_5EA438;
      if ( !sub_588410(v10, a2) )
        return this[6];
    }
    v11 = this[7];
    if ( v11 )
    {
      v12 = *(char **)(v11 + 4);
      if ( !v12 )
        v12 = &byte_5EA438;
      if ( !sub_588410(v12, a2) )
        return this[7];
    }
    v13 = this[9];
    if ( v13 )
    {
      v14 = *(char **)(v13 + 4);
      if ( !v14 )
        v14 = &byte_5EA438;
      if ( !sub_588410(v14, a2) )
        return this[9];
    }
    v15 = this[10];
    if ( v15 )
    {
      v16 = *(char **)(v15 + 4);
      if ( !v16 )
        v16 = &byte_5EA438;
      if ( !sub_588410(v16, a2) )
        return this[10];
    }
    v17 = this[11];
    if ( v17 )
    {
      v18 = *(char **)(v17 + 4);
      if ( !v18 )
        v18 = &byte_5EA438;
      if ( !sub_588410(v18, a2) )
        return this[11];
    }
    v19 = this[12];
    if ( v19 )
    {
      v20 = *(char **)(v19 + 4);
      if ( !v20 )
        v20 = &byte_5EA438;
      if ( !sub_588410(v20, a2) )
        return this[12];
    }
    v21 = 0;
    if ( (int)this[14] > 0 )
    {
      while ( 1 )
      {
        v22 = *(char **)(this[8] + v2 + 4);
        if ( !v22 )
          v22 = &byte_5EA438;
        if ( !sub_588410(v22, a2) )
          break;
        ++v21;
        v2 += 200;
        if ( v21 >= this[14] )
          return 0;
      }
      return this[8] + 200 * v21;
    }
  }
  return v23;
}

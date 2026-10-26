int __thiscall sub_411120(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  char *v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  char *v14; // eax
  char v15; // cl
  int result; // eax
  int v17; // edi
  int v18; // ebx
  int *v19; // eax
  float v20; // [esp+0h] [ebp-10h]
  float v21; // [esp+0h] [ebp-10h]
  float v22; // [esp+0h] [ebp-10h]
  float v23; // [esp+0h] [ebp-10h]
  float v24; // [esp+0h] [ebp-10h]
  float v25; // [esp+0h] [ebp-10h]

  v2 = 0;
  if ( (int)this[9] > 0 )
  {
    v3 = 0;
    do
    {
      v20 = dbl_8AFEA0;
      ModeDispatchedRenderPhysicsCall((_DWORD *)(v3 + this[10]), v20);
      ++v2;
      v3 += 36;
    }
    while ( v2 < this[9] );
  }
  v4 = 0;
  if ( (int)this[12] > 0 )
  {
    v5 = 0;
    do
    {
      v21 = dbl_8AFEA0;
      ModeDispatchedRenderPhysicsCall((_DWORD *)(v5 + this[13]), v21);
      ++v4;
      v5 += 36;
    }
    while ( v4 < this[12] );
  }
  v6 = 0;
  if ( (int)this[15] > 0 )
  {
    v7 = 0;
    do
    {
      v22 = dbl_8AFEA0;
      ModeDispatchedRenderPhysicsCall((_DWORD *)(v7 + this[16]), v22);
      ++v6;
      v7 += 36;
    }
    while ( v6 < this[15] );
  }
  v8 = 0;
  if ( (int)this[18] > 0 )
  {
    v9 = 0;
    do
    {
      if ( v9 >= 14976
        || (v10 = (char *)&unk_5EC6D8 + 18624 * (v8 / 4), *((_DWORD *)v10 + 3250) == -1)
        || (v11 = (int)&v10[296 * (v8 % 4) + 2100], !*(_DWORD *)v11)
        || !*(_BYTE *)(v11 + 64) )
      {
        v23 = dbl_8AFEA0;
        ModeDispatchedRenderPhysicsCall((_DWORD *)(v9 + this[19]), v23);
      }
      ++v8;
      v9 += 36;
    }
    while ( v8 < this[18] );
  }
  v12 = 0;
  if ( (int)this[21] > 0 )
  {
    v13 = 0;
    while ( v13 < 7488 )
    {
      v14 = (char *)&unk_5EC6D8 + 18624 * (v12 / 2);
      if ( v12 % 2 )
      {
        if ( !*((_DWORD *)v14 + 838) )
          break;
        v15 = v14[3416];
      }
      else
      {
        if ( !*((_DWORD *)v14 + 821) )
          break;
        v15 = v14[3348];
      }
      if ( !v15 )
        break;
LABEL_28:
      ++v12;
      v13 += 36;
      if ( v12 >= this[21] )
        goto LABEL_29;
    }
    v24 = dbl_8AFEA0;
    ModeDispatchedRenderPhysicsCall((_DWORD *)(v13 + this[22]), v24);
    goto LABEL_28;
  }
LABEL_29:
  result = this[24];
  v17 = 0;
  if ( result > 0 )
  {
    v18 = 0;
    do
    {
      if ( v18 >= 29952 || (v19 = &dword_5ED434[4656 * (v17 / 8) + 17 * (v17 % 8)], !*v19) || !*((_BYTE *)v19 + 64) )
      {
        v25 = dbl_8AFEA0;
        ModeDispatchedRenderPhysicsCall((_DWORD *)(v18 + this[25]), v25);
      }
      result = this[24];
      ++v17;
      v18 += 36;
    }
    while ( v17 < result );
  }
  return result;
}

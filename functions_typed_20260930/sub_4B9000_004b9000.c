int *__thiscall sub_4B9000(char *this, float a2)
{
  char *v2; // ebx
  int i; // edi
  float *v4; // eax
  float *v5; // esi
  float **v6; // eax
  float *v7; // eax
  float **v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // esi
  int *v12; // eax
  int v13; // eax
  int *v14; // eax
  int *v15; // edx
  int j; // ecx
  int *v17; // eax
  int v18; // eax
  int *v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // eax
  int *v25; // eax
  int v26; // esi
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // edi
  int v33; // eax
  int v34; // esi
  int v35; // eax
  int v36; // eax
  int *v37; // eax
  _DWORD *v40; // [esp+10h] [ebp-368h]
  int v41; // [esp+14h] [ebp-364h]
  int v42; // [esp+14h] [ebp-364h]
  int *v43; // [esp+18h] [ebp-360h]
  int v44[3]; // [esp+1Ch] [ebp-35Ch] BYREF
  int v45[212]; // [esp+28h] [ebp-350h] BYREF

  v2 = this;
  for ( i = 0; i < 104; ++i )
  {
    v4 = LinkedListTraversalWithFilter(v2, i, a2);
    v5 = v4;
    v45[i + 108] = (int)v4;
    if ( v4 )
    {
      if ( FieldCompareConstant(v4 + 36)
        && v5[147] <= (double)a2
        && FloatComparisonCheck(v5 + 36)
        && v5[39] >= (double)a2 )
      {
        v45[i + 108] = 0;
      }
      else
      {
        ThunkWithStructInitSubCalls(v5 + 36);
      }
      v2 = this;
    }
  }
  v40 = v2 + 3908;
  FloatComparisonListIteration((int)(v2 + 3908), a2);
  v6 = (float **)*((_DWORD *)v2 + 455);
  if ( v6 && (v7 = *v6) != 0
    || (*((float *)v2 + 973) - *((float *)v2 + 972) + *((float *)v2 + 972) >= a2
      ? (v8 = (float **)*((_DWORD *)v2 + 453))
      : (v8 = (float **)*((_DWORD *)v2 + 454)),
        (*((_DWORD *)v2 + 455) = v8) != 0 && (v7 = *v8) != 0) )
  {
    if ( *v7 <= (double)a2 )
    {
      while ( 1 )
      {
        v13 = *((_DWORD *)v2 + 455);
        if ( !v13 )
          break;
        v14 = *(int **)(v13 + 4);
        *((_DWORD *)v2 + 455) = v14;
        if ( !v14 )
          break;
        v11 = *v14;
        if ( !*v14 )
          break;
        if ( *(float *)v11 >= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 454);
    }
    else
    {
      while ( 1 )
      {
        v9 = *((_DWORD *)v2 + 455);
        if ( !v9 )
          break;
        v10 = *(int **)(v9 + 8);
        *((_DWORD *)v2 + 455) = v10;
        if ( !v10 )
          break;
        v11 = *v10;
        if ( !*v10 )
          break;
        if ( *(float *)v11 <= (double)a2 )
          goto LABEL_34;
      }
      v12 = (int *)*((_DWORD *)v2 + 453);
    }
    *((_DWORD *)v2 + 455) = v12;
    if ( v12 )
      v11 = *v12;
    else
      v11 = 0;
LABEL_34:
    v15 = (int *)*((_DWORD *)v2 + 455);
    j = -1;
    v43 = v15;
    if ( v15 )
    {
      v17 = (int *)*((_DWORD *)v2 + 453);
      for ( j = 0; v17; ++j )
      {
        if ( v17 == v15 )
          break;
        v17 = (int *)v17[1];
      }
    }
    if ( j < *((_DWORD *)v2 + 456) - 1 && v11 )
    {
      while ( *(float *)v11 < (double)a2 )
      {
        v18 = *((_DWORD *)v2 + 455);
        if ( v18 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v18 + 4);
        v19 = (int *)*((_DWORD *)v2 + 455);
        if ( !v19 )
        {
          v11 = 0;
          break;
        }
        v11 = *v19;
        if ( !*v19 )
          break;
      }
    }
    v41 = 0;
    if ( v11 )
    {
      do
      {
        sub_566DB0((int *)v2 + 441, *(_DWORD *)(v11 + 4));
        WrapperPassThrough(v44);
        sub_4B44A0(v44, (int)(v2 + 1764));
        if ( ++v41 > 64 )
          break;
        v20 = 0;
        if ( *(_WORD *)(v11 + 8) )
        {
          do
          {
            StreamReadWithScale((int)(v2 + 1764), *(float *)v11, (int)v45);
            if ( (v45[0] & 0xE0000000) == 0x20000000 )
            {
              if ( (((unsigned int)v45[0] >> 18) & 0x3F) != 0 )
              {
                if ( (((unsigned int)v45[0] >> 18) & 0x3F) <= 6 )
                  NetworkMessageDispatch((int)v40, (int)v45);
              }
              else if ( LOBYTE(v45[0]) < 0x68u )
              {
                v21 = v45[LOBYTE(v45[0]) + 108];
                if ( v21 )
                  ZoneThresholdComparisonWithConditionalAction(v21 + 144, a2, (int)v45);
              }
            }
            ++v20;
          }
          while ( v20 < *(unsigned __int16 *)(v11 + 8) );
        }
        v22 = 0;
        while ( 1 )
        {
          v23 = v45[v22 + 108];
          if ( v23 )
          {
            if ( !FieldCompareConstant((float *)(v23 + 144)) )
              break;
          }
          if ( ++v22 >= 104 )
          {
            if ( v41 >= 64 || ListWalkWithUserCancelCheck(v40) )
              goto LABEL_68;
            break;
          }
        }
        v24 = *((_DWORD *)v2 + 455);
        if ( v24 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v24 + 8);
        v25 = (int *)*((_DWORD *)v2 + 455);
        if ( !v25 )
          break;
        v11 = *v25;
      }
      while ( *v25 );
    }
LABEL_68:
    *((_DWORD *)v2 + 455) = v43;
    if ( v43 )
      v26 = *v43;
    else
      v26 = 0;
    v27 = *((_DWORD *)v2 + 455);
    if ( v27 )
    {
      v28 = *((_DWORD *)v2 + 453);
      v29 = 0;
      if ( v28 )
      {
        do
        {
          if ( v28 == v27 )
            break;
          v28 = *(_DWORD *)(v28 + 4);
          ++v29;
        }
        while ( v28 );
        if ( v29 > 0 && v26 )
        {
          while ( *(float *)v26 > (double)a2 )
          {
            v30 = *((_DWORD *)v2 + 455);
            if ( v30 )
              *((_DWORD *)v2 + 455) = *(_DWORD *)(v30 + 8);
            v31 = (int *)*((_DWORD *)v2 + 455);
            if ( !v31 )
            {
              v26 = 0;
              break;
            }
            v26 = *v31;
            if ( !*v31 )
              break;
          }
        }
      }
    }
    v42 = 0;
    if ( v26 )
    {
      do
      {
        sub_566DB0((int *)v2 + 441, *(_DWORD *)(v26 + 4));
        WrapperPassThrough(v44);
        sub_4B44A0(v44, (int)(v2 + 1764));
        if ( ++v42 > 64 )
          break;
        v32 = 0;
        if ( *(_WORD *)(v26 + 8) )
        {
          do
          {
            StreamReadWithScale((int)(v2 + 1764), *(float *)v26, (int)v45);
            if ( (v45[0] & 0xE0000000) == 0x20000000 )
            {
              if ( (((unsigned int)v45[0] >> 18) & 0x3F) != 0 )
              {
                if ( (((unsigned int)v45[0] >> 18) & 0x3F) <= 6 )
                  NetworkMessageDispatch((int)v40, (int)v45);
              }
              else if ( LOBYTE(v45[0]) < 0x68u )
              {
                v33 = v45[LOBYTE(v45[0]) + 108];
                if ( v33 )
                  ZoneThresholdComparisonWithConditionalAction(v33 + 144, a2, (int)v45);
              }
            }
            ++v32;
          }
          while ( v32 < *(unsigned __int16 *)(v26 + 8) );
        }
        v34 = 0;
        while ( 1 )
        {
          v35 = v45[v34 + 108];
          if ( v35 )
          {
            if ( !FloatComparisonCheck((float *)(v35 + 144)) )
              break;
          }
          if ( ++v34 >= 104 )
          {
            if ( v42 >= 64 || LinkedListValidationWalk(v40) )
              goto LABEL_105;
            break;
          }
        }
        v36 = *((_DWORD *)v2 + 455);
        if ( v36 )
          *((_DWORD *)v2 + 455) = *(_DWORD *)(v36 + 4);
        v37 = (int *)*((_DWORD *)v2 + 455);
        if ( !v37 )
          break;
        v26 = *v37;
      }
      while ( *v37 );
    }
  }
LABEL_105:
  CollisionFilterAABBCull((int)v40);
  return LinkedListIteratorWithStateUpdate((int)v40);
}


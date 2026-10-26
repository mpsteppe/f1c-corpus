int __thiscall sub_540940(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  int v5; // ecx
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // ebp
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  _DWORD *i; // eax
  _DWORD *v15; // eax
  int v16; // eax
  _DWORD *v17; // ebp
  int v19; // edx
  int v20; // ecx
  unsigned int *v21; // eax
  unsigned int *v22; // esi
  unsigned int *v23; // eax
  unsigned int v24; // esi
  unsigned int j; // eax
  _DWORD *v26; // eax
  unsigned int v27; // eax
  int v28; // ecx
  int v29; // [esp-4h] [ebp-1Ch]
  int v30; // [esp+10h] [ebp-8h]
  int v32; // [esp+1Ch] [ebp+4h]

  v3 = (_DWORD *)OperatorNewNhMallocWrapper(36);
  if ( v3 )
  {
    v3[5] = 0;
    v3[4] = 0;
    v3[3] = 0;
    v3[2] = 0;
    v3[1] = 0;
    *v3 = 0;
    v3[7] = 0;
    v3[6] = 0;
    v3[8] = 0;
  }
  else
  {
    v3 = 0;
  }
  v5 = a2[14];
  a2[7] = v3;
  *v3 = v5;
  *(_DWORD *)(a2[7] + 12) = a2[2];
  *(_DWORD *)(a2[7] + 8) = 64;
  *(_DWORD *)(a2[7] + 4) = 1234;
  v6 = (unsigned int *)OperatorNewNhMallocWrapper(28);
  if ( v6 )
  {
    v6[3] = 0;
    v6[2] = 0;
    v6[1] = 0;
    *v6 = 0;
    v6[5] = 0;
    v6[4] = 0;
    v6[6] = 0;
  }
  else
  {
    v6 = 0;
  }
  v7 = a2[14];
  a2[9] = v6;
  if ( (v7 & 0x20) != 0 )
    v7 = v7 & 0xFFFFFFDD | 2;
  *v6 = v7;
  *(_DWORD *)(a2[9] + 4) = a2[4];
  if ( this[1271] )
  {
    if ( (a2[14] & 0x20) != 0 )
    {
      v8 = this + 1111;
      v32 = this[1110];
    }
    else
    {
      v8 = this + 1109;
      v32 = this[1108];
    }
    v30 = this[1112];
    v9 = a2[2];
    if ( v9 > v32 )
      v32 = a2[2];
    v10 = (_DWORD *)*v8;
    v11 = (_DWORD *)*v8;
    if ( *v8 )
    {
      while ( v9 > v11[3] - v11[4] )
      {
        v11 = (_DWORD *)v11[7];
        if ( !v11 )
          goto LABEL_18;
      }
      v17 = this;
    }
    else
    {
LABEL_18:
      if ( v10 )
      {
        v13 = (_DWORD *)*v8;
        for ( i = (_DWORD *)v10[7]; i; i = (_DWORD *)i[7] )
          v13 = i;
        v15 = (_DWORD *)OperatorNewNhMallocWrapper(36);
        if ( v15 )
        {
          v15[5] = 0;
          v15[4] = 0;
          v15[3] = 0;
          v15[2] = 0;
          v15[1] = 0;
          *v15 = 0;
          v15[7] = 0;
          v15[6] = 0;
          v15[8] = 0;
        }
        else
        {
          v15 = 0;
        }
        v13[7] = v15;
        v15[6] = v13;
        v11 = (_DWORD *)v13[7];
      }
      else
      {
        v12 = (_DWORD *)OperatorNewNhMallocWrapper(36);
        if ( v12 )
        {
          v12[5] = 0;
          v12[4] = 0;
          v12[3] = 0;
          v12[2] = 0;
          v12[1] = 0;
          *v12 = 0;
          v12[7] = 0;
          v12[6] = 0;
          v12[8] = 0;
          *v8 = v12;
          v11 = v12;
        }
        else
        {
          *v8 = 0;
          v11 = 0;
        }
      }
      v16 = a2[14];
      v17 = this;
      v11[3] = v32;
      *v11 = v16;
      v11[2] = 64;
      v11[1] = 1234;
      if ( sub_540DF0(v11) )
        return -1;
    }
    *(_DWORD *)(a2[7] + 32) = v11[8];
    v19 = a2[2];
    a2[11] = v11[4];
    v11[4] += v19;
    v20 = a2[4];
    if ( v20 > v30 )
      v30 = a2[4];
    v21 = (unsigned int *)v17[1113];
    v22 = v21;
    if ( v21 )
    {
      while ( v20 > (int)(v22[1] - v22[2]) )
      {
        v22 = (unsigned int *)v22[5];
        if ( !v22 )
          goto LABEL_36;
      }
    }
    else
    {
LABEL_36:
      if ( v21 )
      {
        v24 = v17[1113];
        for ( j = v21[5]; j; j = *(_DWORD *)(j + 20) )
          v24 = j;
        v26 = (_DWORD *)OperatorNewNhMallocWrapper(28);
        if ( v26 )
        {
          v26[3] = 0;
          v26[2] = 0;
          v26[1] = 0;
          *v26 = 0;
          v26[5] = 0;
          v26[4] = 0;
          v26[6] = 0;
        }
        else
        {
          v26 = 0;
        }
        *(_DWORD *)(v24 + 20) = v26;
        v26[4] = v24;
        v22 = *(unsigned int **)(v24 + 20);
      }
      else
      {
        v23 = (unsigned int *)OperatorNewNhMallocWrapper(28);
        if ( v23 )
        {
          v23[3] = 0;
          v23[2] = 0;
          v23[1] = 0;
          *v23 = 0;
          v23[5] = 0;
          v23[4] = 0;
          v23[6] = 0;
          v17[1113] = v23;
          v22 = v23;
        }
        else
        {
          v17[1113] = 0;
          v22 = 0;
        }
      }
      v27 = a2[14];
      if ( (v27 & 0x20) != 0 )
        v27 = v27 & 0xFFFFFFDD | 2;
      *v22 = v27;
      v22[1] = v30;
      if ( sub_540FC0(v22) )
        return -1;
    }
    *(_DWORD *)(a2[9] + 24) = v22[6];
    v28 = a2[4];
    a2[12] = v22[2];
    v22[2] += v28;
    return 0;
  }
  else if ( sub_540DF0(a2[7]) || (v29 = a2[9], a2[11] = 0, sub_540FC0(v29)) )
  {
    sub_53C590(-1, aErrorCreatingV);
    return -1;
  }
  else
  {
    a2[12] = 0;
    return 0;
  }
}


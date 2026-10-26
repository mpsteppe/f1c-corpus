void __usercall sub_531060(int a1@<ebx>)
{
  int v1; // ebx
  int v2; // eax
  float v3; // edi
  char *v4; // ebp
  int v5; // esi
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  float *v11; // ecx
  int v12; // edi
  float *v13; // esi
  int v14; // edx
  char *v15; // ecx
  int v16; // ebp
  int v17; // edi
  _DWORD *v18; // esi
  int v19; // ebx
  int v21; // [esp+4h] [ebp-4F0h]
  int v22; // [esp+8h] [ebp-4ECh]
  int v23; // [esp+Ch] [ebp-4E8h]
  int v24; // [esp+10h] [ebp-4E4h]
  float v26[311]; // [esp+18h] [ebp-4DCh] BYREF

  if ( *(int *)dword_B72314 <= 0 || *(int *)dword_B72314 > 5 )
    return;
  v1 = dword_757C10;
  v2 = 0;
  if ( dword_B71F48 == 105 )
  {
    v3 = 0.0;
    if ( dword_757C10 > 0 )
    {
      do
      {
        if ( v3 == 0.0 && (_BYTE)dword_757C1C )
        {
          v4 = dword_B6F740;
          if ( !dword_B6F740 )
            v4 = (char *)WindowName;
        }
        else
        {
          v4 = (char *)&unk_9204A0
             + 22616 * LODWORD(v3)
             + 108 * *((_DWORD *)&unk_9204A0 + 5654 * LODWORD(v3) + 5447)
             + 21568;
        }
        SLODWORD(v26[3 * LODWORD(v3) - 1]) = sub_5302D0(v4);
        v26[3 * LODWORD(v3)] = sub_530340(v4);
        v26[3 * LODWORD(v3)++ + 1] = v3;
      }
      while ( SLODWORD(v3) < v1 );
    }
    v5 = 0;
    if ( v1 > 0 )
    {
      v6 = 0;
      v21 = 0;
      do
      {
        v7 = v5;
        v8 = v5;
        if ( v5 < v1 )
        {
          v9 = v6;
          do
          {
            if ( *(int *)((char *)&v26[-1] + v6) < *(int *)((char *)&v26[-1] + v9) )
            {
              v7 = v8;
              v9 = v6;
            }
            ++v8;
            v6 += 12;
          }
          while ( v8 < v1 );
          v6 = v21;
        }
        v10 = (int *)((char *)&v26[-1] + v6);
        v22 = *(int *)((char *)&v26[-1] + v6);
        v24 = *(_DWORD *)((char *)&v26[1] + v6);
        v11 = &v26[3 * v7 - 1];
        v23 = *(int *)((char *)v26 + v6);
        *v10 = *(_DWORD *)v11;
        v10[1] = *((_DWORD *)v11 + 1);
        v10[2] = *((_DWORD *)v11 + 2);
        *(_DWORD *)v11 = v22;
        *((_DWORD *)v11 + 1) = v23;
        ++v5;
        v6 += 12;
        *((_DWORD *)v11 + 2) = v24;
        v21 = v6;
      }
      while ( v5 < v1 );
      v12 = 1;
      v13 = v26;
      do
      {
        v14 = *(_DWORD *)v13;
        v15 = (char *)&unk_924FE8 + 22616 * *((_DWORD *)v13 + 1);
        *((_DWORD *)v15 + 11) = v12;
        *((_DWORD *)v15 + 12) = v14;
        sub_52C360(v12);
        v13 += 3;
        ++v12;
        --v1;
      }
      while ( v1 );
    }
    return;
  }
  v16 = -1;
  v17 = 1;
  if ( (_BYTE)dword_757C1C )
  {
    v16 = dword_B71F48;
    if ( !dword_B71F48 )
    {
      if ( *(_DWORD *)dword_B72314 == 4 )
        goto LABEL_28;
      v16 = rand() % v1 + 1;
    }
    if ( v16 >= 1 )
    {
      if ( v16 > v1 )
        v16 = v1;
      goto LABEL_31;
    }
LABEL_28:
    v16 = 1;
LABEL_31:
    *(_DWORD *)(dword_91E084 + 19316) = v16;
    *(_DWORD *)(dword_91E084 + 19320) = -1082130432;
    sub_52C360(v16);
    v2 = a1;
  }
  if ( v2 < v1 )
  {
    v18 = (_DWORD *)((char *)&unk_925018 + 22616 * v2);
    v19 = v1 - v2;
    do
    {
      if ( v17 == v16 )
        ++v17;
      *(v18 - 1) = v17;
      *v18 = -1082130432;
      sub_52C360(v17++);
      v18 += 5654;
      --v19;
    }
    while ( v19 );
  }
}

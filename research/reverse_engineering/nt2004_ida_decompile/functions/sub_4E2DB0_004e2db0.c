void __usercall sub_4E2DB0(double a1@<st0>)
{
  signed int v1; // ebx
  int v2; // esi
  int *v3; // edi
  signed int v4; // ebx
  int v5; // ebp
  char *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ebp
  char *v10; // eax
  char *v11; // esi
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  int v15; // edi
  _DWORD *v16; // esi
  int v17; // ebx
  int v18; // [esp+10h] [ebp-4h]

  if ( *(int *)dword_7689CC <= 0 )
    return;
  if ( *(int *)dword_7689CC > 5 )
  {
    if ( *(_DWORD *)dword_7689CC == 6 )
    {
      v1 = NumOfElements;
      if ( (int)NumOfElements > 0 )
      {
        v2 = 1;
        v3 = dword_75AAD0;
        do
        {
          *(_DWORD *)(*v3 + 20876) = v2;
          *(_DWORD *)(*v3 + 20880) = -1082130432;
          sub_4DEB20((int *)(*v3++ + 20836), v2++);
        }
        while ( v2 - 1 < v1 );
      }
    }
    return;
  }
  v4 = NumOfElements;
  v5 = 0;
  if ( dword_7685F4 == 44 )
  {
    if ( sub_42DBA0() )
    {
      v6 = sub_410E00(&dword_76662C);
      v7 = sub_4E3130(v6);
      v8 = v7;
      if ( v7 >= 1 )
      {
        if ( v7 > v4 )
          v8 = v4;
      }
      else
      {
        v8 = 1;
      }
      *(_DWORD *)(dword_75AACC + 20876) = v8;
      v9 = dword_75AACC;
      v10 = sub_410E00(&dword_76662C);
      sub_4E32F0(v10);
      *(float *)(v9 + 20880) = a1;
      sub_4DEB20((int *)(dword_75AACC + 20836), v8);
      v5 = 1;
    }
    if ( v5 < v4 )
    {
      v11 = (char *)&unk_63202C + 25304 * v5;
      v12 = v4 - v5;
      do
      {
        v13 = sub_4E3130(v11);
        *((_DWORD *)v11 - 974) = v13;
        sub_4E32F0(v11);
        *((float *)v11 - 973) = a1;
        sub_4DEB20((int *)v11 - 984, v13);
        v11 += 25304;
        --v12;
      }
      while ( v12 );
    }
    return;
  }
  v18 = -1;
  if ( sub_42DBA0() )
  {
    v14 = dword_7685F4;
    v5 = 1;
    v18 = dword_7685F4;
    if ( !dword_7685F4 )
    {
      v18 = rand() % v4 + 1;
      v14 = v18;
    }
    if ( v14 >= 1 )
    {
      if ( v14 <= v4 )
      {
LABEL_27:
        *(_DWORD *)(dword_75AACC + 20876) = v14;
        *(_DWORD *)(dword_75AACC + 20880) = -1082130432;
        sub_4DEB20((int *)(dword_75AACC + 20836), v14);
        goto LABEL_28;
      }
      v18 = v4;
    }
    else
    {
      v18 = 1;
    }
    v14 = v18;
    goto LABEL_27;
  }
LABEL_28:
  v15 = 1;
  if ( v5 < v4 )
  {
    v16 = (_DWORD *)((char *)&unk_6310F8 + 25304 * v5);
    v17 = v4 - v5;
    do
    {
      if ( v15 == v18 )
        ++v15;
      *(v16 - 1) = v15;
      *v16 = -1082130432;
      sub_4DEB20(v16 - 11, v15++);
      v16 += 6326;
      --v17;
    }
    while ( v17 );
  }
}

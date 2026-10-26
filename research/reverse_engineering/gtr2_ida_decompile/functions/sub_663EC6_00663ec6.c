int __thiscall sub_663EC6(
        _DWORD *this,
        _DWORD *a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6,
        int a7,
        int *a8,
        _DWORD *a9)
{
  int v9; // ebx
  _DWORD *v11; // esi
  int result; // eax
  int v13; // eax
  _DWORD *v14; // eax
  unsigned int *v15; // ebx
  int v16; // [esp+Ch] [ebp-8h] BYREF
  int v17; // [esp+10h] [ebp-4h] BYREF

  v9 = 0;
  v17 = 0;
  v16 = 0;
  if ( !a8 )
    a8 = &v16;
  v11 = a2;
  if ( !a2 )
    goto LABEL_34;
  if ( a2[1] == 1 )
  {
    v15 = a3;
    result = sub_663EC6(a2[2], a3, a4, a5, a6, a7, a8, &a3);
    if ( result < 0 )
      return result;
    result = sub_663EC6(v11[3], &v15[(_DWORD)a3], a4, a5, a6, a7, a8, &a2);
    if ( result < 0 )
      return result;
    v17 = (int)a2 + (_DWORD)a3;
    goto LABEL_34;
  }
  if ( a2[1] == 6 )
  {
    result = sub_663EC6(a2[6], a3, a4, a5, a6, a7, a8, &v17);
    goto LABEL_11;
  }
  if ( a2[1] != 8 )
  {
    if ( a2[1] == 9 )
    {
      if ( a2[4] == 3 )
      {
        if ( a6 )
        {
          v13 = *(_DWORD *)(*(_DWORD *)(this[2] + 16) + 4 * a4);
          *(_BYTE *)(v13 + 4) |= 0x80u;
        }
        else
        {
          a4 = sub_681A51("s", 721, -1, 4);
        }
      }
      result = sub_6624E8(this, v11[4], v11[6], v11[7], v11[8], a3, a4, a8, a7, &v17);
    }
    else
    {
      if ( a2[1] != 11 )
      {
        sub_663C07(this, 0, 0, "internal error: unknown node");
LABEL_34:
        if ( a9 )
          *a9 = v17;
        return 0;
      }
      result = sub_664A70(a2[8], a3, a4, a5, a6, a7, a8, a2[11], a2[12], &v17);
    }
LABEL_11:
    if ( result < 0 )
      return result;
    goto LABEL_34;
  }
  if ( !a6 )
  {
    v14 = a2;
    do
    {
      if ( v14[1] != 8 )
        break;
      v14 = (_DWORD *)v14[4];
    }
    while ( v14 );
    if ( v14 && v14[1] == 9 && v14[4] == 3 )
    {
      a4 = sub_681A51("s", 721, -1, 4);
      a6 = 1;
    }
  }
  if ( !v11[5] )
    goto LABEL_34;
  while ( 1 )
  {
    result = sub_663EC6(v11[4], &a3[v17], a4, a5, a6, a7, a8, &a2);
    if ( result < 0 )
      return result;
    v17 += (int)a2;
    if ( (unsigned int)++v9 >= v11[5] )
      goto LABEL_34;
  }
}

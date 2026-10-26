int __userpurge sub_4DFAA0@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3@<esi>, _DWORD *a4, int a5)
{
  int v5; // ebp
  int result; // eax
  int v7; // esi
  int i; // edi
  int v9; // ebp
  int j; // esi
  int v11; // [esp+4h] [ebp-1Ch]
  int v12; // [esp+8h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+14h] [ebp-Ch]
  int *v15; // [esp+18h] [ebp-8h]

  v5 = a1[6];
  v15 = (int *)a1[22];
  result = 0;
  v14 = a1[23];
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    return off_16C956C(a4, a5);
  if ( v5 )
  {
    v12 = a3;
    v7 = *(_DWORD *)(v5 + 64);
    v11 = a2;
    for ( i = 0; v7; v7 = sub_4CD340() )
    {
      if ( (*(int (__thiscall **)(int, int *, int, int, int))(*(_DWORD *)v7 + 20))(v7, v15, v14, v11, v12) )
      {
        i = v7;
        if ( a4 )
          *a4 = v5;
      }
    }
    if ( *(_DWORD *)(v5 + 68) && !i )
    {
      v9 = *(_DWORD *)(v5 + 68);
      if ( (unsigned __int8)sub_4DF840() )
        v9 = sub_4DF700();
      for ( j = *(_DWORD *)(v9 + 52); j; j = sub_4CD340() )
      {
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)j + 20))(j) )
          i = j;
      }
      if ( a4 )
        *a4 = v13;
      if ( v15 )
        *v15 = v9;
    }
    return i;
  }
  return result;
}

int **__thiscall sub_5A31E0(_DWORD *this, int **a2, int *a3, int *a4)
{
  int *v4; // esi
  int v6; // eax
  _DWORD *v7; // eax
  int **result; // eax
  int **v9; // eax
  int *j; // eax
  int *i; // eax
  int **v12; // [esp+8h] [ebp-4h]

  v4 = a3;
  v6 = this[1];
  if ( a3 == *(int **)v6 && a4 == (int *)v6 )
  {
    sub_59EA90(*(void ***)(v6 + 4));
    *(_DWORD *)(this[1] + 4) = this[1];
    v7 = (_DWORD *)this[1];
    this[2] = 0;
    *v7 = v7;
    *(_DWORD *)(this[1] + 8) = this[1];
    result = a2;
    *a2 = *(int **)this[1];
  }
  else
  {
    if ( a3 != a4 )
    {
      do
      {
        if ( !*((_BYTE *)v4 + 21) )
        {
          v9 = (int **)v4[2];
          if ( *((_BYTE *)v9 + 21) )
          {
            for ( i = (int *)v4[1]; !*((_BYTE *)i + 21); i = (int *)i[1] )
            {
              if ( v4 != (int *)i[2] )
                break;
              v4 = i;
            }
            v4 = i;
          }
          else
          {
            v4 = (int *)v4[2];
            for ( j = *v9; !*((_BYTE *)j + 21); j = (int *)*j )
              v4 = j;
          }
        }
        sub_5A28F0();
      }
      while ( v4 != a4 );
    }
    result = v12;
    *v12 = v4;
  }
  return result;
}

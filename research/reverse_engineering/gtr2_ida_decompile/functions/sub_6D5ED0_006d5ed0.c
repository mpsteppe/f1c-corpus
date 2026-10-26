int __stdcall sub_6D5ED0(int *a1)
{
  BOOL v2; // ecx
  int result; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // edx
  int *v7; // edi
  _DWORD v9[4]; // [esp+4h] [ebp-20h] BYREF
  BOOL v10; // [esp+14h] [ebp-10h]
  _DWORD *v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]
  int *i; // [esp+2Ch] [ebp+8h]

  v12 = a1[93];
  sub_6D5640(v12);
  v2 = a1[81] == 0;
  memset(v9, 0, sizeof(v9));
  v13 = 0;
  result = a1[63];
  v10 = v2;
  if ( result > 0 )
  {
    for ( i = a1 + 64; ; ++i )
    {
      v4 = *i;
      if ( !v2 )
        break;
      if ( !a1[83] )
      {
        v5 = *(_DWORD *)(v4 + 20);
        goto LABEL_7;
      }
LABEL_13:
      result = v13 + 1;
      if ( ++v13 >= a1[63] )
        return result;
    }
    v5 = *(_DWORD *)(v4 + 24);
LABEL_7:
    v6 = v9[v5];
    v11 = &v9[v5];
    if ( !v6 )
    {
      v7 = &a1[v5 + 22];
      if ( !v2 )
        v7 = &a1[v5 + 26];
      if ( !*v7 )
        *v7 = sub_6B5F80((int)a1);
      sub_6D4FF0(a1, *v7, *(_DWORD *)(v12 + 4 * v5 + 92));
      *v11 = 1;
      v2 = v10;
    }
    goto LABEL_13;
  }
  return result;
}

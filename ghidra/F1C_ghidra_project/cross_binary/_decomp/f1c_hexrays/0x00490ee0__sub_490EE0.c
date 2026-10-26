// f1c  0x00490ee0  size=483
char __stdcall sub_490EE0(void ***a1, __int16 a2, __int16 a3, __int16 a4, __int16 a5)
{
  __int16 *v5; // edi
  void **v6; // eax
  bool v7; // zf
  void *v8; // ebp
  int i; // edi
  _DWORD *v10; // eax
  void **v11; // ecx
  void **v12; // eax
  void **v13; // eax
  void *v14; // edx
  void **v15; // eax
  int *v16; // eax
  int j; // eax
  int *v19; // [esp+14h] [ebp-10h] BYREF
  int *v20; // [esp+18h] [ebp-Ch]
  int *v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]
  __int16 *v23; // [esp+38h] [ebp+14h]

  v5 = (__int16 *)sub_490940(a2, a3, a4, a5);
  v6 = *a1;
  v7 = *a1 == 0;
  v23 = v5;
  a1[2] = *a1;
  if ( !v7 )
  {
    v8 = *v6;
    if ( *v6 )
    {
      while ( 1 )
      {
        if ( (unsigned __int8)sub_491680(*v5, v5[1], v5[2], v5[3]) )
        {
          for ( i = sub_491350(*v23, v23[1], v23[2], v23[3]); i; i = *(_DWORD *)(i + 12) )
          {
            v10 = (_DWORD *)sub_587C03(12);
            if ( v10 )
            {
              *v10 = i;
              v10[1] = 0;
              *((_BYTE *)v10 + 8) = 0;
            }
            else
            {
              v10 = 0;
            }
            if ( *a1 )
            {
              a1[1][1] = v10;
            }
            else
            {
              *a1 = (void **)v10;
              a1[2] = (void **)v10;
            }
            a1[1] = (void **)v10;
            a1[3] = (void **)((char *)a1[3] + 1);
          }
          v11 = *a1;
          v12 = 0;
          if ( *a1 )
          {
            while ( *v11 != v8 )
            {
              v12 = v11;
              v11 = (void **)v11[1];
              if ( !v11 )
                goto LABEL_17;
            }
            if ( v11 == a1[2] )
              a1[2] = (void **)v11[1];
            v14 = v11[1];
            if ( v12 )
              v12[1] = v14;
            else
              *a1 = (void **)v14;
            if ( a1[1] == v11 )
              a1[1] = v12;
            a1[3] = (void **)((char *)a1[3] - 1);
            sub_491E10(1);
          }
LABEL_17:
          sub_490AA0(v8);
          v13 = a1[2];
        }
        else
        {
          v15 = a1[2];
          if ( !v15 )
            break;
          v13 = (void **)v15[1];
          a1[2] = v13;
        }
        if ( !v13 )
          break;
        v8 = *v13;
        if ( !*v13 )
          break;
        v5 = v23;
      }
      v5 = v23;
    }
  }
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  if ( v5 )
  {
    if ( sub_587C03(12) )
      v16 = (int *)sub_4BAC20(v5, 0);
    else
      v16 = 0;
    v19 = v16;
    v21 = v16;
    v20 = v16;
    ++v22;
  }
  sub_490D00((int)&v19, (int)a1);
  v21 = v19;
  if ( v19 )
  {
    for ( j = *v19; j; j = sub_581780(&v19) )
      sub_434030(a1, j, 0);
  }
  sub_491DB0(&v19);
  return 0;
}

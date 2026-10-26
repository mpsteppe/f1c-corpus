// f1c  0x00566380  size=287
char __thiscall sub_566380(int ***this, int *a2)
{
  int **v2; // ebx
  int v3; // eax
  int *v4; // ecx
  int *v5; // edx
  int *v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int *v10; // esi
  int *v11; // ebx
  int *v12; // edx
  int **v14; // [esp+4h] [ebp-4h]
  int *v15; // [esp+Ch] [ebp+4h]

  (*this)[136] = a2;
  v2 = *this;
  v3 = 0;
  v14 = v2;
  v4 = **this;
  v5 = *v2;
  if ( *v2 )
  {
    do
    {
      v5 = (int *)v5[1];
      ++v3;
    }
    while ( v5 );
    if ( v3 >= 2 )
    {
      v6 = *v2;
      v7 = v3 / 2 - 1;
      if ( v7 > 0 )
      {
        do
        {
          v6 = (int *)v6[1];
          --v7;
        }
        while ( v7 );
      }
      v8 = v6[1];
      v6[1] = 0;
      v9 = sub_5664A0(v4);
      v3 = sub_5664A0(v8);
      v10 = (int *)v3;
      if ( v9 )
      {
        if ( v3 )
        {
          LOBYTE(v3) = sub_565BB0(*(void **)v9, *(_DWORD *)v3);
          if ( (_BYTE)v3 )
          {
            v15 = (int *)v9;
            v11 = (int *)v9;
            v9 = *(_DWORD *)(v9 + 4);
          }
          else
          {
            v15 = v10;
            v11 = v10;
            v10 = (int *)v10[1];
          }
          if ( v9 )
          {
            while ( v10 )
            {
              if ( sub_565BB0(*(void **)v9, *v10) )
              {
                v3 = v9;
                v9 = *(_DWORD *)(v9 + 4);
              }
              else
              {
                v3 = (int)v10;
                v10 = (int *)v10[1];
              }
              v11[1] = v3;
              v11 = (int *)v3;
              if ( !v9 )
                goto LABEL_17;
            }
            v11[1] = v9;
            v2 = v14;
          }
          else
          {
LABEL_17:
            if ( v10 )
              v11[1] = (int)v10;
            else
              v11[1] = 0;
            v2 = v14;
          }
        }
        else
        {
          v15 = (int *)v9;
        }
      }
      else
      {
        v15 = (int *)v3;
      }
      v4 = v15;
    }
  }
  *v2 = v4;
  if ( v4 && (v3 = v4[1]) != 0 )
  {
    do
    {
      v12 = (int *)v3;
      v3 = *(_DWORD *)(v3 + 4);
    }
    while ( v3 );
    v2[1] = v12;
    v2[2] = v4;
  }
  else
  {
    v2[1] = v4;
    v2[2] = v4;
  }
  return v3;
}

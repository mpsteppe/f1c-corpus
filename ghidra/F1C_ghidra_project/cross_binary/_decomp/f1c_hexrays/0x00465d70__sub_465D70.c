// f1c  0x00465d70  size=582
int **__stdcall sub_465D70(int a1)
{
  int v1; // eax
  int v2; // ecx
  int **result; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned int ***v7; // esi
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  _DWORD *v10; // ebp
  int v11; // ecx
  unsigned int v12; // edi
  int *v13; // eax
  int v14; // ebp
  unsigned int v15; // ecx
  _DWORD *v16; // ebx
  int v17; // ecx
  int **v18; // ecx
  int **v19; // [esp+8h] [ebp-10h]
  int ***v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int ***v22; // [esp+10h] [ebp-8h]
  unsigned int ***v23; // [esp+1Ch] [ebp+4h]

  v1 = 0;
  v2 = a1;
  if ( !a1 )
    return (int **)a1;
  do
  {
    v2 = *(_DWORD *)(v2 + 4);
    ++v1;
  }
  while ( v2 );
  if ( v1 < 2 )
    return (int **)a1;
  v4 = v1 / 2 - 1;
  v5 = a1;
  if ( v4 > 0 )
  {
    do
    {
      --v4;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v4 );
  }
  v6 = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 4) = 0;
  v7 = (unsigned int ***)sub_465D70(a1);
  result = (int **)sub_465D70(v6);
  v19 = result;
  v23 = v7;
  if ( v7 )
  {
    if ( result )
    {
      v8 = ***v7;
      v9 = v8 >> 29;
      v21 = 0;
      v10 = (_DWORD *)(dword_7CD2AC + 58384);
      while ( 1 )
      {
        if ( v9 == 4 && ((v8 >> 18) & 0x3F) < 2 )
        {
LABEL_20:
          v22 = (int ***)v7;
          v20 = (int ***)v7;
          v23 = (unsigned int ***)v7[1];
          goto LABEL_22;
        }
        v11 = (unsigned __int8)*(_DWORD *)**result;
        if ( (unsigned __int8)v8 == 255 )
        {
          if ( v11 != 255 )
            goto LABEL_20;
        }
        else if ( v11 == 255 )
        {
          break;
        }
        if ( *v10 == (unsigned __int8)v8 )
          break;
        if ( *v10 == v11 )
          goto LABEL_20;
        ++v10;
        if ( ++v21 >= 104 )
          goto LABEL_20;
        v9 = ***v7 >> 29;
      }
      v22 = (int ***)result;
      v20 = (int ***)result;
      result = (int **)result[1];
      v19 = result;
LABEL_22:
      if ( v23 )
      {
        while ( result )
        {
          v12 = ***v23;
          v13 = *result;
          v14 = 0;
          v15 = v12 >> 29;
          v16 = (_DWORD *)(dword_7CD2AC + 58384);
          while ( 1 )
          {
            if ( v15 == 4 && ((v12 >> 18) & 0x3F) < 2 )
            {
LABEL_35:
              v18 = (int **)v23;
              v23 = (unsigned int ***)v23[1];
              goto LABEL_37;
            }
            v17 = (unsigned __int8)*(_DWORD *)*v13;
            if ( (unsigned __int8)v12 == 255 )
            {
              if ( v17 != 255 )
                goto LABEL_35;
            }
            else if ( v17 == 255 )
            {
              break;
            }
            if ( *v16 == (unsigned __int8)v12 )
              break;
            if ( *v16 == v17 )
              goto LABEL_35;
            ++v14;
            ++v16;
            if ( v14 >= 104 )
              goto LABEL_35;
            v15 = ***v23 >> 29;
          }
          v18 = v19;
          v19 = (int **)v19[1];
LABEL_37:
          result = v19;
          v20[1] = v18;
          v20 = (int ***)v18;
          if ( !v23 )
            goto LABEL_38;
        }
        v20[1] = (int **)v23;
        return (int **)v22;
      }
      else
      {
LABEL_38:
        if ( result )
          v20[1] = result;
        else
          v20[1] = 0;
        return (int **)v22;
      }
    }
    else
    {
      return (int **)v7;
    }
  }
  return result;
}

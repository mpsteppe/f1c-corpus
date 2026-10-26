int __stdcall sub_680494(_DWORD *a1, int *a2, int *a3)
{
  int *v3; // edi
  _DWORD *v4; // esi
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  int result; // eax
  int *v9; // ebx
  int *v10; // eax
  int *v11; // [esp-4h] [ebp-10h]

  v3 = a3;
  if ( !a3 )
    v3 = (int *)&a1;
  v4 = a1;
  v5 = a1[1];
  if ( v5 == 9 )
  {
    v6 = a1[4];
    v7 = 1;
    if ( v6 < 2 )
    {
      *a2 = 1;
      v7 = v4[7];
LABEL_9:
      *v3 = v7;
      return 0;
    }
    if ( v6 == 2 )
    {
      *a2 = a1[7];
      v7 = v4[6];
      goto LABEL_9;
    }
    if ( v6 == 3 )
    {
      *a2 = 1;
      goto LABEL_9;
    }
    return -2147467259;
  }
  if ( v5 == 8 )
  {
    v11 = v3;
    v3 = a2;
    result = sub_680494(a1[4], a2, v11);
    if ( result < 0 )
      return result;
    v7 = *v3 * v4[5];
    goto LABEL_9;
  }
  if ( v5 != 1 )
    return -2147467259;
  v9 = a2;
  *a2 = 0;
  *v3 = 0;
  while ( 1 )
  {
    result = sub_680494(*(_DWORD *)(*(_DWORD *)(v4[2] + 24) + 32), &a3, &a2);
    if ( result < 0 )
      break;
    *v9 += (int)a3;
    v10 = (int *)*v3;
    if ( (unsigned int)a2 > *v3 )
      v10 = a2;
    *v3 = (int)v10;
    v4 = (_DWORD *)v4[3];
    if ( !v4 )
      return 0;
  }
  return result;
}

int __stdcall sub_4D3930(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ebx
  int v4; // edi
  int i; // esi
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  v4 = a1;
  for ( i = 0; i < *(_DWORD *)(v4 + 40); ++i )
  {
    v6 = i;
    if ( i >= 0 && i < *(_DWORD *)(v4 + 40) )
    {
      v7 = *(int **)(v4 + 28);
      if ( i <= 0 )
      {
LABEL_7:
        if ( v7 )
        {
          v8 = *v7;
          goto LABEL_10;
        }
      }
      else
      {
        while ( v7 )
        {
          v7 = (int *)v7[1];
          if ( --v6 <= 0 )
            goto LABEL_7;
        }
      }
    }
    v8 = 0;
LABEL_10:
    sub_4D3930(v8, v3, a3);
  }
  sub_567EA0(&a1, &v10, 0);
  sub_567E80(&a2, &v11);
  if ( (int)a2 + a1 > *v3 )
    *v3 = (char *)a2 + a1;
  result = v10 + v11;
  if ( v10 + v11 > *a3 )
    *a3 = result;
  return result;
}

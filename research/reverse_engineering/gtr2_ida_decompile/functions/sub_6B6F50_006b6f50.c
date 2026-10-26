int __stdcall sub_6B6F50(int *a1)
{
  int v2; // edi
  int v3; // eax
  int *v4; // ebx
  int v5; // edi
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp+8h] [ebp-4h]
  int v9; // [esp+14h] [ebp+8h]

  v2 = a1[89];
  v8 = v2;
  if ( !a1[45] )
  {
    v3 = a1[63];
    v9 = 0;
    if ( v3 > 0 )
    {
      v4 = a1 + 64;
      while ( 1 )
      {
        v5 = *v4;
        if ( a1[59] )
        {
          if ( !a1[81] )
          {
            if ( !a1[83] )
              sub_6B62D0(0, a1, *(_DWORD *)(v5 + 20));
            goto LABEL_11;
          }
          v7 = *(_DWORD *)(v5 + 24);
        }
        else
        {
          sub_6B62D0(0, a1, *(_DWORD *)(v5 + 20));
          v7 = *(_DWORD *)(v5 + 24);
        }
        sub_6B62D0(1, a1, v7);
LABEL_11:
        ++v4;
        if ( ++v9 >= a1[63] )
        {
          v2 = v8;
          break;
        }
      }
    }
  }
  if ( a1[50] != *(_DWORD *)(v2 + 28) )
  {
    sub_6B6460(a1);
    *(_DWORD *)(v2 + 28) = a1[50];
  }
  return sub_6B6710((int)a1);
}

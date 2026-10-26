int __thiscall sub_4A7A80(_DWORD *this)
{
  _DWORD *v1; // ebx
  int v2; // esi
  int v3; // ecx
  int *v4; // eax
  int v5; // eax
  _DWORD *v6; // ebp
  int v8; // esi
  _DWORD *v9; // edi
  char v10; // al
  void *v11; // ebx
  int v12; // ecx
  int v13; // edx
  int *v14; // eax
  int v15; // eax
  int v16; // eax
  int v18; // [esp+14h] [ebp-8h] BYREF
  int v19; // [esp+18h] [ebp-4h] BYREF

  v1 = this;
  sub_4AE870(&v19, &v18);
  v2 = 0;
  if ( (int)v1[71] <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = v2;
    if ( v2 < 0 || v2 >= v1[71] )
      goto LABEL_8;
    v4 = (int *)v1[68];
    if ( v2 > 0 )
    {
      while ( v4 )
      {
        v4 = (int *)v4[1];
        if ( --v3 <= 0 )
          goto LABEL_7;
      }
LABEL_8:
      v5 = 0;
      goto LABEL_10;
    }
LABEL_7:
    if ( !v4 )
      goto LABEL_8;
    v5 = *v4;
LABEL_10:
    v6 = (_DWORD *)sub_4A74F0(v19, v18, v5);
    if ( v6 )
      break;
    if ( ++v2 >= v1[71] )
      return 0;
  }
  v8 = v1[68];
  while ( v8 )
  {
    v9 = (_DWORD *)v8;
    v10 = *(_BYTE *)(v8 + 8);
    v8 = *(_DWORD *)(v8 + 4);
    if ( v10 )
    {
      v11 = (void *)*v9;
      if ( *v9 )
      {
        sub_4A8160(*v9);
        sub_5BE8AE(v11);
      }
      v1 = this;
    }
    sub_5BE8AE(v9);
  }
  v1[68] = 0;
  v1[69] = 0;
  v1[70] = 0;
  v1[71] = 0;
  v12 = 0;
  if ( (int)v6[10] > 0 )
  {
    while ( 1 )
    {
      v13 = v12;
      if ( v12 >= 0 && v12 < v6[10] )
      {
        v14 = (int *)v6[7];
        if ( v12 <= 0 )
        {
LABEL_25:
          if ( v14 )
          {
            v15 = *v14;
            goto LABEL_28;
          }
        }
        else
        {
          while ( v14 )
          {
            v14 = (int *)v14[1];
            if ( --v13 <= 0 )
              goto LABEL_25;
          }
        }
      }
      v15 = 0;
LABEL_28:
      *(_DWORD *)(v15 + 44) = 1;
      v16 = v6[10];
      if ( ++v12 >= v16 )
      {
        if ( v16 > 0 )
          sub_4A7310(v1, v6 + 7);
        break;
      }
    }
  }
  sub_4A7600(v1, v6, 1, 1, 1);
  return 0;
}

int __thiscall sub_410460(_DWORD *this)
{
  int *v2; // eax
  int v3; // ebp
  int i; // eax
  int *v5; // ecx
  _BYTE *v6; // eax
  int v7; // edx
  int v8; // eax
  int *v9; // eax
  char v10; // bl
  int *v11; // esi
  char v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h] BYREF
  __int16 v15; // [esp+18h] [ebp-4h]

  v14 = 16843009;
  v15 = 257;
  v2 = (int *)this[3];
  v3 = 0;
  this[5] = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v9 )
    {
      v5 = &v14;
      v6 = (_BYTE *)(i + 15);
      v7 = 6;
      do
      {
        if ( *v6 )
          *(_BYTE *)v5 = 0;
        ++v6;
        v5 = (int *)((char *)v5 + 1);
        --v7;
      }
      while ( v7 );
      v8 = this[5];
      if ( !v8 )
        break;
      v9 = *(int **)(v8 + 4);
      this[5] = v9;
      if ( !v9 )
        break;
    }
  }
  v10 = 0;
  v13 = 0;
  v11 = &v14;
  do
  {
    if ( *(_BYTE *)v11 )
      v3 += sub_410560(v13);
    ++v10;
    v11 = (int *)((char *)v11 + 1);
    v13 = v10;
  }
  while ( (unsigned __int8)v10 < 6u );
  return v3;
}

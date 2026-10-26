int __thiscall sub_68584A(_DWORD *this, _DWORD *a2, int a3, int a4, int a5)
{
  _DWORD *v5; // edx
  int *v6; // ecx
  int result; // eax
  int *v9; // edi
  unsigned int v10; // ebx
  int v11; // edx
  int *v12; // eax
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // eax
  int *v16; // [esp+Ch] [ebp-8h]
  _DWORD *v17; // [esp+10h] [ebp-4h]
  unsigned int v18; // [esp+1Ch] [ebp+8h]
  unsigned int v19; // [esp+20h] [ebp+Ch]
  int v20; // [esp+24h] [ebp+10h]
  int *v21; // [esp+28h] [ebp+14h]

  v5 = this;
  v6 = *(int **)(this[5] + 4 * a3);
  v17 = v5;
  v16 = v6;
  v20 = *(_DWORD *)(a2[7] + 4 * (a5 + 4 * a4));
  result = v20;
  if ( v20 != -1 )
  {
    while ( 1 )
    {
      v9 = *(int **)(v5[5] + 4 * result);
      if ( v9[18] < (unsigned int)v6[22] )
      {
        v10 = v6[18];
        if ( v10 >= v9[22] )
          return -1;
        v11 = v9[5];
        if ( v6[5] == v11 && v6[6] == v11 )
          return result;
        if ( v10 >= v9[18] )
        {
          v12 = v9;
          v21 = v6;
        }
        else
        {
          v12 = v6;
          v21 = v9;
        }
        v19 = 0;
        v13 = 4 * v12[29];
        v14 = a2[21] + 4 * *(_DWORD *)(v13 + a2[20]);
        v18 = *(_DWORD *)(v13 + a2[19]);
        if ( v18 )
        {
          do
          {
            v15 = (_DWORD *)(a2[22] + 12 * *(_DWORD *)(v14 + 4 * v19));
            if ( *v15 <= (unsigned int)v21[18] )
              break;
            if ( !sub_685795(v17, v21[5], v21[6], v15[1], v15[2]) )
              return v20;
            ++v19;
            v6 = v16;
          }
          while ( v19 < v18 );
        }
      }
      v20 = v9[12];
      if ( v20 == -1 )
        return -1;
      result = v9[12];
      v5 = v17;
    }
  }
  return -1;
}

int __thiscall sub_4E9440(int this)
{
  char *v2; // ecx
  int v3; // ebp
  int *v4; // ebx
  int v5; // esi
  int result; // eax
  int v7; // ebp
  int *v8; // ebx
  int v9; // esi
  int v10; // [esp+48h] [ebp-Ch]
  int v11; // [esp+48h] [ebp-Ch]
  int v12; // [esp+4Ch] [ebp-8h]
  int v13; // [esp+4Ch] [ebp-8h]
  float v14; // [esp+50h] [ebp-4h]

  v2 = dword_91E07C;
  v3 = 0;
  v10 = 0;
  v14 = *((float *)dword_91E07C + 4307) * 9.549296585513721;
  v12 = *(_DWORD *)(this + 56);
  if ( v12 > 0 )
  {
    v4 = (int *)(this + 60);
    do
    {
      v5 = *v4;
      if ( (*(float *)(this + 344) - *(float *)(this + 340)) / (double)v12 * (double)v10 + *(float *)(this + 340) >= v14 )
      {
        if ( v5 )
        {
          if ( *((_DWORD *)v2 + 1291) )
            sub_5E37F0(0, v5, 0);
          if ( *((_DWORD *)dword_91E07C + 1286) )
            sub_5E37F0(0, v5, 0);
          if ( *(_DWORD *)(this + 392) )
            sub_5E37F0(0, v5, 0);
        }
      }
      else if ( v5 )
      {
        if ( *((_DWORD *)v2 + 1291) )
          sub_5E37F0(1, v5, 0);
        if ( *((_DWORD *)dword_91E07C + 1286) )
          sub_5E37F0(1, v5, 0);
        if ( *(_DWORD *)(this + 392) )
          sub_5E37F0(1, v5, 0);
      }
      v2 = dword_91E07C;
      ++v3;
      ++v4;
      v10 = v3;
      v12 = *(_DWORD *)(this + 56);
    }
    while ( v3 < v12 );
  }
  result = *(_DWORD *)(this + 348);
  v7 = 0;
  v11 = 0;
  v13 = result;
  if ( result > 0 )
  {
    v8 = (int *)(this + 352);
    while ( 1 )
    {
      v9 = *v8;
      if ( (*(float *)(this + 388) - *(float *)(this + 384)) / (double)v13 * (double)v11 + *(float *)(this + 384) >= v14 )
      {
        if ( v9 )
        {
          if ( *((_DWORD *)v2 + 1291) )
            sub_5E37F0(0, v9, 0);
          if ( *((_DWORD *)dword_91E07C + 1286) )
            sub_5E37F0(0, v9, 0);
          if ( *(_DWORD *)(this + 392) )
            sub_5E37F0(0, v9, 0);
        }
      }
      else if ( v9 )
      {
        if ( *((_DWORD *)v2 + 1291) )
          sub_5E37F0(1, v9, 0);
        if ( *((_DWORD *)dword_91E07C + 1286) )
          sub_5E37F0(1, v9, 0);
        if ( *(_DWORD *)(this + 392) )
          sub_5E37F0(1, v9, 0);
      }
      result = *(_DWORD *)(this + 348);
      ++v7;
      ++v8;
      v11 = v7;
      v13 = result;
      if ( v7 >= result )
        break;
      v2 = dword_91E07C;
    }
  }
  return result;
}

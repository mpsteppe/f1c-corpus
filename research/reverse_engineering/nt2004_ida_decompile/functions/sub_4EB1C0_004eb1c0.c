char __thiscall sub_4EB1C0(int this)
{
  _DWORD *v2; // ecx
  char result; // al
  int v4; // ebp
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int *v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int *v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int *v20; // eax
  int v21; // esi
  char *v22; // eax
  int v23; // eax
  CHAR *v24; // ecx
  int v25; // [esp+4h] [ebp-4h]

  v2 = *(_DWORD **)(this + 96);
  result = 0;
  if ( v2 )
  {
    sub_4E9BB0(v2);
    v25 = sub_4EB570(this);
    sub_4EC010(this);
    v4 = 0;
    if ( v25 >= 0 )
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(this + 96);
        v6 = 0;
        if ( *(int *)(v5 + 64) > 0 )
        {
          while ( 1 )
          {
            v7 = v6;
            if ( v6 < 0 || v6 >= *(_DWORD *)(v5 + 64) )
              goto LABEL_10;
            v8 = *(int **)(v5 + 52);
            if ( v6 > 0 )
              break;
LABEL_9:
            if ( !v8 )
              goto LABEL_10;
            v9 = *v8;
LABEL_12:
            if ( *(__int16 *)(v9 + 24) == v4 )
            {
              v10 = *(_DWORD *)(v9 + 40);
              if ( v10 )
                sub_41C8B0(*(_DWORD **)(this + 100), v10, *(_DWORD *)(v9 + 20));
            }
            v5 = *(_DWORD *)(this + 96);
            if ( ++v6 >= *(_DWORD *)(v5 + 64) )
              goto LABEL_16;
          }
          while ( v8 )
          {
            v8 = (int *)v8[1];
            if ( --v7 <= 0 )
              goto LABEL_9;
          }
LABEL_10:
          v9 = 0;
          goto LABEL_12;
        }
LABEL_16:
        v11 = *(_DWORD *)(this + 96);
        v12 = 0;
        if ( *(int *)(v11 + 80) > 0 )
        {
          while ( 1 )
          {
            v13 = v12;
            if ( v12 < 0 || v12 >= *(_DWORD *)(v11 + 80) )
              goto LABEL_23;
            v14 = *(int **)(v11 + 68);
            if ( v12 > 0 )
              break;
LABEL_22:
            if ( !v14 )
              goto LABEL_23;
            v15 = *v14;
LABEL_25:
            if ( *(__int16 *)(v15 + 24) == v4 )
            {
              v16 = *(_DWORD *)(v15 + 40);
              if ( v16 )
                sub_41C8B0(*(_DWORD **)(this + 100), v16, *(_DWORD *)(v15 + 20));
            }
            v11 = *(_DWORD *)(this + 96);
            if ( ++v12 >= *(_DWORD *)(v11 + 80) )
              goto LABEL_29;
          }
          while ( v14 )
          {
            v14 = (int *)v14[1];
            if ( --v13 <= 0 )
              goto LABEL_22;
          }
LABEL_23:
          v15 = 0;
          goto LABEL_25;
        }
LABEL_29:
        v17 = *(_DWORD *)(this + 96);
        v18 = 0;
        if ( *(int *)(v17 + 96) > 0 )
          break;
LABEL_46:
        if ( ++v4 > v25 )
          goto LABEL_47;
      }
      while ( 1 )
      {
        v19 = v18;
        if ( v18 >= 0 && v18 < *(_DWORD *)(v17 + 96) )
        {
          v20 = *(int **)(v17 + 84);
          if ( v18 <= 0 )
          {
LABEL_35:
            if ( v20 )
            {
              v21 = *v20;
              goto LABEL_38;
            }
          }
          else
          {
            while ( v20 )
            {
              v20 = (int *)v20[1];
              if ( --v19 <= 0 )
                goto LABEL_35;
            }
          }
        }
        v21 = 0;
LABEL_38:
        if ( *(__int16 *)(v21 + 40) == v4 )
        {
          v22 = *(char **)(v21 + 20);
          if ( !v22 )
            v22 = &byte_629120;
          v23 = sub_4EB650(v22);
          if ( v23 )
          {
            v24 = *(CHAR **)v21;
            if ( !*(_DWORD *)v21 )
              v24 = &byte_629120;
            sub_41C8C0(
              *(_DWORD **)(this + 100),
              (int)v24,
              v23,
              *(float *)(v21 + 28),
              *(float *)(v21 + 8),
              *(float *)(v21 + 12),
              *(float *)(v21 + 32),
              *(float *)(v21 + 36),
              *(float *)(v21 + 16));
          }
        }
        v17 = *(_DWORD *)(this + 96);
        if ( ++v18 >= *(_DWORD *)(v17 + 96) )
          goto LABEL_46;
      }
    }
LABEL_47:
    sub_41C910(*(_DWORD **)(this + 100), *(_DWORD **)(*(_DWORD *)(this + 96) + 140), 0);
    sub_4EC230(this);
    return 1;
  }
  return result;
}

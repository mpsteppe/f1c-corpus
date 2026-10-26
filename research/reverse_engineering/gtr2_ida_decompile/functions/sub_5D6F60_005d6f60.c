_DWORD *__thiscall sub_5D6F60(void *this, int a2, int a3)
{
  int v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // esi
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v13; // [esp+Ch] [ebp-14h]
  _DWORD *v15; // [esp+24h] [ebp+4h]

  v3 = (int)this;
  v4 = operator new(0x18u);
  if ( v4 )
    v5 = sub_5D6F00(v4, a2);
  else
    v5 = 0;
  v15 = v5;
  sub_5D6BC0((int)(v5 + 3), v3, (int *)(v3 + 12));
  if ( *(int *)(v3 + 12) > 0 )
  {
    v6 = 0;
    v13 = *(_DWORD *)(v3 + 12);
    while ( 1 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 20) + v6) + 400);
      v8 = *(_DWORD *)(a3 + 444);
      v9 = 0;
      if ( v8 <= 0 )
      {
LABEL_12:
        v11 = 0;
      }
      else
      {
        v10 = *(_DWORD *)(a3 + 452);
        while ( *(_DWORD *)(*(_DWORD *)v10 + 400) != v7 )
        {
          ++v9;
          v10 += 4;
          if ( v9 >= v8 )
          {
            v5 = v15;
            goto LABEL_12;
          }
        }
        v11 = *(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v9);
        v5 = v15;
      }
      *(_DWORD *)(v6 + v5[5]) = v11;
      v6 += 68;
      if ( !--v13 )
        break;
      v3 = (int)this;
    }
  }
  return v5;
}

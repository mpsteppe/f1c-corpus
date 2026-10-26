int __thiscall sub_608640(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // ebx
  _DWORD *v4; // ecx
  int v5; // eax
  int *v7; // eax
  int v8; // edi
  int v9; // edx
  _DWORD **v10; // eax
  _DWORD *v11; // ebx
  int v12; // ecx
  int v13; // esi
  _DWORD *v14; // eax
  int v15; // eax
  _DWORD **v16; // eax
  int v17; // eax
  int *v18; // eax
  int v19; // [esp+3Ch] [ebp-14h]
  int v20; // [esp+40h] [ebp-10h]
  int v21; // [esp+44h] [ebp-Ch]
  int v22; // [esp+48h] [ebp-8h]
  int v23; // [esp+4Ch] [ebp-4h]

  v2 = a2;
  if ( (*a2 & 0x3000000) != 0x3000000 )
  {
    v4 = (_DWORD *)dword_FB27A4;
    if ( *(int *)(dword_FB27A4 + 4816) <= 1 )
    {
      v5 = (*a2 & 8) != 0 ? 0x8000 : 4096;
    }
    else
    {
      v5 = sub_60AE80(a2);
      v4 = (_DWORD *)dword_FB27A4;
    }
    v19 = v5;
    if ( (*(int (__stdcall **)(_DWORD *, _DWORD, _DWORD, int, _DWORD *, _DWORD *, _DWORD, _DWORD))(*v4 + 376))(
           v4 + 168,
           v4[167],
           a2[2],
           v5,
           a2 + 11,
           a2 + 13,
           0,
           0)
      || (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD *, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 380))(
           dword_FB27A4 + 712,
           *(_DWORD *)(dword_FB27A4 + 708),
           a2[9],
           a2 + 12,
           a2 + 14,
           0,
           0) )
    {
      return -1;
    }
    v7 = (int *)this[67];
    v8 = a2[13];
    v20 = a2[14];
    this[69] = v7;
    if ( v7 )
    {
      v22 = *v7;
      if ( *v7 )
      {
        while ( 1 )
        {
          v9 = v22;
          v10 = *(_DWORD ***)(v22 + 532);
          *(_DWORD *)(v22 + 540) = v10;
          if ( v10 )
          {
            v11 = *v10;
            if ( *v10 )
            {
              while ( 1 )
              {
                if ( (*v11 & 0x200) == 0 )
                {
                  v12 = 0;
                  v23 = 0;
                  if ( (int)v11[90] > 0 )
                    break;
                }
LABEL_25:
                v15 = *(_DWORD *)(v9 + 540);
                if ( v15 )
                {
                  v16 = *(_DWORD ***)(v15 + 4);
                  *(_DWORD *)(v9 + 540) = v16;
                  if ( v16 )
                  {
                    v11 = *v16;
                    if ( *v16 )
                      continue;
                  }
                }
                goto LABEL_28;
              }
              v21 = 0;
              while ( 2 )
              {
                v13 = v21 + v11[91];
                v14 = a2;
                if ( a2[22] == *(_DWORD *)(v13 + 88) && a2[1] == *(_DWORD *)(v13 + 4) )
                {
                  if ( v19 == 4096 )
                  {
                    sub_5D70A0(
                      (void *)(*(_DWORD *)(a2[11] + 76) + (v8 << 6)),
                      *(const void **)(v13 + 32),
                      *(_DWORD *)(v13 + 8) << 6);
                    goto LABEL_21;
                  }
                  if ( v19 == 0x8000 )
                  {
                    sub_5D70A0(
                      (void *)(*(_DWORD *)(a2[11] + 76) + 88 * v8),
                      *(const void **)(v13 + 32),
                      88 * *(_DWORD *)(v13 + 8));
LABEL_21:
                    v14 = a2;
                  }
                  sub_5D70D0(
                    *(_DWORD *)(v14[12] + 32) + 2 * v20,
                    *(_WORD **)(v13 + 40),
                    *(_DWORD *)(v13 + 36),
                    v8 - *((_WORD *)v14 + 26));
                  v8 += *(_DWORD *)(v13 + 8);
                  v20 += *(_DWORD *)(v13 + 36);
                  v12 = v23;
                }
                v23 = ++v12;
                v21 += 108;
                if ( v12 >= v11[90] )
                {
                  v9 = v22;
                  goto LABEL_25;
                }
                continue;
              }
            }
LABEL_28:
            v2 = a2;
          }
          v17 = this[69];
          if ( v17 )
          {
            v18 = *(int **)(v17 + 4);
            this[69] = v18;
            if ( v18 )
            {
              v22 = *v18;
              if ( *v18 )
                continue;
            }
          }
          break;
        }
      }
    }
    *v2 |= 0x3000000u;
  }
  return 0;
}

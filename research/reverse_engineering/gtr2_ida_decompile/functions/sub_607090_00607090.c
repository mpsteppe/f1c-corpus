void __thiscall sub_607090(char *this, int a2, int a3, int a4)
{
  _DWORD *v5; // ecx
  int v6; // eax
  char *v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int *v12; // eax
  bool v13; // zf
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int *v19; // eax
  int v20; // eax
  float v21; // [esp+0h] [ebp-1Ch]
  float v22; // [esp+4h] [ebp-18h]
  float v23; // [esp+8h] [ebp-14h]
  int v24; // [esp+14h] [ebp-8h]
  float v25; // [esp+18h] [ebp-4h]
  int v26; // [esp+24h] [ebp+8h]

  v24 = 1;
  if ( *((float *)this + 12) <= sub_5F5900(*((_DWORD *)this + 18)) )
  {
    sub_5F5A20(*((_DWORD *)this + 18));
    if ( (*(_DWORD *)this & 0x30) != 0 || (*(_DWORD *)this & 2) == 0 )
    {
      v5 = (_DWORD *)*((_DWORD *)this + 21);
      if ( v5 )
        sub_5DA7A0(v5, (_DWORD *)this + 14, (_DWORD *)this + 15, (_DWORD *)this + 16);
      v25 = *((float *)this + 13);
      if ( v25 * v25 < sub_5D7980((float *)this + 14, (float *)(a3 + 52)) )
      {
        *(_DWORD *)this |= 0x80u;
        return;
      }
      if ( !sub_606DB0((int)this, (char)this, 0) )
      {
        v6 = *(_DWORD *)this & 0xC;
        if ( v6 == 4 )
        {
          v24 = 1;
        }
        else if ( v6 == 8 )
        {
          v24 = 6;
        }
        if ( *((int *)this + 25) <= 0 )
        {
          if ( *(int *)(a2 + 560) <= 0 )
            return;
          v7 = (char *)(a2 + 548);
        }
        else
        {
          v7 = this + 88;
        }
        v8 = 0;
        v26 = (int)v7;
        do
        {
          v9 = dword_FB2804[v8];
          v10 = dword_FB27A4;
          if ( v9 > *(_DWORD *)(4 * v8 + 9060 + dword_FB27A4) )
          {
            sub_5F7D00((_DWORD *)dword_FB27A4, v8, v9);
            v10 = dword_FB27A4;
          }
          v11 = 9084 - (_DWORD)dword_FB2804 + 4 * v8++;
          *(int *)((char *)dword_FB2804 + v11 + v10) = 0;
        }
        while ( v8 < 6 );
        v12 = *(int **)v26;
        v13 = *(_DWORD *)v26 == 0;
        *(_DWORD *)(v26 + 8) = *(_DWORD *)v26;
        if ( !v13 )
        {
          v14 = *v12;
          if ( *v12 )
          {
            do
            {
              v15 = *(_DWORD **)(v14 + 532);
              *(_DWORD *)(v14 + 540) = v15;
              if ( v15 && *v15 )
              {
                do
                {
                  v16 = *(_DWORD *)(v14 + 540);
                  if ( !v16 )
                    break;
                  v17 = *(_DWORD **)(v16 + 4);
                  *(_DWORD *)(v14 + 540) = v17;
                  if ( !v17 )
                    break;
                }
                while ( *v17 );
              }
              v18 = *(_DWORD *)(v26 + 8);
              if ( !v18 )
                break;
              v19 = *(int **)(v18 + 4);
              *(_DWORD *)(v26 + 8) = v19;
              if ( !v19 )
                break;
              v14 = *v19;
            }
            while ( *v19 );
          }
        }
        v23 = -*((float *)this + 16);
        v22 = -*((float *)this + 15);
        v21 = -*((float *)this + 14);
        sub_5E4C80(*((float **)this + 19), v21, v22, v23);
        sub_5E5050(*((char **)this + 19), 286);
        v20 = 1 - v24;
        LOBYTE(v20) = v24 == 1;
        (*(void (__thiscall **)(int, int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 476))(
          dword_FB27A4,
          a2,
          *((_DWORD *)this + 19),
          v20);
        sub_5F7DD0((_DWORD **)dword_FB27A4);
        *(_DWORD *)this |= 2u;
      }
    }
  }
}

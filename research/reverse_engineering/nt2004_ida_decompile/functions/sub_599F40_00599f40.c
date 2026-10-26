int __thiscall sub_599F40(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // ebp
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // ecx
  int v7; // esi
  int *v8; // eax
  _DWORD *v9; // ebp
  _DWORD *v10; // edi
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // edi
  void *v14; // eax
  int v15; // edx
  void *v16; // ebp
  int v17; // eax
  unsigned int v18; // eax
  _DWORD *v19; // esi
  float v21; // [esp+0h] [ebp-3Ch]
  int v22; // [esp+14h] [ebp-28h]
  unsigned __int16 v23; // [esp+18h] [ebp-24h]
  unsigned __int16 v24; // [esp+1Ah] [ebp-22h]
  unsigned int v25; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+24h] [ebp-18h]
  int v28; // [esp+28h] [ebp-14h]
  int v29; // [esp+2Ch] [ebp-10h]
  int v30; // [esp+30h] [ebp-Ch]
  char Source[8]; // [esp+34h] [ebp-8h] BYREF

  v3 = this;
  sub_59D490(4);
  v27 = 0;
  if ( v28 <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = operator new(0xC4u);
    v5 = v4 ? sub_598460(v4) : 0;
    v5[48] = v3;
    sub_59D490(32);
    sub_59D490(4);
    sub_59D490(16);
    sub_59D490(16);
    sub_59D490(16);
    sub_59D490(16);
    sub_59D490(4);
    sub_59D490(4);
    v5[39] |= 2u;
    sub_599620((int)v5, v23, v24);
    sub_5995A0(v6, v29);
    sub_59D490(4);
    v7 = v5[43];
    if ( v7 > 0 )
    {
      v8 = (int *)operator new(148 * v7 + 4);
      if ( v8 )
      {
        v9 = v8 + 1;
        *v8 = v7;
        v10 = v8 + 1;
        if ( v7 - 1 >= 0 )
        {
          do
          {
            sub_5A1B00(v10);
            v10 += 37;
            --v7;
          }
          while ( v7 );
        }
        v11 = v9;
        v3 = this;
      }
      else
      {
        v11 = 0;
      }
      v12 = v5[43];
      v13 = 0;
      v5[44] = v11;
      v22 = 0;
      if ( v12 > 0 )
        break;
    }
LABEL_36:
    v19 = v5 + 39;
    if ( (v5[39] & 0x200) != 0 )
    {
      sub_59A800(a2, Source);
      strncpy((char *)v5 + 64, Source, 4u);
      strcat((char *)v5, Source);
      v19 = v5 + 39;
    }
    if ( sub_599BF0(v3, (const char *)v5) )
    {
      sub_598580(v5);
      j_nullsub_6(v5);
      sub_5BE8AE();
    }
    else
    {
      sub_599A70(v3, v5);
      if ( (BYTE1(*v19) & 0x80u) == 0 )
        *v19 |= 1u;
    }
    if ( ++v27 >= v28 )
      return 0;
  }
  while ( 1 )
  {
    sub_59D490(32);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    if ( (int)v11[18] > 1 )
    {
      sub_59D490(4);
      v14 = operator new(4 * v11[20]);
      v15 = 4 * v11[20];
      v11[19] = v14;
      sub_59D490(v15);
      sub_59D490(4);
      sub_59D490(4);
      if ( (v11[21] & 0xFFFF000F) == 0 )
        v11[21] |= 6u;
      v13 = v22;
    }
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    sub_59D490(4);
    v21 = (float)v30;
    sub_5A1BC0(v21);
    sub_5A1C40(v25 & 0xFFFFFF);
    sub_5A1C50(HIBYTE(v25));
    sub_5A1CC0(v11[16] & 0xC, v11[17]);
    if ( a3 == 420 )
      sub_59D490(4);
    v16 = (void *)v11[24];
    if ( (int)v16 <= (int)&unk_800000 )
    {
      if ( v16 == &unk_800000 )
      {
        v17 = sub_599350(v5, v13);
        goto LABEL_29;
      }
      if ( v16 == (void *)0x100000 )
      {
        sub_599310(v5, v13);
      }
      else if ( v16 == (void *)0x400000 )
      {
        v17 = sub_5993C0(v5, v13);
        goto LABEL_29;
      }
      goto LABEL_30;
    }
    if ( v16 == (void *)0x1000000 )
      break;
    if ( v16 == (void *)0x8000000 )
    {
      v17 = sub_599480(v5, v13);
      goto LABEL_29;
    }
LABEL_30:
    v18 = v11[16] & 0xFFFFFEFF;
    v11[16] = v18;
    if ( (v18 & 0x100) != 0 )
      v5[39] |= 0x200u;
    if ( (v11[16] & 0x200) != 0 )
      v5[39] |= 0x4000u;
    v11 += 37;
    v22 = ++v13;
    if ( v13 >= v5[43] )
    {
      v3 = this;
      goto LABEL_36;
    }
  }
  v17 = sub_599420(v5, v13);
LABEL_29:
  if ( !v17 )
    goto LABEL_30;
  return -1;
}

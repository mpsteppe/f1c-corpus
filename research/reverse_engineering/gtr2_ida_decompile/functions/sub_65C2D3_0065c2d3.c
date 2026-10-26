int __thiscall sub_65C2D3(int this, void *Block, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  int v6; // esi
  int i; // eax
  int v8; // eax
  int v9; // ecx
  _DWORD *j; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _DWORD *Blocka; // [esp+14h] [ebp+8h]
  _DWORD *v17; // [esp+18h] [ebp+Ch]
  _DWORD *v18; // [esp+18h] [ebp+Ch]

  v4 = operator new(0x14u);
  if ( v4 )
    Blocka = sub_659C5B(v4, (int)Block, 0, 0);
  else
    Blocka = 0;
  if ( Blocka )
  {
    if ( a3 && (v5 = *(_DWORD **)(this + 620), *v5 < v5[1]) && *(_BYTE *)*v5 == 40 )
    {
      v17 = Blocka + 1;
      v6 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
      if ( v6 >= 0 )
      {
        while ( 1 )
        {
          v6 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
          if ( v6 < 0 )
            break;
          if ( *(_DWORD *)(this + 632) != 9 )
            goto LABEL_25;
          for ( i = Blocka[1]; i; i = *(_DWORD *)(i + 12) )
          {
            if ( !strcmp(*(const char **)(this + 640), *(const char **)(i + 24)) )
            {
              sub_65DD1F(this + 24, this + 632, 1511, "duplicate macro parameter '%s'", *(_DWORD *)(this + 640));
              break;
            }
          }
          if ( sub_65B229(48) )
            v8 = sub_67EF22(this + 632);
          else
            v8 = 0;
          *v17 = v8;
          if ( !v8 )
            goto LABEL_40;
          v17 = (_DWORD *)(v8 + 12);
          v6 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
          if ( v6 < 0 )
            break;
          if ( *(_DWORD *)(this + 632) != 1 )
            goto LABEL_25;
          if ( strcmp(",", (const char *)(this + 640)) )
          {
            if ( !strcmp((const char *)&word_6FBE80, (const char *)(this + 640)) )
              goto LABEL_29;
LABEL_25:
            v9 = *(_DWORD *)(this + 632);
            if ( v9 == 12 || v9 == 13 )
              *(_DWORD *)(this + 64) = 1;
            sub_65DF43(this + 24, 1500, this + 632);
            *(_DWORD *)(this + 68) = 1;
            v6 = -2147467259;
            break;
          }
        }
      }
    }
    else
    {
LABEL_29:
      for ( j = Blocka + 2; ; j = (_DWORD *)(v14 + 12) )
      {
        v18 = j;
        v11 = *(_DWORD *)(this + 100);
        if ( v11 )
        {
          qmemcpy((void *)(this + 632), (const void *)(v11 + 16), 0x20u);
          *(_DWORD *)(this + 100) = *(_DWORD *)(v11 + 12);
          *(_DWORD *)(v11 + 12) = 0;
          v12 = *(_DWORD *)(this + 620);
          *(_DWORD *)(this + 648) = *(_DWORD *)(v12 + 24);
          *(_DWORD *)(this + 652) = *(_DWORD *)(v12 + 28);
        }
        else
        {
          v6 = sub_65E7A1(*(_DWORD *)(this + 664), this + 632);
          if ( v6 < 0 )
            goto LABEL_43;
        }
        v13 = *(_DWORD *)(this + 632);
        if ( v13 == 12 || v13 == 13 )
          break;
        if ( sub_65B229(48) )
          v14 = sub_67EF22(this + 632);
        else
          v14 = 0;
        *v18 = v14;
        if ( !v14 )
          goto LABEL_40;
      }
      *(_DWORD *)(this + 64) = 1;
      v6 = sub_65B478((char *)this, (const char **)Blocka);
      if ( v6 >= 0 )
      {
        Blocka = 0;
        v6 = 0;
      }
    }
  }
  else
  {
LABEL_40:
    v6 = -2147024882;
  }
LABEL_43:
  if ( Blocka )
    sub_65B2FE(Blocka, 1);
  return v6;
}

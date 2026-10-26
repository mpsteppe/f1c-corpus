void __thiscall sub_65C7B1(int this, int a2, int a3)
{
  int v4; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  bool v11; // cf
  bool v12; // cf
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // [esp-Ch] [ebp-58h]
  char *v17; // [esp-4h] [ebp-50h]
  char v18; // [esp+0h] [ebp-4Ch]
  int v19; // [esp+Ch] [ebp-40h]
  int v20; // [esp+10h] [ebp-3Ch]
  int v21; // [esp+14h] [ebp-38h]

  v4 = 0;
  if ( !*(_DWORD *)(this + 68) )
  {
    while ( a3 )
    {
      v6 = *(_DWORD *)(this + 92);
      --a3;
      if ( !v6 )
      {
        sub_65DD1F(this + 24, this + 632, 0, "internal error: stack underflow", v18);
        goto LABEL_73;
      }
      *(&v19 + a3) = *(_DWORD *)(v6 + 8);
      *(_DWORD *)(this + 92) = *(_DWORD *)(v6 + 12);
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 12) = *(_DWORD *)(this + 96);
      *(_DWORD *)(this + 96) = v6;
    }
    switch ( a2 )
    {
      case 0:
        sub_65C2D3(this, *(void **)(v19 + 24), 1);
        goto LABEL_63;
      case 1:
        sub_65B35D((char *)this, *(char **)(v19 + 24));
        goto LABEL_63;
      case 2:
        sub_65A171((_DWORD *)this, *(_DWORD *)(v19 + 24), 0);
        goto LABEL_63;
      case 3:
        sub_65A171((_DWORD *)this, *(_DWORD *)(v19 + 24), *(_DWORD *)(v20 + 24));
        goto LABEL_63;
      case 4:
        sub_65A1AA(this, 0);
        goto LABEL_63;
      case 5:
        sub_65A3A3(this);
        goto LABEL_63;
      case 6:
        sub_65A487((int *)this, *(_DWORD *)(v19 + 24));
        goto LABEL_63;
      case 7:
        v7 = sub_65B1A2((_DWORD *)this, *(char **)(v19 + 24), 0, 0);
        goto LABEL_19;
      case 8:
        v7 = sub_65B1A2((_DWORD *)this, *(char **)(v19 + 24), 0, 0) == 0;
LABEL_19:
        sub_65A487((int *)this, v7);
        goto LABEL_63;
      case 9:
        sub_65A4E7((_DWORD *)this, *(_DWORD *)(v19 + 24));
        goto LABEL_63;
      case 10:
        sub_65A564((_DWORD *)this);
        goto LABEL_63;
      case 11:
        sub_65A5CE((_DWORD *)this);
        goto LABEL_63;
      case 12:
        sub_65A487((int *)this, 1);
        goto LABEL_24;
      case 13:
        sub_65A4E7((_DWORD *)this, 1);
LABEL_24:
        sub_65D86A(*(_DWORD *)(this + 620));
        goto LABEL_63;
      case 14:
        sub_65B3D1(this);
        goto LABEL_63;
      case 15:
      case 16:
      case 19:
      case 22:
      case 23:
      case 26:
      case 29:
      case 34:
      case 37:
      case 39:
      case 41:
      case 43:
        v4 = v19;
        goto LABEL_63;
      case 17:
        v4 = v19;
        v17 = *(char **)(v19 + 24);
        *(_DWORD *)(v19 + 16) = 2;
        v8 = sub_65B52F((_DWORD *)this, v17);
        goto LABEL_36;
      case 18:
        v4 = v19;
        v16 = *(char **)(v19 + 24);
        *(_DWORD *)(v19 + 16) = 2;
        *(_DWORD *)(v4 + 24) = sub_65B1A2((_DWORD *)this, v16, 0, 0);
        *(_DWORD *)(this + 88) = 1;
        goto LABEL_63;
      case 20:
        v4 = v19;
        v9 = *(_DWORD *)(v19 + 24) == 0;
        goto LABEL_31;
      case 21:
        v4 = v19;
        *(_DWORD *)(v19 + 24) = -*(_DWORD *)(v19 + 24);
        goto LABEL_63;
      case 24:
        v4 = v19;
        v9 = *(_DWORD *)(v19 + 24) * *(_DWORD *)(v20 + 24);
        goto LABEL_31;
      case 25:
        v10 = *(_DWORD *)(v20 + 24);
        v4 = v19;
        if ( v10 )
        {
          v8 = *(_DWORD *)(v19 + 24) / v10;
LABEL_36:
          *(_DWORD *)(v4 + 24) = v8;
        }
        else
        {
          sub_65DD1F(this + 24, this + 632, 1503, "division by zero in preprocessor expression", v18);
          *(_DWORD *)(this + 68) = 1;
        }
        goto LABEL_63;
      case 27:
        v4 = v19;
        *(_DWORD *)(v19 + 24) += *(_DWORD *)(v20 + 24);
        goto LABEL_63;
      case 28:
        v4 = v19;
        *(_DWORD *)(v19 + 24) -= *(_DWORD *)(v20 + 24);
        goto LABEL_63;
      case 30:
        v4 = v19;
        v11 = *(_DWORD *)(v19 + 24) < *(_DWORD *)(v20 + 24);
        goto LABEL_43;
      case 31:
        v4 = v19;
        v11 = *(_DWORD *)(v20 + 24) < *(_DWORD *)(v19 + 24);
LABEL_43:
        v9 = v11;
        goto LABEL_31;
      case 32:
        v4 = v19;
        v12 = *(_DWORD *)(v20 + 24) < *(_DWORD *)(v19 + 24);
        goto LABEL_45;
      case 33:
        v4 = v19;
        v12 = *(_DWORD *)(v19 + 24) < *(_DWORD *)(v20 + 24);
LABEL_45:
        v13 = -v12;
        goto LABEL_48;
      case 35:
        v4 = v19;
        v13 = -(*(_DWORD *)(v20 + 24) != *(_DWORD *)(v19 + 24));
LABEL_48:
        v9 = v13 + 1;
        goto LABEL_31;
      case 36:
        v4 = v19;
        *(_DWORD *)(v19 + 24) = *(_DWORD *)(v19 + 24) != *(_DWORD *)(v20 + 24);
        goto LABEL_63;
      case 38:
        v4 = v19;
        if ( *(_DWORD *)(v19 + 24) )
          goto LABEL_51;
        goto LABEL_55;
      case 40:
        v4 = v19;
        if ( *(_DWORD *)(v19 + 24) )
          goto LABEL_52;
LABEL_51:
        if ( *(_DWORD *)(v20 + 24) )
LABEL_52:
          v9 = 1;
        else
LABEL_55:
          v9 = 0;
LABEL_31:
        *(_DWORD *)(v4 + 24) = v9;
LABEL_63:
        if ( *(_DWORD *)(this + 68) )
          return;
        v15 = *(_DWORD *)(this + 96);
        if ( v15 )
        {
          *(_DWORD *)(this + 96) = *(_DWORD *)(v15 + 12);
          *(_DWORD *)(v15 + 8) = v4;
          *(_DWORD *)(v15 + 12) = *(_DWORD *)(this + 92);
LABEL_66:
          *(_DWORD *)(this + 92) = v15;
          return;
        }
        if ( sub_65B229(20) )
          v15 = sub_67ED1B(v4, *(_DWORD *)(this + 92), "Stack");
        else
          v15 = 0;
        if ( v15 )
          goto LABEL_66;
        sub_65DD1F(this + 24, this + 632, 0, "internal error: out of memory", v18);
LABEL_73:
        *(_DWORD *)(this + 68) = 1;
        break;
      case 42:
        v4 = v19;
        v14 = v20;
        if ( !*(_DWORD *)(v19 + 24) )
          v14 = v21;
        v9 = *(_DWORD *)(v14 + 24);
        goto LABEL_31;
      case 44:
      case 45:
      case 46:
        if ( sub_65B229(48) )
          v4 = sub_67EF22(this + 632);
        else
          v4 = 0;
        sub_65B2A9((_DWORD *)this, v4);
        goto LABEL_63;
      default:
        goto LABEL_63;
    }
  }
}

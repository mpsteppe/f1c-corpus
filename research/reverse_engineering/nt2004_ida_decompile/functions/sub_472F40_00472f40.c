void __thiscall sub_472F40(_DWORD *this, int a2, int a3)
{
  int v4; // edi
  char *v5; // eax
  int v6; // eax
  int v7; // edi

  if ( a2 )
  {
    v4 = 0;
    switch ( a3 )
    {
      case 6:
        *(_DWORD *)(a2 + 84) = 0;
        v4 = sub_49CB60(6);
        v5 = (char *)sub_49C9C0(this);
        goto LABEL_8;
      case 7:
        *(_DWORD *)(a2 + 84) = 0;
        v6 = sub_49CB60(7);
        goto LABEL_7;
      case 8:
        *(_DWORD *)(a2 + 84) = 1;
        v4 = sub_49CB60(8);
        v5 = (char *)sub_49CA00(this);
        goto LABEL_8;
      case 9:
        *(_DWORD *)(a2 + 84) = 1;
        v6 = sub_49CB60(9);
LABEL_7:
        v4 = v6;
        v5 = (char *)sub_49C9E0(this);
LABEL_8:
        if ( !v5 )
          goto LABEL_9;
        goto LABEL_10;
      default:
LABEL_9:
        v5 = (char *)sub_4AE330(this[12]);
LABEL_10:
        sub_4A5A60(v5);
        if ( v4 )
        {
          v7 = *(_DWORD *)(v4 + 28);
          if ( v7 )
          {
            sub_4A57E0(v7);
            *(_DWORD *)(a2 + 4) = this[85] - this[84];
          }
        }
        break;
    }
  }
}

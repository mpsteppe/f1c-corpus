int __thiscall sub_4B99F0(void *this)
{
  int v1; // edi
  int v3; // esi
  int v4; // esi
  int v5; // eax

  v1 = dword_75CBB0;
  v3 = 1;
  switch ( dword_75CBB0 )
  {
    case 1:
      v4 = 2;
      goto LABEL_8;
    case 2:
      v4 = 3;
      goto LABEL_8;
    case 3:
      v4 = 4;
      goto LABEL_8;
    case 4:
      v4 = 5;
      goto LABEL_8;
    case 5:
      v4 = 6;
      goto LABEL_8;
    case 6:
      v4 = 7;
LABEL_8:
      if ( *(_DWORD *)dword_7689CC == 8 )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 88))(dword_76BB24);
      sub_42F6C0(&dword_75CBA8, v4);
      if ( *(_DWORD *)dword_7689CC != 4 )
        goto LABEL_15;
      v5 = sub_4E5DA0(&unk_76BB28);
      if ( !v5 )
        goto LABEL_15;
      if ( v1 == 7 )
      {
        sub_4B9F00(this);
        sub_419110(byte_6292D0);
        return 0;
      }
      else
      {
        sub_4E4ED0(v5);
LABEL_15:
        v3 = 0;
LABEL_16:
        sub_419110(byte_6292D0);
        return v3;
      }
    default:
      goto LABEL_16;
  }
}

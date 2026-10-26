int __thiscall sub_42D8A0(_DWORD *this)
{
  int v1; // eax
  char v2; // bl

  *this = 5;
  sub_4F9F00(&unk_8AFE18);
  if ( sub_461CD0(&unk_7CD25C) == 1 )
  {
    v2 = 1;
LABEL_3:
    sub_4BA180(&dword_8AB6E4);
    sub_463CA0(&unk_7CD25C);
    sub_4BA150(&dword_8AB6E4);
    sub_4B3B40(&dword_7D2E50);
    sub_404460((int)dword_5EA2C0);
    sub_4D4580(&unk_8ACEE0);
    sub_455E50(&ppvOut);
    sub_42C690(&unk_5EC6D0);
    sub_4B3BA0(&dword_83EE60);
    sub_4643C0(&unk_7CD25C);
    sub_463CD0(&unk_7CD25C);
    sub_4BA6C0(&dword_8AB6E4);
    sub_4B3B40(&dword_83EE60);
    if ( v2 )
    {
      sub_4CFCC0(&unk_8ACEA0);
    }
    else
    {
      sub_40CA30((int)&dword_5EA510);
      sub_4CFCC0(&unk_8ACEA0);
      sub_4B40A0(&unk_8AB678);
      sub_49F070(&dword_7CE048);
    }
    sub_4F9F30(&unk_8AFE18);
    sub_4C8B70(&byte_8AC494);
    sub_4FA7E0(&unk_8AFE18);
    sub_4FCEE0(&unk_8AFEC0);
    sub_4A1830(&unk_7CE2A4);
    JUMPOUT(0x8D9596);
  }
  v1 = sub_4A0FD0(&unk_7CE24D);
  v2 = byte_7CE254;
  if ( v1 == 5 )
    goto LABEL_3;
  if ( v1 == 4 )
    return 0;
  if ( v1 != 6 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_11, 628) )
    sub_4D7AA0(&unk_8AD25C, aNextStateDWasN);
  return 1;
}

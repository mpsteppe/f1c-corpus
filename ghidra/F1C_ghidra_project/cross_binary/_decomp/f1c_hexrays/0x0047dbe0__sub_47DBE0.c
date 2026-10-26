// f1c  0x0047dbe0  size=273
int __thiscall sub_47DBE0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  double v4; // st7
  double v5; // st7
  int v6; // eax
  const char *v7; // [esp+4h] [ebp-5Ch]
  float v8; // [esp+Ch] [ebp-54h]
  _BYTE v9[80]; // [esp+10h] [ebp-50h] BYREF

  switch ( this[59] )
  {
    case 0x1E0:
      v1 = sub_4B9E30(&unk_8AB6EC);
      v2 = sub_487010(v1);
      sub_488B40(v2);
      return 0;
    case 0x1E1:
      v8 = sub_4B9CE0(&unk_8AB6EC);
      v4 = sub_4B9CB0(&unk_8AB6EC);
      sub_58815F(v9, "%1.3f", v8 - v4);
      sub_488B40(v9);
      return 0;
    case 0x1E2:
      v5 = sub_4B9C80(&unk_8AB6EC);
      sub_58815F(v9, "%1.3f", v5);
      sub_488B40(v9);
      return 0;
    case 0x1E3:
      if ( !dword_7C54E0 )
      {
        v7 = asc_5C7370;
        goto LABEL_9;
      }
      v6 = *(_DWORD *)(dword_7C54E0 + 16480);
      v7 = (const char *)(dword_7C54E0 + 17952);
      if ( v6 <= 0 )
      {
LABEL_9:
        sub_488B40(v7);
        return 0;
      }
      sub_58815F(v9, "(%d) %s", v6, v7);
      sub_488B40(v9);
      return 0;
    default:
      return 0;
  }
}

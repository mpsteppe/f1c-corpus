void __thiscall sub_53E6F0(int this, int a2)
{
  bool v3; // al
  int v4; // eax
  _BYTE v5[8]; // [esp+1Ch] [ebp-24h] BYREF
  _BYTE v6[8]; // [esp+28h] [ebp-18h] BYREF
  _BYTE v7[12]; // [esp+34h] [ebp-Ch] BYREF

  if ( (_BYTE)dword_757C1C
    && dword_91E084
    && *(_DWORD *)(dword_91E084 + 14820) != -1
    && this == dword_91E084
    && *(_DWORD *)(this + 14820) <= 1u )
  {
    sub_583170(this + 16, 0, 0);
    v3 = !byte_B6F118 && dword_B640C0 == 5;
    if ( byte_B73990 && v3 )
      sub_463BC0(dword_B6A328);
    if ( *(_DWORD *)dword_B72314 != 5 && !byte_B722CC )
    {
      v4 = (unsigned __int8)byte_B6F778;
      *(_DWORD *)(this + 21788) = (unsigned __int8)byte_B6F778;
      if ( byte_B6F790 )
      {
        if ( v4 == 1 )
          sub_583170(this + 16, 1, 0);
      }
    }
  }
  else
  {
    *(_DWORD *)(this + 21788) = 0;
  }
  sub_572690(*(float *)&a2);
  sub_583E20(this + 16);
  sub_4FB770(this + 14824, a2, COERCE_FLOAT(this + 16));
  sub_416F50();
  if ( (_BYTE)a2 )
    sub_52D7D0((_DWORD *)(this + 19272));
  sub_54FD90(this);
  sub_54FDB0(&unk_FADD40, this, v7, v6);
  sub_54FDF0(&unk_FADD40, this, v6, v5);
  if ( (_BYTE)a2 )
  {
    sub_54FE30(this, v7, v6);
    sub_57DCC0(v7, v6);
  }
  sub_428C90((char *)this, a2);
  sub_53E550((void *)this, 1, a2);
  *(_DWORD *)(this + 22564) = -8388609;
  sub_551110(&unk_FADD40);
  if ( flt_91BDF0 <= 0.0 )
    sub_57FB60(this + 16);
}

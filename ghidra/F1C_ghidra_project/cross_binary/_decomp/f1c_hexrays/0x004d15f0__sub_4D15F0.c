// f1c  0x004d15f0  size=122
int __thiscall sub_4D15F0(int *this)
{
  int result; // eax
  int v3; // esi
  int *v4; // edi
  _BYTE v5[32]; // [esp+8h] [ebp-40h] BYREF
  _BYTE v6[32]; // [esp+28h] [ebp-20h] BYREF

  result = sub_4D1450(this);
  if ( dword_8AFE88 )
  {
    v3 = 0;
    v4 = this + 160;
    do
    {
      sub_58815F(v5, "PDOOR%02d", v3);
      *(v4 - 52) = sub_5453A0(v5, 0);
      sub_58815F(v6, "PTENT%02d", v3);
      result = sub_5453A0(v6, 0);
      *v4 = result;
      ++v3;
      ++v4;
    }
    while ( v3 < 52 );
  }
  return result;
}

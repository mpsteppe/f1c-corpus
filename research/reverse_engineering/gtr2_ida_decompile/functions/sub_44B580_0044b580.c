char __thiscall sub_44B580(int this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  int i; // ebx
  char result; // al

  *(_BYTE *)(this + 146) = dword_B6F958;
  *(_BYTE *)(this + 147) = dword_B6F9A0;
  *(_BYTE *)(this + 148) = dword_B6FA54;
  v2 = this + 146;
  *(_BYTE *)(this + 149) = dword_B6FB50;
  *(_BYTE *)(this + 150) = dword_B6FAFC;
  *(_BYTE *)(this + 151) = dword_B6F9E8;
  v3 = this + 151;
  *(_BYTE *)(this + 152) = dword_B6F910;
  v4 = this + 152;
  *(_BYTE *)(this + 153) = dword_B6F910;
  *(_BYTE *)(this + 154) = dword_B6F97C;
  *(_BYTE *)(this + 155) = dword_B6F9C4;
  *(_BYTE *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = dword_B6FAFC != 0 ? 3 : 0;
  sub_5019D0(7, this + 153, 0);
  sub_5019D0(8, this + 154, 0);
  sub_5019D0(0, v2, 0);
  sub_5019D0(1, this + 147, 0);
  sub_5019D0(9, this + 155, 0);
  sub_5019D0(5, v3, 0);
  sub_5019D0(10, this + 156, 0);
  sub_5019D0(6, v4, 0);
  sub_5019D0(2, this + 148, 0);
  for ( i = 0; i < 11; ++i )
  {
    if ( !(unsigned __int8)sub_501D80(&byte_B6F530, i) )
      *(_BYTE *)(v2 + i) = 0;
  }
  if ( *(_BYTE *)(this + 148) || *(_BYTE *)(this + 154) )
    *(_BYTE *)(this + 147) = 2;
  result = *(_BYTE *)(this + 149);
  if ( result )
    *(_BYTE *)(this + 150) = 1;
  *(double *)(this + 176) = flt_B6FC04 * 0.95;
  return result;
}

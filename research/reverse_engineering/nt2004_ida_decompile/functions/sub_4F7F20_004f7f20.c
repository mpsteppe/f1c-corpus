void __thiscall sub_4F7F20(_DWORD *this, _DWORD *a2, float a3)
{
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // [esp+0h] [ebp-10h]

  if ( !a2 )
    return;
  if ( (dword_75CBAC & 1) == 0 && sub_4EED40(a2) )
  {
    v4 = (_DWORD *)dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    *(float *)&v8 = dbl_7DA9D0;
    sub_4D0D00(v4, 4, 43, 4, a2[6312], v8, 3);
    v4[2] = a2[5279];
    return;
  }
  if ( (unsigned __int8)sub_4F8410(a2) )
    return;
  if ( !*(_BYTE *)this )
    goto LABEL_17;
  if ( !sub_4DCA60(a2 + 5209) )
  {
    v5 = sub_4FA870(0);
    if ( v5 >= 0 && a2[5212] < dword_6310D8[6326 * v5] - 1 )
    {
      sub_4F7DC0(this + 1, a2[6312], a3, 0);
      goto LABEL_18;
    }
LABEL_17:
    sub_4F7DC0(this + 98, a2[6312], a3, 0);
    goto LABEL_18;
  }
  if ( this[97] <= this[194] )
    sub_4F7DC0(this + 98, a2[6312], a3, 1);
  else
    sub_4F7DC0(this + 1, a2[6312], a3, 1);
  sub_4DC9C0(a2 + 5209, 3);
LABEL_18:
  if ( a2 == (_DWORD *)(sub_42DBA0() ? dword_75AACC : 0) && (dword_75CBAC & 1) != 0 )
  {
    v6 = dword_75AACC;
    v7 = sub_4F82E0(a2);
    sub_4DCEB0((int *)(v6 + 20836), v7);
  }
}

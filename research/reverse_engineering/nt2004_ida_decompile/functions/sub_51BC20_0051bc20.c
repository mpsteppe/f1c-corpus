int __thiscall sub_51BC20(float *this, _DWORD *a2, char a3)
{
  int result; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-24h] BYREF
  double v7[3]; // [esp+1Ch] [ebp-18h] BYREF

  result = *((_DWORD *)this + 4125);
  *((_DWORD *)this + 4125) = a2;
  if ( a3 && dword_75CBA8 == 5 && !a2 )
  {
    if ( result )
    {
      sub_51C1E0(v6, v5);
      sub_51BE20(v6, v5);
      v7[0] = this[4386];
      v7[1] = this[4387];
      v7[2] = this[4388];
      result = sub_449EA0((int)&dbl_75E930, v7);
      dbl_75EADC = this[4677];
    }
  }
  else if ( !result && a2 )
  {
    sub_42C0F0(*(_DWORD **)this, 18);
    result = sub_42C120(*(_DWORD **)this);
    this[4693] = dbl_7608E4;
  }
  return result;
}

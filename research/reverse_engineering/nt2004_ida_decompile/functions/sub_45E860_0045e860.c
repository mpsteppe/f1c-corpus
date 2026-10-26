int __thiscall sub_45E860(_DWORD *this)
{
  int *v2; // eax
  int result; // eax
  int v4; // [esp-10h] [ebp-14h]

  this[1] = *(unsigned __int16 *)dword_7699BC;
  this[2] = *(unsigned __int16 *)dword_7699BC;
  *(_BYTE *)this = 0;
  v4 = dword_769C50;
  v2 = sub_45E390();
  result = sub_5B99E0(v2, 0, v4, 1, sub_45D440, 0);
  this[3] = result;
  return result;
}

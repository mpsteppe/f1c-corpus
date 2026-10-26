// f1c  0x004901a0  size=163
int __thiscall sub_4901A0(_DWORD *this)
{
  char *v2; // eax
  int result; // eax
  _BYTE v4[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  v4[0] = byte_5EA438[0];
  memset(&v4[1], 0, 0x3Cu);
  v5 = 0;
  v6 = 0;
  v2 = (char *)this[46];
  if ( !v2 )
    v2 = byte_5EA438;
  sub_587DD0(v4, v2, 63);
  v6 = 0;
  if ( !sub_588410(v4, &unk_5CC21C) )
    this[57] = 0;
  if ( !sub_588410(v4, aC_0) )
    this[57] = 1;
  result = sub_588410(v4, aR);
  if ( !result )
    this[57] = 2;
  return result;
}

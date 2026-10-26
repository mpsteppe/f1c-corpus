int __thiscall sub_686A7B(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v7; // eax
  bool v8; // zf

  if ( !a3 )
    return -2147467259;
  this[49] = a3;
  this[50] = a4;
  this[53] = 0;
  this[54] = 0;
  this[55] = 0;
  this[48] = a2;
  this[51] = a5;
  this[29] = sub_681A51(this, (int)&unk_73D0A0, 0, -1, 4);
  this[30] = sub_681A51(this, (int)"l", 785, -1, 4);
  this[31] = sub_681A51(this, (int)"c", 593, -1, 4);
  this[32] = sub_681A51(this, (int)&unk_739B24, 81, -1, 4);
  this[33] = sub_681A51(this, (int)&unk_739AD8, 98, -1, 4);
  this[34] = sub_681A51(this, (int)"r", 3, -1, 4);
  this[35] = sub_681A51(this, (int)"a", 6, -1, 4);
  this[36] = sub_681A51(this, (int)&unk_739ADC, 10, -1, 4);
  this[37] = sub_681A51(this, (int)"s", 721, -1, 4);
  this[38] = sub_681A51(this, (int)&unk_739B00, 4099, -1, 4);
  this[39] = sub_681A51(this, (int)"c", 8785, -1, 4);
  this[40] = sub_681A51(this, (int)&unk_739ADC, 16394, -1, 4);
  this[41] = sub_681A51(this, (int)&unk_73D09C, 49162, -1, 4);
  this[42] = sub_681A51(this, (int)&unk_73D098, 65602, 0, 4);
  this[43] = sub_681A51(this, (int)&unk_73D094, 131075, -1, 4);
  this[44] = sub_681A51(this, (int)&unk_739B00, 262673, -1, 4);
  this[45] = sub_681A51(this, (int)&unk_73D090, 8290, -1, 4);
  v7 = sub_681A51(this, (int)&unk_73D08C, 262242, -1, 4);
  v8 = this[1] == 18;
  this[46] = v7;
  if ( !v8 )
    return -2147024882;
  memset(this + 10, 0, 0x4Cu);
  result = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  if ( result >= 0 )
  {
    result = sub_682468((void **)this, 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

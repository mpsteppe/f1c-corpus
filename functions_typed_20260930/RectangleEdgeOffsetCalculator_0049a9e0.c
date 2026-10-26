int __thiscall sub_49A9E0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int result; // eax

  v5 = this[3];
  this[5] = a2 - v5;
  v6 = this[1];
  this[6] = a3 - v6;
  v7 = a4 - v5;
  result = a5 - v6;
  this[7] = v7;
  this[8] = a5 - v6;
  return result;
}


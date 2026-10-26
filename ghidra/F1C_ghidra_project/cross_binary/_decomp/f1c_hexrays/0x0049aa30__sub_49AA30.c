// f1c  0x0049aa30  size=51
int __thiscall sub_49AA30(_DWORD *this, int a2, int a3)
{
  int v3; // esi
  int v4; // edx
  int v5; // edi
  int v6; // edx
  int result; // eax

  v3 = this[3];
  v4 = a3 - this[1];
  this[1] = a3;
  v5 = v4 + this[2];
  v6 = this[4];
  result = a2 - v3;
  this[2] = v5;
  this[3] = a2;
  this[4] = a2 - v3 + v6;
  return result;
}

// f1c  0x0041f1e0  size=56
bool __thiscall sub_41F1E0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = sub_4C2850(&unk_7D2DB0);
  v3 = sub_4C11D0(v2);
  return this && v3 >= 2 && this[v3 + 5] == 1 && this[v3 + 4] == 1;
}

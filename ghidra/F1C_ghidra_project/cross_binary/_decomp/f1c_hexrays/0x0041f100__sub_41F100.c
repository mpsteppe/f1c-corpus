// f1c  0x0041f100  size=71
bool __thiscall sub_41F100(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = sub_4C2850(&unk_7D2DB0);
  v3 = sub_4C11D0(v2);
  return this && v3 >= 3 && this[v3 + 54] == 10 && this[v3 + 53] == 10 && this[v3 + 52] == 10;
}

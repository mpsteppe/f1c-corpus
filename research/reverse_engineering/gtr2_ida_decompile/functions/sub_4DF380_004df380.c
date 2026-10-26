unsigned __int64 __thiscall sub_4DF380(_DWORD *this)
{
  int v1; // eax
  int v3; // ecx
  unsigned __int64 result; // rax
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]

  v1 = dword_B6A350;
  v3 = dword_B6A354;
  this[24] = dword_B6A3D8;
  v5 = *(float *)&v1;
  v6 = *(float *)&v3;
  this[25] = dword_B6A3DC;
  this[26] = dword_B6A3E0;
  this[27] = sub_45DE90(dword_B6A328);
  this[22] = (unsigned __int64)(v5 * 400.0 + 10.0);
  result = (unsigned __int64)(v6 * 300.0);
  this[23] = result;
  return result;
}

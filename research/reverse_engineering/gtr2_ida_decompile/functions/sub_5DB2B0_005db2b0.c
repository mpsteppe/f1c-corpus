int __thiscall sub_5DB2B0(_DWORD *this, int a2, int a3, int a4, float a5, float a6, float a7)
{
  int v8; // edi
  int result; // eax
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+4h] [ebp-10h]
  float v12; // [esp+8h] [ebp-Ch]

  v8 = (int)(this + 18);
  v12 = fmod(a7, 6.283185482025146);
  v11 = fmod(a6, 6.283185482025146);
  v10 = fmod(a5, 6.283185482025146);
  sub_5D73C0((int)(this + 18), v10, v11, v12);
  sub_5D7330(v8, *(float *)&a2, *(float *)&a3, *(float *)&a4);
  result = *this | 0x40;
  *this = result;
  return result;
}

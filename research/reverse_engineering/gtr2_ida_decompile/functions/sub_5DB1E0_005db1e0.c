int __thiscall sub_5DB1E0(_DWORD *this, float a2, float a3, float a4)
{
  int result; // eax
  float v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-8h]

  v8 = fmod(a4, 6.283185482025146);
  v7 = fmod(a3, 6.283185482025146);
  v6 = fmod(a2, 6.283185482025146);
  result = sub_5D73C0((int)(this + 18), v6, v7, v8);
  *this |= 0x40u;
  return result;
}

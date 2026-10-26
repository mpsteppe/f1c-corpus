int __thiscall sub_504B70(_DWORD *this)
{
  int v2; // ebx
  int v3; // eax
  int v5; // [esp-8h] [ebp-1Ch]
  int v6; // [esp+0h] [ebp-14h]

  this[12] = 1176256512;
  *(float *)&v6 = sub_4B2DC0();
  sub_4B6220(this + 4, v6);
  sub_4B6230(this + 4, dword_7E8CDC);
  v2 = (__int64)(1.0 / sub_501870() * (double)(this[13] + this[15] / 2));
  v5 = (__int64)(1.0 / sub_501880() * (double)(int)(this[14] - (__int64)((double)(int)this[16] * -0.675)));
  v3 = sub_4B2DE0();
  sub_504DC0(v3, v2, v5, 1.0, 1.0);
  return sub_4B6240(this + 4, dword_7E8CDC);
}

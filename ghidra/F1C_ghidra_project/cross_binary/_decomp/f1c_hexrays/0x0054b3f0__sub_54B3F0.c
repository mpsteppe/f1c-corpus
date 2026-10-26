// f1c  0x0054b3f0  size=43
void __thiscall sub_54B3F0(int this, float a2, float a3, float a4)
{
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  *(float *)&v6 = a4 + *(float *)(this + 40);
  *(float *)&v5 = a3 + *(float *)(this + 36);
  *(float *)&v4 = a2 + *(float *)(this + 32);
  sub_54B3B0((_DWORD *)this, v4, v5, v6);
}

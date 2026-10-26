int __thiscall sub_4CFF40(int this, int a2)
{
  int v2; // eax
  int v3; // ecx
  int result; // eax
  int v5; // [esp+0h] [ebp-8h]

  v2 = *(unsigned __int16 *)(this + 25);
  v5 = v2 << 20;
  v3 = (v2 & 0xF000) + (*(unsigned __int8 *)(this + 27) << 16);
  result = a2;
  *(_DWORD *)(a2 + 4) = 0;
  *(float *)a2 = (double)v5 * 0.000000029802322;
  *(float *)(a2 + 8) = (double)(v3 << 8) * 0.000000029802322;
  return result;
}

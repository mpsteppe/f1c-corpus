int __thiscall sub_521650(int this, int a2)
{
  int result; // eax

  sub_630FE0(this, a2 + 21808, 63);
  *(_BYTE *)(this + 63) = 0;
  sub_630FE0(this + 64, a2 + 22072, 7);
  *(_BYTE *)(this + 71) = 0;
  sub_630FE0(this + 72, a2 + 21872, 63);
  *(_BYTE *)(this + 135) = 0;
  sub_630FE0(this + 136, 108 * *(_DWORD *)(a2 + 21788) + a2 + 21568, 63);
  *(_BYTE *)(this + 199) = 0;
  *(_DWORD *)(this + 200) = dword_B70618[0];
  *(float *)(this + 204) = sub_552900(&unk_FADD40);
  *(_DWORD *)(this + 208) = dword_B72338;
  *(_DWORD *)(this + 212) = (unsigned __int8)byte_B660DA;
  *(_DWORD *)(this + 216) = (unsigned __int8)byte_B660D9;
  *(_DWORD *)(this + 220) = (unsigned __int8)byte_B660D4;
  *(_DWORD *)(this + 224) = (unsigned __int8)byte_B660D5;
  *(_DWORD *)(this + 228) = (unsigned __int8)byte_B660D2;
  result = (unsigned __int8)byte_B660D3;
  *(_DWORD *)(this + 232) = (unsigned __int8)byte_B660D3;
  return result;
}

int __thiscall sub_4BE700(int this)
{
  int result; // eax

  *(_BYTE *)(this + 832) = 1;
  *(_BYTE *)(this + 833) = 1;
  result = 0;
  *(_BYTE *)(this + 834) = 0;
  *(_DWORD *)(this + 836) = 1065353216;
  *(_DWORD *)(this + 840) = 1065353216;
  *(_DWORD *)(this + 844) = 1142292480;
  *(_DWORD *)(this + 848) = 1092616192;
  *(_DWORD *)(this + 852) = 0;
  *(_DWORD *)(this + 856) = 0;
  *(_DWORD *)(this + 860) = 10;
  *(_DWORD *)(this + 864) = 5;
  return result;
}

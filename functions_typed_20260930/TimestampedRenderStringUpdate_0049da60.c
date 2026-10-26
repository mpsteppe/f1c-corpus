int __thiscall sub_49DA60(_DWORD *this)
{
  int v1; // edi
  int v3; // ebp
  int v4; // ebx
  int result; // eax
  int v6; // edi
  _BYTE v7[64]; // [esp+10h] [ebp-40h] BYREF

  v1 = dword_5CCBB8;
  v3 = dword_7CE238;
  v4 = dword_5CCBC0;
  DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
  result = this[2];
  if ( result )
  {
    v6 = dword_5CCBBC + v1;
    sub_49C8F0((int)v7, 64);
    StringFormatAndRender(v7, v4, v6, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49C960((int)v7, 64);
    return StringFormatAndRender(v7, v3, v6, this[2], *(_DWORD *)(this[5] + 84), 0);
  }
  return result;
}


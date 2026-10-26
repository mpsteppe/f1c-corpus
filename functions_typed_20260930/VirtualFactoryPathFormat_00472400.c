int __thiscall VirtualFactoryPathFormat(_DWORD *this)
{
  _DWORD *v2; // eax
  char v4[32]; // [esp+4h] [ebp-20h] BYREF

  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 19);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  StringFormatWithBufferOverflowCheck(v4, (int)"%d", dword_7D09D8);
  EditBufferStringUpdate(this, v4);
  return 0;
}


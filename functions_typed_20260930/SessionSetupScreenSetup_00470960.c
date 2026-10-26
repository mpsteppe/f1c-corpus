int __thiscall SessionSetupScreenSetup(_DWORD *this)
{
  char *v2; // eax
  _DWORD *v3; // eax
  char v5[32]; // [esp+4h] [ebp-20h] BYREF

  this[201] = dword_7D0410;
  this[200] = &dword_7CEAA4;
  v2 = UIListIndexedAccessor(this, dword_7CEAA4);
  StringFormatWithBufferOverflowCheck(v5, (int)v2);
  EditBufferStringUpdate(this, v5);
  v3 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 19);
  if ( v3 )
    ObjectNameComparison(v3, (int)this);
  return 0;
}


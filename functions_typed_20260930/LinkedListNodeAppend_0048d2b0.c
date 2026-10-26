char __thiscall sub_48D2B0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // edx

  v3 = (_DWORD *)OperatorNewNhMallocWrapper(8);
  if ( v3 )
    v4 = SimpleVTableNullInit(v3);
  else
    v4 = 0;
  IntSetterAt4(v4, a2);
  if ( !v4 )
    return 0;
  v5 = OperatorNewNhMallocWrapper(16);
  if ( v5 )
  {
    *(_DWORD *)v5 = v4;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_BYTE *)(v5 + 12) = 1;
  }
  else
  {
    v5 = 0;
  }
  if ( this[199] )
  {
    *(_DWORD *)(this[200] + 4) = v5;
    *(_DWORD *)(v5 + 8) = this[200];
  }
  else
  {
    this[199] = v5;
    this[201] = v5;
  }
  v6 = this[202] + 1;
  this[200] = v5;
  this[202] = v6;
  LinkedListSizeCalcWithMaxTracking(this);
  (*(void (__stdcall **)(int))(*this + 44))(1);
  return 1;
}


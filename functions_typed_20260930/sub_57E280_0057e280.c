int __thiscall sub_57E280(void *this, float a2)
{
  double v3; // st7
  __int16 v4; // fps
  bool v5; // c0
  char v6; // c2
  bool v7; // c3
  int result; // eax
  bool v9; // zf
  void *v10; // eax
  int v11; // ebp
  int i; // edi
  float v13; // eax
  int v14; // eax
  void *v15; // esi
  _DWORD v16[8]; // [esp+8h] [ebp-2Ch] BYREF
  int v17; // [esp+30h] [ebp-4h]
  bool v18; // [esp+38h] [ebp+4h]

  v3 = *((float *)this + 682) - a2;
  *((float *)this + 682) = v3;
  v5 = v3 < 0.0;
  v6 = 0;
  v7 = v3 == 0.0;
  result = v4 & 0x4100;
  if ( (v4 & 0x4100) != 0 )
  {
    *((_DWORD *)this + 682) = 1040187392;
    v9 = MutexProtectedPointerReadRelease(this) == 4;
    v10 = (void *)*((_DWORD *)this + 694);
    v18 = !v9;
    if ( v10 )
      WaitForSingleObject(v10, *((_DWORD *)this + 695));
    v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
    for ( i = 0; i < v11; ++i )
    {
      ObjectInitWithVTableFieldSet(v16, 0, 0, 0);
      v13 = *(float *)this;
      v17 = 0;
      if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD *))(LODWORD(v13) + 172))(this, i, v16)
        && (!v18 || sub_587220(v16) == 2) )
      {
        v14 = ReadFieldAtOffset0x14(v16);
        sub_585870(v14, 0);
      }
      v17 = -1;
      VTablePointerInit(v16);
    }
    result = MutexCallbackDispatch(this);
    v15 = (void *)*((_DWORD *)this + 694);
    if ( v15 )
      return ReleaseMutex(v15);
  }
  return result;
}


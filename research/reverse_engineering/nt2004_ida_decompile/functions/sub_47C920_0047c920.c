int __thiscall sub_47C920(int this)
{
  int v2; // eax
  int v3; // esi
  const char *v4; // eax
  int v5; // esi
  char v7; // [esp+1Fh] [ebp-5Dh] BYREF
  _BYTE v8[92]; // [esp+20h] [ebp-5Ch] BYREF

  v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 10);
  v3 = v2;
  if ( v2 )
  {
    if ( sub_49FB50(v2) >= 0 )
    {
      v4 = (const char *)sub_49FB60(v3);
      if ( v4 )
      {
        v5 = atol(v4);
        sub_462C80(v8);
        if ( (unsigned __int8)((int (__thiscall *)(_DWORD *, int, _BYTE *, _DWORD, _DWORD, char *))loc_463800)(
                                dword_764D70,
                                v5,
                                v8,
                                0,
                                0,
                                &v7)
          && sub_462D10(v8, 2)
          && !strlen(&byte_7654A8) )
        {
          sub_4AD720(aMultiClientPas, 1);
          nullsub_6(v8);
          return -1;
        }
        if ( (unsigned __int8)((int (__thiscall *)(_DWORD *, int, char *))loc_464600)(dword_764D70, v5, &byte_7654A8) )
          *(_DWORD *)(this + 268) = 1082130432;
        nullsub_6(v8);
      }
    }
  }
  return -1;
}

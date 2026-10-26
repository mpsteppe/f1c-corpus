int __thiscall sub_46DD30(int this)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  char v7; // [esp+17h] [ebp-81h] BYREF
  _BYTE v8[128]; // [esp+18h] [ebp-80h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 64) + 28))(*(_DWORD *)(this + 64), 34);
  v3 = v2;
  if ( v2 )
  {
    if ( sub_489940(v2) >= 0 )
    {
      v4 = sub_489950(v3);
      if ( v4 )
      {
        v5 = sub_587ECE(v4);
        sub_461550(v8);
        if ( (unsigned __int8)((int (__thiscall *)(_DWORD *, int, _BYTE *, _DWORD, _DWORD, char *))loc_462010)(
                                dword_7CD25C,
                                v5,
                                v8,
                                0,
                                0,
                                &v7)
          && sub_4615F0(v8, 2)
          && !strlen(&byte_7CD850) )
        {
          sub_497940(aMultiClientPas, -1);
          sub_4988D0(aClientPassword);
        }
        else if ( sub_462C00(dword_7CD25C, v5, (int)&byte_7CD850) )
        {
          *(_DWORD *)(this + 228) = 1082130432;
        }
        nullsub_3(v8);
      }
    }
  }
  return -1;
}

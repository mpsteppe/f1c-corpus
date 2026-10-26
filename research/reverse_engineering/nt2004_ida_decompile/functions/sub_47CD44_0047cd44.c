int __usercall sub_47CD44@<eax>(int a1@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // esi
  const char *v4; // eax
  int v5; // esi
  int v7; // [esp+8h] [ebp-78h] BYREF
  _BYTE v8[112]; // [esp+Ch] [ebp-74h] BYREF
  int v9; // [esp+7Ch] [ebp-4h]

  v9 = (unsigned __int16)__DS__;
  v2 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 7, a2);
  v3 = v2;
  if ( v2 )
  {
    if ( sub_49FB30(v2) )
    {
      v4 = (const char *)sub_49FB60(v3);
      if ( v4 )
      {
        v5 = atol(v4);
        sub_462BC0(v8);
        if ( sub_463D40(dword_764D70, v5, v8, &v7) )
          sub_464350(dword_764D70, v7);
        nullsub_6(v8);
      }
    }
  }
  return 0;
}
